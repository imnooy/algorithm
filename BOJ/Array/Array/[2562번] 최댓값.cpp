#include <iostream>
using namespace std;

int main() {
	int x, max, m;
	int arr[9];
	for (int i = 0; i < 9; i++) {
		cin >> x;
		if (x >0 && x<100) arr[i] = x;
	}

	m = 0;
	max = arr[0];
	for (int i = 0; i < 8; i++) {
		if (max < arr[i + 1]) {
			max = arr[i + 1];
			m = i + 1;
		}
	}

	cout << max << endl << m+1;
	return 0;
}

