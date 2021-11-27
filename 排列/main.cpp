#include <iostream>
#include <string>
#define N 4

using namespace std;

void p(char c[], int x)
{
    int i,j;
    char c2[100],temp;
    for (i=x;i<=N-1;i++) {
        for (j=0;j<=N-1;j++) c2[j]=c[j];
        temp=c[x];
        c[x]=c[i];
        c[i]=temp;
        if (x==N-1) {
            for (j=0;j<=N-1;j++) cout << c[j] << " ";
            cout << "\n";
        }
        p(c, x+1);
        for (j=0;j<=N-1;j++) c[j]=c2[j];
    }
}

int main()
{
    char c[4]={'a','b','c','d'};
    p(c,0);
    return 0;
}
