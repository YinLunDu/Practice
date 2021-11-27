#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(NULL));
    int num[100],i,n,right,left,mid;
    for (i=0;i<=99;i++)
        num[i]=rand()%100;
    sort(num, num+100);
    for (i=0;i<=99;i++)
        cout << num[i] << " ";
    cout << "\n";
    cin >> n;
    right=0; left=99;
    while (right<=left) {
        mid=(right+left)/2;
        if (n==num[mid])
            break;
        else if (n>num[mid])
            right=mid+1;
        else if (n<num[mid])
            left=mid-1;
    }
    if (n==num[mid]) cout << mid;
    else cout << "No Result\n";
    return 0;
}
