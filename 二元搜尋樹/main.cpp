#include <iostream>
#include <cstdlib>
#define N 9

using namespace std;

int num[N]={5,3,4,8,1,7,9,2,6};

struct item
{
    struct item *left;
    int value;
    struct item *right;
};


void inorder(struct item *p)
{
    if (p->left!=NULL) inorder( p->left );
    cout << p->value << " ";
    if (p->right!=NULL) inorder( p->right );
}



int main()
{
    struct item *top,*now,*p;
    int i,n;
    top=(struct item *)malloc(sizeof(struct item));
    top->value=num[0]; top->left=NULL; top->right=NULL;

    for (i=1;i<=N-1;i++) {
        now=top;
        while ((now->left!=NULL && num[i]<now->value) || (now->right!=NULL && num[i]>now->value)) {
            if (num[i]>now->value) now=now->right;
            else if (num[i]<now->value) now=now->left;
        }
        p=(struct item *)malloc(sizeof(struct item));
        p->value=num[i];
        p->left=NULL;
        p->right=NULL;
        if (num[i] < (now->value) )
            now->left=p;
        if (num[i] > (now->value) )
            now->right=p;
    }

    inorder(top);
    /*
    cin >> n;
    now=top;
    while (n != (now->value) ) {
        cout << now->value << " ";
        if (n > (now->value) ) now=now->right;
        else if (n < (now->value) ) now=now->left;
    }
    cout << n << " ";
    */
    return 0;
}
