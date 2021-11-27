#include <iostream>
using namespace std;

void Towers(int n,char from,char by,char to) {
	if (n==1) {
		cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<endl;
	} else {
		Towers(n-1,from,to,by);
		cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<endl;
		Towers(n-1,by,from,to);
	}
}
int main() {
	int n;
	cin >> n;
	Towers(n,'A','B','C');
	cout << endl;
	return 0;
}
