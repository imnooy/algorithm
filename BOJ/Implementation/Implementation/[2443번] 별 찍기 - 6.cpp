#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int blank = 0;
	int star;

	for (int i = n; i >= 1; i--) {
		star = 2 * i - 1;
		for (int j = 0; j < blank; j++) cout << " ";
		for (int k = 0; k < star; k++) cout << "*";
		blank++;
		cout << '\n';
	}

	return 0;
}