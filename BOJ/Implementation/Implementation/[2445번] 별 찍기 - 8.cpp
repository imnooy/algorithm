#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int blank = (n - 1);
	int blank1 = 1;
	int star;

	for (int i = 1; i <= n-1; i++) {
		star = i;
		for (int j = 0; j < star; j++) cout << "*";
		for (int k = 0; k < blank; k++) cout << " ";
		for (int k = 0; k < blank; k++) cout << " ";
		for (int j = 0; j < star; j++) cout << "*";
		blank--;
		cout << '\n';
	}
	for (int i = 0; i < 2 * n; i++) cout << "*";
	cout << '\n';

	for (int i = n - 1; i >= 1; i--) {
		star = i;
		for (int j = 0; j < star; j++) cout << "*";
		for (int k = 0; k < blank1; k++) cout << " ";
		for (int k = 0; k < blank1; k++) cout << " ";
		for (int j = 0; j < star; j++) cout << "*";
		blank1++;
		cout << '\n';
	}

	return 0;
}