#include <iostream>
#define N 7

using namespace std;

char tree[16]={' ', 'A', 'B', 'C', 'D', 'E', ' ', 'F'};

int find_num(char c)
{
    int i;
    for (i=1;;i++) if (tree[i]==c) break;
    return i;
}

void find_clildren(char c)
{
    int m;
    m=find_num(c);

    if (2*m <= N) if (tree[2*m]!=' ') cout << tree[2*m] << " ";
    if (2*m+1 <= N) if (tree[2*m+1]!=' ') cout << tree[2*m+1] << " ";
}

void preorder(char c)
{
    int m;
    m=find_num(c);

    if (m*2 > N) {
        if (c!=' ') cout << c << " ";
    } else {
        if (c!=' ') cout << c << " ";
        preorder( tree[m*2] );
        preorder( tree[m*2+1] );
    }
}

void inorder(char c)
{
    int m;
    m=find_num(c);

    if (m*2 > N) {
        if (c!=' ') cout << c << " ";
    } else {
        inorder( tree[m*2] );
        if (c!=' ') cout << c << " ";
        inorder( tree[m*2+1] );
    }
}

void postorder(char c)
{
    int m;
    m=find_num(c);

    if (m*2 > N) {
        if (c!=' ') cout << c << " ";
    } else {
        postorder( tree[m*2] );
        postorder( tree[m*2+1] );
        if (c!=' ') cout << c << " ";
    }
}

int main()
{
    char c;
    cin >> c;

    find_clildren(c);
    cout << "\n";
    cout << "\n";

    preorder('A');
    cout << "\n";
    cout << "\n";

    inorder('A');
    cout << "\n";
    cout << "\n";

    postorder('A');
    cout << "\n";
    cout << "\n";
    return 0;
}
