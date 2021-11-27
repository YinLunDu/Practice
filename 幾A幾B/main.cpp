#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
    int i,n,A,B,num[1000],last[1000],guess,gh,gt,go,h,t,o,compare_A,compare_B,len,times;

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
    while (1) {
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
            guess=last[rand()%len];
            times++;
            cout << guess << " ";
            cin >> A >> B;
        }
        if (A==3) {
            cout << "Total: " << times << " times!";
            break;
        }
        gh=guess/100;
        gt=(guess%100)/10;
        go=guess%10;
        for (i=0;i<=999;i++) {
            if (num[i]==0) continue;
            h=i/100;
            t=(i%100)/10;
            o=i%10;
            compare_A=0; compare_B=0;
            if (gh==h) compare_A++;
            if (gt==t) compare_A++;
            if (go==o) compare_A++;
            if (gh==t||gh==o) compare_B++;
            if (gt==h||gt==o) compare_B++;
            if (go==h||go==t) compare_B++;
            if (A!=compare_A||B!=compare_B) num[i]=0;
        }
    }
    return 0;
}
