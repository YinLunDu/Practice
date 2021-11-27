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

struct item
{
    int a;
    int b;
    int s;
}q[1000];

int head=0,rear=0;

bool inside(int x, int y)
{
    if (0<=x && x<=A-1 && 0<=y && y<=B-1)
        return true;
    else
        return false;
}

void pop(int *x, int *y, int *step)
{
    *x=q[head].a;
    *y=q[head].b;
    *step=q[head].s;
    head++;
}

void push(int x, int y, int step)
{
    q[rear].a=x;
    q[rear].b=y;
    q[rear].s=step;
    rear++;
}

bool empty_or_not()
{
    if (head==rear)
        return true;
    else
        return false;
}

int main()
{
    int i,j,x,y;
    struct item temp;
    //cout << "Beginning:";
    //cin >> x >> y;
    x=1;y=1;

    push(x, y, 1);
    while (empty_or_not()==false) {
        pop(&temp.a,&temp.b,&temp.s);
        m[temp.a][temp.b]=temp.s;
        if (inside(temp.a+1,temp.b+0)) if (m[temp.a+1][temp.b+0]==0) push(temp.a+1, temp.b+0, temp.s+1);
        if (inside(temp.a+0,temp.b+1)) if (m[temp.a+0][temp.b+1]==0) push(temp.a+0, temp.b+1, temp.s+1);
        if (inside(temp.a-1,temp.b-0)) if (m[temp.a-1][temp.b-0]==0) push(temp.a-1, temp.b-0, temp.s+1);
        if (inside(temp.a-0,temp.b-1)) if (m[temp.a-0][temp.b-1]==0) push(temp.a-0, temp.b-1, temp.s+1);
    }

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
