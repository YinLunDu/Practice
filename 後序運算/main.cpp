#include <iostream>
#include <cstring>

using namespace std;

int stack[100]={0}, top=0;

int pop() {int num; num=stack[top]; top--; return num;}
void push(int num) {top++; stack[top]=num;}

int main()
{
    string str;
    int i,a,b,c,temp;
    char ch;
    bool error;
    getline(cin, str);

    i=0; error=false;
    for (i=0;i<=str.length()-1;i++) {
        ch=str[i];
		
        switch (ch) {
        	case ' ':
        		break;
            case '+':
                b=pop(); a=pop(); c=a+b; push(c); break;
            case '-':
                b=pop(); a=pop(); c=a-b; push(c); break;
            case '*':
                b=pop(); a=pop(); c=a*b; push(c); break;
            case '/':
                b=pop(); a=pop();
                if (b==0) error=true;
                else {c=a/b; push(c);}
                break;
            case '%':
                b=pop(); a=pop();
                if (b==0) error=true;
                else {c=a%b; push(c);}
                break;
            default:
            	temp=(int)ch-(int)'0';
            	while ((int)'0'<=(int)str[i+1] && (int)str[i+1]<=(int)'9') {
            		i++;
            		temp=temp*10+(int)str[i]-(int)'0';
				}
                push(temp);
        }
        if (error==true) break;
    }
    if (error==true) cout << "error\n";
	else cout << pop() << "\n";
    return 0;
}
