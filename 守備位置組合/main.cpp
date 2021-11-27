/*
題目: 守備位置組合

故事:
郭哥非常的健壯,其中有一個原因是因為他非常癡迷於量球,每個禮拜不找人練習個三四天他就會渾身不
舒服。最近他突發奇想,想要找人來組一個壘球隊,只不過找來的人都是小廢廢,只能守備他們指定的位置
因此想請你幫忙調整隊伍。

說明:
總共有n個人和m個需要的位置,n一定大等於m。
由於每個人只能守備一個位置,且每個人都有他可以與不可以的位置,接下告知每個人能守的位置,
0代表不可以,1代表可以守備該位置。
找出總共有幾種狀況是所有位置都必須由一人守備。

輸入說明:
第一行輸入m代表接下有n行輸入,每一行由長度為m的0與1組的數字。

輸出說明:
總共有幾種守備組合

範例輸入:
4 3
001
101
010
111

範例輸出:
5
*/
#include <iostream>

using namespace std;

bool table[100][100];
int n,m;
int sum;

void check(int x, int now[])
{
    bool success;
    int i,j;
    if (x>m) {
        sum++;
    } else {
        for (i=1;i<=n;i++) {
            if (table[i][x]==true) {
                success=true;
                for (j=1;j<=x-1;j++)
                    if (now[j]==i) {
                        success=false;
                        break;
                    }
                if (success==true) {
                    int now2[100];
                    for (j=1;j<=x-1;j++) now2[j]=now[j];
                    now2[x]=i;
                    check(x+1, now2);
                }
            }
        }
    }
}

int main()
{
    int i,j;
    int temp[100]={0};
    string input;
    cin >> n >> m;
    for (i=1;i<=n;i++) {
        cin >> input;
        for (j=1;j<=m;j++)
            table[i][j]=input[j-1]-'0';
    }

    sum=0;
    check(1, temp);

    cout << sum;
    return 0;
}
