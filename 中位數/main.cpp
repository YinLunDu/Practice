#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(NULL));
    int num[1001],i;
    for (i=0;i<=1000;i++) {
        num[i]=rand()%90+10;
        cout << num[i] << " ";
    }
    cout << "\n";
    sort(num, num+1001);
    for (i=0;i<=1000;i++)
        cout << num[i] << " ";
    cout << "\n";
    cout << num[500] << "\n";
    return 0;
}
