#include <bits/stdc++.h>
using namespace std;

int arr[2][100001];
int d[2][100001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t, n;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		fill(&d[0][0], &d[1][100001], 0);
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}

		d[0][1] = arr[0][1];
		d[1][1] = arr[1][1];

		for (int i = 2; i <= n; i++) {
			d[0][i] = max(d[1][i - 1] + arr[0][i], d[0][i - 1]);
			d[1][i] = max(d[0][i - 1] + arr[1][i], d[1][i - 1]);
		}

		cout << max(d[0][n], d[1][n]) << '\n';
	}

	return 0;
}