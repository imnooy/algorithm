#include <iostream>
using namespace std;

int main() {
	int a, b, k, temp;

	int arr[21] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		k = b;
		for (int j = a; j <= a+((b-a)/2); j++) {
			temp = arr[j];
			arr[j] = arr[k];
			arr[k] = temp;
			k--;
		}
	}

	for (int i = 1; i <= 20; i++) cout << arr[i] << " ";

	return 0;
}