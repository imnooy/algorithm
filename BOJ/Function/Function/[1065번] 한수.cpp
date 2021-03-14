#include <iostream>
using namespace std;

bool d(int n) {

	int x, a, b, c, w, y;
	int result = 0;

	if (0 < n && n < 100) {
		return true;
	}
	else if (100 <= n && n < 1000) {
		a = n / 100;
		n =	n - (a * 100);
		b = n / 10;
		n = n - (b * 10);
		c = n;

		if ((a < b) && (b < c)) {
			w = b - a;
			y = c - b;
			if (w == y) return true;
			else return false;
		}
		else if (((a < b) && (b > c)) || ((a > b) && (b < c))) {
			return false;
		}

		else {
			w = a - b;
			y = b - c;
			if (w == y) return true;
			else return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	int n;
	int cnt = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (d(i) == true) cnt++;
	}

	cout << cnt;


	return 0;
}