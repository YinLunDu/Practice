#include <iostream>
#include <string>
#define N 5

using namespace std;

void p(char c[], int x, int M)
{
    int i,j,success;
    char c2[100],temp;
    for (i=x;i<=N-1;i++) {
        for (j=0;j<=N-1;j++) c2[j]=c[j];
        temp=c[x];
        c[x]=c[i];
        c[i]=temp;

        if (x==M-1) {
            success=1;
            for (j=1;j<=M-1;j++)
                if (c[j]<c[j-1])
                    success=0;
            if (success==1) {
                for (j=0;j<=M-1;j++) cout << c[j] << " ";
                cout << "\n";
            }
        }
        p(c, x+1, M);
        for (j=0;j<=N-1;j++) c[j]=c2[j];
    }
}

int main()
{
    char c[5]={'a','b','c','d','e'};
    int M;
    cin >> M;
    p(c,0,M);
    return 0;
}
