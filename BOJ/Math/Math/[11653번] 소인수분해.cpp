#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, j;
	cin >> n;
	
	int m = n;

	j = 2;
	while (j <= m) {
		if (n % j == 0) {
			n = n / j;
			cout << j << endl;
		}
		else j++;

		if (n == 1) break;
	}

	return 0;
}