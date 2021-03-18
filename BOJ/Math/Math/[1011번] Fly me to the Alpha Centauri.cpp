#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long int a, b, x, y, z, t;
	double dou;
	int cnt, n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		x = b - a;
		y = sqrt(x); //(b-a)ÀÇ Á¦°ö±Ù
		dou = sqrt(x);
		z = pow(y, 2) + 1;
		t = sqrt(x - 1);
		if ((dou - y) == 0) cnt = 2 * t + 1;
		else {
			if (x < ((pow((y + 1), 2) + z) / 2)) cnt = 2 * y;
			else cnt = 2 * y + 1;
		}

		cout << cnt << endl;
	}

	return 0;
}