/*
6
1 2
2 3
1 3
3 4
5 7
6 7
*/
#include <iostream>
#define N 7

using namespace std;
bool check[N+1];
int graph[N+1][N+1];

void fun(int x)
{
    int i;
    check[x]=true;
    for (i=1;i<=N;i++) {
        if (graph[x][i]==1 && check[i]==false)
            fun(i);
    }
}

int main()
{

    int i,j,x,a,b,group;
    for (i=1;i<=N;i++) {
        check[i]=false;
        for (j=1;j<=N;j++)
            graph[i][j]=0;
    }
    cin >> x;
    for (i=1;i<=x;i++) {
        cin >> a >> b;
        graph[a][b]=1;
        graph[b][a]=1;
    }

    group=0;
    for (i=1;i<=N;i++)
        if (check[i]==false) {
            group++;
            fun(i);
        }
    cout << group;
    return 0;
}
