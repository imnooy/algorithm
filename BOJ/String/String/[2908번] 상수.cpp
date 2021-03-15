#include <iostream>
#include <string>
using namespace std;

int main() {
	string x, y;
	string xx, yy="";
	int a, b;
	cin >> x >> y;
	
	for (int i = 2; i >=0; i--) {
		xx += x[i];
		yy += y[i];
	}

	a = stoi(xx);
	b = stoi(yy);

	if (a >= b) cout << a;
	else cout << b;


	return 0;
}