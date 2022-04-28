#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int n, m;
int d[1001][1001];

int main() {
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			arr[i][j + 1] = s[j] - '0';
		}
	}
	d[1][1] = arr[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) continue;

			if (i - 1 < 1 || j - 1 < 1) {
				d[i][j] = arr[i][j];
				continue;
			}

			if (arr[i][j] == 0) d[i][j] = 0;
			
			if (arr[i - 1][j] == 0 || arr[i][j - 1] == 0 || arr[i - 1][j - 1] == 0) {
				d[i][j] = 0;
				if (arr[i][j] == 1) d[i][j] = 1;
				continue;
			}
			int minimum = d[i - 1][j - 1];
			minimum = min({ minimum, d[i - 1][j], d[i][j - 1] });
			d[i][j] = minimum + 1;
			
			if (arr[i][j] == 0) d[i][j] = 0;

		}
	}

	int res = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			res = max(res, d[i][j]);
		}
	}

	cout << res * res;
	return 0;
}