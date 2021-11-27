#include <iostream>
#include <cstdlib>

using namespace std;

struct item
{
    struct item *left;
    char ch;
    struct item *right;
};

void preorder(struct item *p)
{
    if (p->left==NULL && p->right==NULL) {
        if (p->ch!=NULL) cout << p->ch << " ";
    } else {
        if (p->ch!=NULL) cout << p->ch << " ";
        preorder( p->left );
        preorder( p->right );
    }
}

void inorder(struct item *p)
{
    if (p->left==NULL && p->right==NULL) {
        if (p->ch!=NULL) cout << p->ch << " ";
    } else {
        inorder( p->left );
        if (p->ch!=NULL) cout << p->ch << " ";
        inorder( p->right );
    }
}

void postorder(struct item *p)
{
    if (p->left==NULL && p->right==NULL) {
        if (p->ch!=NULL) cout << p->ch << " ";
    } else {
        postorder( p->left );
        postorder( p->right );
        if (p->ch!=NULL) cout << p->ch << " ";
    }
}

int main()
{
    struct item *p1,*p2,*p3,*p4,*p5,*p6,*p7;
    p1=(struct item *)malloc(sizeof(struct item));
    p2=(struct item *)malloc(sizeof(struct item));
    p3=(struct item *)malloc(sizeof(struct item));
    p4=(struct item *)malloc(sizeof(struct item));
    p5=(struct item *)malloc(sizeof(struct item));
    p6=(struct item *)malloc(sizeof(struct item));
    p7=(struct item *)malloc(sizeof(struct item));

    p1->ch='A'; p1->left=p2; p1->right=p3;
    p2->ch='B'; p2->left=p4; p2->right=p5;
    p3->ch='C'; p3->left=p6; p3->right=p7;
    p4->ch='D'; p4->left=NULL; p4->right=NULL;
    p5->ch='E'; p5->left=NULL; p5->right=NULL;
    p6->ch=NULL; p6->left=NULL; p6->right=NULL;
    p7->ch='F'; p7->left=NULL; p7->right=NULL;

    preorder(p1);
    cout << "\n";
    cout << "\n";

    inorder(p1);
    cout << "\n";
    cout << "\n";

    postorder(p1);
    cout << "\n";
    cout << "\n";
    return 0;
}
