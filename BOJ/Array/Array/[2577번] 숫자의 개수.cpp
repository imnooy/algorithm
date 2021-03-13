#include <iostream>
using namespace std;

int main() {
	int a, b, c, i, y, mul;
	int arr[10] = { 0 };
	cin >> a >> b >> c;
	mul = a * b * c;

	y = 1000000;
	while (y <= 1000000000) {
		if (y < mul) {
			y *= 10;
		}
		else {
			y /= 10;
			break;
		}
	}

	int x;
	for (i = y; i >=1; i /= 10) {
		x = mul / i;
		arr[x] += 1;
		mul-= x*i;
	}

	for (int j = 0; j < 10; j++) {
		cout << arr[j] << endl;
	}

	return 0;
}
