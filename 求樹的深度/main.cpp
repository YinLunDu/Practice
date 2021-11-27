/*
8
0 1
0 2
0 3
7 0
1 4
1 5
3 6
*/
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class item
{
    public:
        int num;
        vector <item *> leaves;
};

int deep[100];

int find_deep(item *p)
{
    int big,temp,i;
    if (p->leaves.empty()) {
        deep[p->num]=0;
        return 0;
    } else {
        big=0;
        for (i=0;i<=(int)p->leaves.size()-1;i++) {
            temp=find_deep(p->leaves[i]);
            if (temp>big)
                big=temp;
        }
        deep[p->num]=big+1;
        return big+1;
    }
}

int main()
{
    bool pointed[100];
    int n,i,a,b;
    item *p[100], *root;
    cin >> n;
    for (i=0;i<=n-1;i++) {
        p[i]=new item;
        p[i]->num=i;
        p[i]->leaves.clear();
        pointed[i]=false;
    }
    for (i=1;i<=n-1;i++) {
        cin >> a >> b;
        p[a]->num=a;
        p[a]->leaves.push_back(p[b]);
        pointed[b]=true;
    }
    for (i=0;i<=n-1;i++)
        if (pointed[i]==false) {
            root=p[i];
            break;
        }

    find_deep(root);

    for (i=0;i<=n-1;i++)
        cout << i << ":" << deep[i] << "\n";
    return 0;
}
