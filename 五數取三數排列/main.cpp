#include <iostream>
#include <algorithm>

using namespace std;

int num[5], amount;

void fun(int x, int now[])
{
    bool success;
    int i,j;
    if (x==3) {
        amount++;
        for (i=0;i<=2;i++)
            cout << now[i] << " ";
        cout << "\n";
    } else {
        for (i=0;i<=4;i++) {
            success=true;
            for (j=0;j<=x-1;j++)
                if (now[j]==num[i]) {
                    success=false;
                    break;
                }
            if (success==true) {
                int now2[5];
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
    cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];
    sort(num, num+5);
    amount=0;
    fun(0, num);
    cout << amount;
    return 0;
}
