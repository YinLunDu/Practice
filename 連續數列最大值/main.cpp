#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 1000000

using namespace std;

int main()
{
    int i,j;
    char num[N+1];
    long long m,sum;
    srand(time(NULL));
    for (i=1;i<=N;i++) {
        num[i]=rand()%21-10;
        //cout << num[i] << " ";
    }
    cout << "\n";
    m=-100;
    cout << "OK";
    for (i=1;i<=N;i++) {
        if (i%10000==0) cout << i << endl;
        sum=0;
        for (j=i;j<=N;j++) {
            sum+=num[j];
            if (sum>m) m=sum;
        }
    }
    cout << m;
    return 0;
}
