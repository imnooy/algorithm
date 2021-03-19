#include <iostream>
using namespace std;

int main() {
	int n;
	int cnt = 0;
	cin >> n;
	bool isPrime = true;
	int *arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		isPrime = true;
		if (arr[i] == 1) isPrime = false;
		if (arr[i] > 2) {
			for (int j = 2; j <= arr[i] - 1; j++) {
				if (arr[i] % j == 0) {
					isPrime = false;
				}
			}
		}

		if (isPrime == true) cnt++;
	}

	cout << cnt;

	return 0;
}