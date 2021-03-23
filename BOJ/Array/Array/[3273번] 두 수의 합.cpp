#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a;
	int cnt = 0;
	cin >> n;
	int arr[1000001];
	bool arr1[1000001];
	fill(arr1, arr1 + 1000001, false);
	fill(arr, arr + 1000001, 0);

	for (int i = 0; i < n; i++) {
		cin >> a;
		arr1[arr[i]] = true;
	}
	cin >> m;

	for (int i = 0; i < n; i++) {
		if (arr1[m - arr[i]] == true) {
			cnt++;
			arr1[m - arr[i]] = false;
		}
	}

	cout << cnt;

	return 0;
}