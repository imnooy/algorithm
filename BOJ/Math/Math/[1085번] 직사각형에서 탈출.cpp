#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int arr[4];
	arr[0] = w - x;
	arr[1] = h - y;
	arr[2] = x;
	arr[3] = y;

	int min = arr[0];
	for (int i = 1; i < 4; i++) {
		if (arr[i] < min) min = arr[i];
	}
	cout << min;
	
}