#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int column[6][5],row[6][5],mesh[5][5];

int main()
{
    srand(time(NULL));
    int i,j,a,b;
    bool m[5][5];

    for (i=0;i<=4;i++)
        for (j=0;j<=4;j++)
            m[i][j]=false;

    for (i=0;i<=5;i++)
        for (j=1;j<=4;j++) {
            column[i][j]=rand()%9+1;
            row[i][j]=rand()%9+1;
        }

    mesh[0][0]=0;
    for (i=1;i<=4;i++) mesh[0][i]=mesh[0][i-1]+row[0][i];
    for (i=1;i<=4;i++) {
        mesh[i][0]=mesh[i-1][0]+column[0][i];
        for (j=1;j<=4;j++) {
            a=mesh[i-1][j]+column[j][i];
            b=mesh[i][j-1]+row[i][j];
            if (a<b) mesh[i][j]=a;
            else mesh[i][j]=b;
        }
    }

    i=4; j=4; m[4][4]=true;
    while (i!=0 || j!=0) {
        if (mesh[i][j]-row[i][j]==mesh[i][j-1])
            j--;
        else
            i--;

        m[i][j]=true;
    }
    m[0][0]=true;



    printf("  %d   %d   %d   %d\n",row[0][1],row[0][2],row[0][3],row[0][4]);
    for (i=1;i<=4;i++) {
        printf("%d   %d   %d   %d   %d\n",column[0][i],column[1][i],column[2][i],column[3][i],column[4][i]);
        printf("  %d   %d   %d   %d\n",row[i][1],row[i][2],row[i][3],row[i][4]);
    }

    printf("\n");

    for (i=0;i<=4;i++) {
        for (j=0;j<=4;j++)
            printf("%2d  ",mesh[i][j]);
        printf("\n");
    }

    printf("\n");


    if (m[0][0]==true) printf("*");
    else printf(" ");
    for (j=1;j<=4;j++) {
        printf(" %d ",row[0][j]);

        if (m[0][j]==true) printf("*");
        else printf(" ");
    }
    printf("\n");
    for (i=1;i<=4;i++) {
        printf("%d   %d   %d   %d   %d\n",column[0][i],column[1][i],column[2][i],column[3][i],column[4][i]);

        if (m[i][0]==true) printf("*");
        else printf(" ");
        for (j=1;j<=4;j++) {
            printf(" %d ",row[i][j]);

            if (m[i][j]==true) printf("*");
            else printf(" ");
        }

        printf("\n");
    }
    return 0;
}
