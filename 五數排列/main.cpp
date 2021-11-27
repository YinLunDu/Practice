/*  N數取K數排列  */
#include <iostream>
#include <algorithm>
#define N 5
#define K 3

using namespace std;

int num[N]={1,2,3,4,5}, amount;

void fun(int x, int now[])
{
    bool success;
    int i,j;
    if (x==K) {
        amount++;
        for (i=0;i<=K-1;i++)
            cout << now[i] << " ";
        cout << "\n";
    } else {
        for (i=0;i<=N-1;i++) {
            success=true;
            for (j=0;j<=x-1;j++)
                if (now[j]==num[i]) {
                    success=false;
                    break;
                }
            if (success==true) {
                int now2[N];
                for (j=0;j<=x-1;j++)
                    now2[j]=now[j];
                now2[x]=num[i];
                fun(x+1, now2);
            }
        }
    }
}

int main()
{
    sort(num, num+N);
    amount=0;
    fun(0, num);
    cout << amount;
    return 0;
}
