#include <iostream>
using namespace std;

int main() {
	int n, x, max, min;	
	cin >> n;
	int arr[1000000];
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x >= (-1000000) && x <= 1000000) arr[i] = x;
	}

	max = arr[0];
	min = arr[0];
	for (int i = 0; i < n-1; i++) {
		if (max < arr[i + 1]) {
			max = arr[i+1];
		}
		if (min > arr[i + 1]) {
			min = arr[i+1];
		}
	}

	cout << min << " " << max;
	return 0;
}

