#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool arr[10001];
	fill(arr, arr + 10001, true);
	int n, a;
	int x, y;

	for (int i = 2; i <= 10000; i++) {
		if (arr[i] == true) {
			for (int j = i * 2; j <= 10000; j += i) {
				arr[j] = false;
			}
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 2; j < a; j++) {
			if (arr[j]) {
				if (arr[a - j]) {
					if (j <= (a - j)) {
						x = j;
						y = a - j;
					}
				}
			}
		}
		cout << x << " " << y << '\n';
	}
}