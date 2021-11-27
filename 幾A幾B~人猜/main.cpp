#include <iostream>
#define N 123

using namespace std;

int main()
{
    int i,j,num,A,B,times;
    int ans[4],guess[4];
    times=0;

    while (cin >> num) {
        A=0; B=0;
        ans[1]=N/100;
        ans[2]=(N%100)/10;
        ans[3]=N%10;
        guess[1]=num/100;
        guess[2]=(num%100)/10;
        guess[3]=num%10;

        for (i=1;i<=3;i++) {
            if (ans[i]==guess[i]) {
                ans[i]=-1;
                guess[i]=-2;
                A++;
            }
        }
        for (i=1;i<=3;i++) {
            for (j=1;j<=3;j++) {
                if (ans[i]==guess[j]&&i!=j) {
                    ans[i]=-1;
                    guess[j]=-2;
                    B++;
                }
            }
        }
        cout << A << "A" << B << "B\n";
        times++;
        if (A==3) {
            cout << "Total: " << times << " times!";
            break;
        }
    }
    return 0;
}
