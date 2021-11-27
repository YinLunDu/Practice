#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int i;
    double x,y,c;
    c=0;
    for (i=1;i<=1000000000;i++) {
        x=(double) rand() / (RAND_MAX);
        y=(double) rand() / (RAND_MAX);
        if (x*x+y*y<1 || x*x+y*y==1) c++;
    }
    cout << c/1000000000.0000*4.0000;
    return 0;
}
