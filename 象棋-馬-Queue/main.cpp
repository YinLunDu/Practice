#include <iostream>
#include <cstdio>
#include <queue>
#define A 10
#define B 10

using namespace std;

typedef struct
{
    int a;
    int b;
    int s;
}obj;

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
queue <obj> q;

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
    obj temp;
    m[i][j]=step;

    step++;
    x=i+2;y=j+1;
    if (inside(x,y))
        if (m[x-1][y-1]!=-1&&m[x][y]==0) {
            temp.a=x; temp.b=y; temp.s=step;
            q.push(temp);
        }

    x=i+1;y=j+2;
    if (inside(x,y))
        if (m[x-1][y-1]!=-1&&m[x][y]==0) {
            temp.a=x; temp.b=y; temp.s=step;
            q.push(temp);
        }

    x=i-1;y=j-2;
    if (inside(x,y))
        if (m[x+1][y+1]!=-1&&m[x][y]==0) {
            temp.a=x; temp.b=y; temp.s=step;
            q.push(temp);
        }

    x=i-2;y=j-1;
    if (inside(x,y))
        if (m[x+1][y+1]!=-1&&m[x][y]==0) {
            temp.a=x; temp.b=y; temp.s=step;
            q.push(temp);
        }

    x=i+2;y=j-1;
    if (inside(x,y))
        if (m[x-1][y+1]!=-1&&m[x][y]==0) {
            temp.a=x; temp.b=y; temp.s=step;
            q.push(temp);
        }

    x=i+1;y=j-2;
    if (inside(x,y))
        if (m[x-1][y+1]!=-1&&m[x][y]==0) {
            temp.a=x; temp.b=y; temp.s=step;
            q.push(temp);
        }

    x=i-1;y=j+2;
    if (inside(x,y))
        if (m[x+1][y-1]!=-1&&m[x][y]==0) {
            temp.a=x; temp.b=y; temp.s=step;
            q.push(temp);
        }

    x=i-2;y=j+1;
    if (inside(x,y))
        if (m[x+1][y-1]!=-1&&m[x][y]==0) {
            temp.a=x; temp.b=y; temp.s=step;
            q.push(temp);
        }

}

int main()
{
    int x,y,i,j;
    obj temp;

    cout << "Beginning:";
    cin >> x >> y;

    temp.a=x; temp.b=y; temp.s=1;
    q.push(temp);
    while (q.empty()==false) {
        temp=q.front();
        q.pop();
        horse(temp.a,temp.b,temp.s);
    }

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
