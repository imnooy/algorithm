#include <iostream>
using namespace std;

int main() {
	int n, max;
	float avg, x;
	avg = 0.0;
	cin >> n;
	float *arr = new float[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	max = arr[0];
	for (int i = 0; i < n; i++) {
		if (max < arr[i + 1]) {
			max = arr[i + 1];
		}
	}

	for (int i = 0; i < n; i++) {
		x = arr[i] / max * 100;
		avg += x;
	}

	cout << avg / n;
	delete[] arr;
	return 0;
}