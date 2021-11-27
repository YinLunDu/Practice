#include <iostream>
#include <fstream>
#define A 32
#define B 32
 
using namespace std;

int graph1[A+1][B+1],graph2[A+1][B+1];
bool check[A+1][B+1];

bool inside(int i, int j)
{
    if (1<=i && i<=A && 1<=j && j<=B)
        return true;
    else
        return false;
}

bool near_ocean(int i, int j)
{
	if (inside(i+0,j+1)) if (graph2[i+0][j+1]==0) return true;
    if (inside(i-0,j-1)) if (graph2[i-0][j-1]==0) return true;
	if (inside(i+1,j+0)) if (graph2[i+1][j+0]==0) return true;
    if (inside(i-1,j-0)) if (graph2[i-1][j-0]==0) return true;
    
	return false;
}

void func(int i, int j, int num)
{
	if (inside(i+0,j+1)) if (check[i+0][j+1]==false && graph1[i+0][j+1]==1) {check[i+0][j+1]=true; graph1[i+0][j+1]=num; func(i+0,j+1,num);}
    if (inside(i-0,j-1)) if (check[i-0][j-1]==false && graph1[i-0][j-1]==1) {check[i-0][j-1]=true; graph1[i-0][j-1]=num; func(i-0,j-1,num);}
	if (inside(i+1,j+0)) if (check[i+1][j+0]==false && graph1[i+1][j+0]==1) {check[i+1][j+0]=true; graph1[i+1][j+0]=num; func(i+1,j+0,num);}
    if (inside(i-1,j-0)) if (check[i-1][j-0]==false && graph1[i-1][j-0]==1) {check[i-1][j-0]=true; graph1[i-1][j-0]=num; func(i-1,j-1,num);}
    if (inside(i+1,j+1)) if (check[i+1][j+1]==false && graph1[i+1][j+1]==1) {check[i+1][j+1]=true; graph1[i+1][j+1]=num; func(i+1,j+1,num);}
    if (inside(i-1,j-1)) if (check[i-1][j-1]==false && graph1[i-1][j-1]==1) {check[i-1][j-1]=true; graph1[i-1][j-1]=num; func(i-1,j-1,num);}
    if (inside(i+1,j-1)) if (check[i+1][j-1]==false && graph1[i+1][j-1]==1) {check[i+1][j-1]=true; graph1[i+1][j-1]=num; func(i+1,j-1,num);}
    if (inside(i-1,j+1)) if (check[i-1][j+1]==false && graph1[i-1][j+1]==1) {check[i-1][j+1]=true; graph1[i-1][j+1]=num; func(i-1,j+1,num);}
}

int main()
{
    ifstream file("data_32.txt");
    if (!file) {
        cout << "Cannot open\n";
        return 1;
    }

    int i,j,c;
    char ch;
    for (i=1;i<=B;i++) {
        for (j=1;j<=A;j++) {
            file >> ch;
            graph1[i][j]=(int)ch-'0';
            graph2[i][j]=(int)ch-'0';
        }
        file.ignore();
    }

	c=1;
	for (i=1;i<=A;i++) 
        for (j=1;j<=B;j++) 
            if (check[i][j]==false && graph2[i][j]!=0) {
            	func(i,j,c);
            	c++;
			}
	
	for (i=1;i<=A;i++) 
        for (j=1;j<=B;j++)
        	if (near_ocean(i,j) && graph2[i][j]!=0) graph2[i][j]=-1;
    
    cout << "Q1:\n";
    for (i=1;i<=B;i++) {
        for (j=1;j<=A;j++) {
            cout << graph1[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << "Q2:" << c-1 << "\n";
    
    cout << "Q3:\n";
    for (i=1;i<=B;i++) {
        for (j=1;j<=A;j++) {
            if (graph2[i][j]==-1) cout << "* ";
            else cout << graph2[i][j] << " ";
        }
        cout << "\n";
    }
    file.close();
    return 0;
}
