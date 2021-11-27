#include <iostream>
#include <cstdio>
#define A 10
#define B 10

using namespace std;

int m[10][10]={
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    {-1,-1, 0, 0, 0, 0, 0, 0, 0,-1},
    {-1, 0, 0, 0, 0, 0,-1, 0, 0,-1},
    {-1, 0, 0,-1, 0, 0, 0, 0, 0,-1},
    {-1, 0,-1,-1, 0, 0,-1, 0, 0,-1},
    {-1, 0, 0,-1, 0,-1, 0, 0, 0,-1},
    {-1, 0, 0,-1, 0, 0,-1,-1, 0,-1},
    {-1, 0, 0, 0, 0, 0,-1, 0, 0,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
};

bool inside(int i, int j)
{
    if (i>=0&&i<=A-1&&j>=0&&j<=B-1)
        return true;
    else
        return false;
}

void horse(int i, int j, int step)
{
    int x,y;
    if (m[i][j]==0||m[i][j]>step) {
        m[i][j]=step;

        step++;
        x=i+2;y=j+1;
        if (inside(x,y))
            if (m[x-1][y-1]!=-1&&m[x][y]!=-1&&((m[x][y]==0)||m[x][y]>step))
                horse(x,y,step);

        x=i+1;y=j+2;
        if (inside(x,y))
            if (m[x-1][y-1]!=-1&&m[x][y]!=-1&&((m[x][y]==0)||m[x][y]>step))
                horse(x,y,step);

        x=i-1;y=j-2;
        if (inside(x,y))
            if (m[x+1][y+1]!=-1&&m[x][y]!=-1&&((m[x][y]==0)||m[x][y]>step))
                horse(x,y,step);

        x=i-2;y=j-1;
        if (inside(x,y))
            if (m[x+1][y+1]!=-1&&m[x][y]!=-1&&((m[x][y]==0)||m[x][y]>step))
                horse(x,y,step);

        x=i+2;y=j-1;
        if (inside(x,y))
            if (m[x-1][y+1]!=-1&&m[x][y]!=-1&&((m[x][y]==0)||m[x][y]>step))
                horse(x,y,step);

        x=i+1;y=j-2;
        if (inside(x,y))
            if (m[x-1][y+1]!=-1&&m[x][y]!=-1&&((m[x][y]==0)||m[x][y]>step))
                horse(x,y,step);

        x=i-1;y=j+2;
        if (inside(x,y))
            if (m[x+1][y-1]!=-1&&m[x][y]!=-1&&((m[x][y]==0)||m[x][y]>step))
                horse(x,y,step);

        x=i-2;y=j+1;
        if (inside(x,y))
            if (m[x+1][y-1]!=-1&&m[x][y]!=-1&&((m[x][y]==0)||m[x][y]>step))
                horse(x,y,step);

    }
}

int main()
{
    int x,y,i,j;
    cout << "°_©lÂI¡G";
    cin >> x >> y;

    horse(x,y,1);


    for (i=0;i<=B-1;i++) {
        for (j=0;j<=A-1;j++) {
            if (m[i][j]==-1)
                printf(" * ");
            else
                printf("%2d ",m[i][j]);
        }
        cout << "\n";
    }
    return 0;
}
