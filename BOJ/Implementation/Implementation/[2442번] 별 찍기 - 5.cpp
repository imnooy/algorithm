#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int blank = (n - 1);
	int star;

	for (int i = 1; i <= n; i++) {
		star = 2 * i - 1;
		for (int j = 0; j < blank; j++) cout << " ";
		for (int k = 0; k < star; k++) cout << "*";
		blank--;
		cout << '\n';
	}

	return 0;
}