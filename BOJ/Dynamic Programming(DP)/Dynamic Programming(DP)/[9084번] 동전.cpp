#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int d[10001];
int arr[10001];

int main() {
	cin >> t;

	for (int a = 0; a < t; a++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		cin >> m;

		d[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = arr[i]; j <= m; j++) {
				d[j] += d[j - arr[i]];
			}
		}

		cout << d[m] << '\n';
		fill(arr, arr + 10001, 0);
		fill(d, d + 10001, 0);
	}
}