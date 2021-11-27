#include <iostream>
#include <cstdio>
#define A 10
#define B 10

using namespace std;

int m[10][10]={
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1, 0, 0,-1, 0, 0, 0, 0, 0,-1},
    {-1,-1, 0, 0, 0, 0, 0, 0, 0,-1},
    {-1, 0, 0, 0,-1, 0,-1, 0, 0,-1},
    {-1, 0, 0,-1, 0, 0, 0, 0, 0,-1},
    {-1, 0,-1,-1, 0, 0,-1, 0, 0,-1},
    {-1, 0, 0,-1, 0,-1, 0, 0, 0,-1},
    {-1, 0, 0,-1, 0, 0,-1,-1, 0,-1},
    {-1, 0, 0, 0, 0, 0,-1, 0, 0,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
};

bool inside(int x, int y)
{
    if (0<=x && x<=A-1 && 0<=y && y<=B-1)
        return true;
    else
        return false;
}

void maze(int i, int j, int step)
{
    m[i][j]=step;

    step++;
    if (inside(i+1, j+0)) if (m[i+1][j+0]!=-1&&((m[i+1][j+0]==0)||m[i+1][j+0]>step)) maze(i+1,j+0,step);
    if (inside(i+0, j+1)) if (m[i+0][j+1]!=-1&&((m[i+0][j+1]==0)||m[i+0][j+1]>step)) maze(i+0,j+1,step);
    if (inside(i-1, j-0)) if (m[i-1][j-0]!=-1&&((m[i-1][j-0]==0)||m[i-1][j-0]>step)) maze(i-1,j-0,step);
    if (inside(i-0, j-1)) if (m[i-0][j-1]!=-1&&((m[i-0][j-1]==0)||m[i-0][j-1]>step)) maze(i-0,j-1,step);
}

int main()
{
    int i,j,x,y,a,b;

    //cout << "Beginning¡G";
    //cin >> x >> y;
    x=1;y=1;
    maze(x,y,1);

    for (i=0;i<=B-1;i++) {
        for (j=0;j<=A-1;j++) {
            if (m[i][j]==-1)
                printf(" * ");
            else
                printf("%2d ",m[i][j]);
        }
        printf("\n");
    }
    return 0;
}
