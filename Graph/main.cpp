#include <iostream>

using namespace std;

int graph[8][3]={
    {-1},
    { 2, 3},
    { 3},
    { 4},
    {-1},
    { 7},
    {-1},
    { 6}
};
int num[8]={0,2,1,1,0,1,0,1};
int ans[20],index;

void fun(int n)
{
    bool success=true;
    int i;
    for (i=1;i<=index-1;i++)
        if (ans[i]==n) {
            success=false;
            break;
        }
    if (success==true) {
        ans[index]=n;
        index++;
    }
    if (graph[n][0]!=-1)
        for (i=0;i<=num[n]-1;i++)
            fun(graph[n][i]);
}

int main()
{
    int n,i;
    cin >> n;
    index=1;
    fun(n);
    for (i=1;i<=index-1;i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
