#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int last[1000],len;

void compare_A_B(int ans, int num, int *A, int *B)
{
    int h1,t1,o1,h2,t2,o2;
    h1=ans/100;
    t1=(ans%100)/10;
    o1=ans%10;
    h2=num/100;
    t2=(num%100)/10;
    o2=num%10;
    *A=0; *B=0;
    if (h1==h2) *A+=1;
    if (t1==t2) *A+=1;
    if (o1==o2) *A+=1;
    if (h1==t2||h1==o2) *B+=1;
    if (t1==h2||t1==o2) *B+=1;
    if (o1==h2||o1==t2) *B+=1;
}

/*
2A
1A2B 1A1B 1A
3B 2B 1B
0A0B
*/

int search_num()
{
    int i,j,cases[9],try_A,try_B,big;
    float multiply[len];
    for (i=0;i<=len-1;i++) { //即將要猜
        cases[1]=1; cases[2]=1; cases[3]=1; cases[4]=1; cases[5]=1; cases[6]=1; cases[7]=1; cases[8]=1;
        for (j=0;j<=len;j++) { //嘗試
            compare_A_B(last[j],last[i],&try_A,&try_B);
            if (try_A==2 && try_B==0) cases[1]++;
            else if (try_A==1 && try_B==2) cases[2]++;
            else if (try_A==1 && try_B==1) cases[3]++;
            else if (try_A==1 && try_B==0) cases[4]++;
            else if (try_A==0 && try_B==3) cases[5]++;
            else if (try_A==0 && try_B==2) cases[6]++;
            else if (try_A==0 && try_B==1) cases[7]++;
            else if (try_A==0 && try_B==0) cases[8]++;
        }
        multiply[i]=sqrt(cases[1])*sqrt(cases[2])*sqrt(cases[3])*sqrt(cases[4])*sqrt(cases[5])*sqrt(cases[6])*sqrt(cases[7])*sqrt(cases[8]);
    }
    big=0;
    for (i=1;i<=len-1;i++)
        if (multiply[i]>multiply[big])
            big=i;
    return last[big];
}

int main()
{
    int i,n,A,B,num[1000],guess,compare_A,compare_B,times;

    for (i=0;i<=999;i++) num[i]=0;
    n=102;
    while (100<n&&n<1000) {
        if (n/100!=(n%100)/10&&(n%100)/10!=n%10&&n/100!=n%10)
            num[n]=1;
        n++;
    }
    srand(5);
    //srand(time(NULL));

    times=0;
    guess=rand()%1000;
    while (num[guess]!=1) guess=rand()%1000;
    times++;
    cout << guess << " ";
    cin >> A >> B;

    while (1) {
        for (i=0;i<=999;i++) {
            if (num[i]==0) continue;
            compare_A_B(guess,i,&compare_A,&compare_B);
            if (A!=compare_A||B!=compare_B) num[i]=0;
        }
        len=0;
        for (i=0;i<=999;i++)
            if (num[i]==1) {
                last[len]=i;
                len++;
            }
        if (len==0) {
            cout << "Input Wrong!";
            break;
        } else {
            guess=search_num();
            times++;
            cout << guess << " ";
            cin >> A >> B;
        }
        if (A==3) {
            cout << "Total: " << times << " times!";
            break;
        }
    }
    return 0;
}
