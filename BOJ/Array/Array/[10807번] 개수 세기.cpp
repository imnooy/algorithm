#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[201] = { 0 };
	int n, v, v1;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v1;
		arr[v1 + 100]++;
	}

	cin >> v;

	cout << arr[v + 100];
	return 0;
}