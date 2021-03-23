#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int arr[10];
	int sum, max;
	fill(arr, arr + 10, 0);

	string n;
	cin >> n;

	for (auto c : n) {
		arr[c - '0']++;
	}

	sum = (arr[6] + arr[9]);
	if ((arr[6] + arr[9]) % 2 == 0) {
		arr[6] = sum / 2;
		arr[9] = sum / 2;
	}
	else {
		arr[6] = sum / 2 + 1;
		arr[9] = sum / 2;
	}

	max = arr[0];
	for (int i = 0; i < 10; i++) {
		if (arr[i] > max) max = arr[i];
	}

	cout << max;

	return 0;
}