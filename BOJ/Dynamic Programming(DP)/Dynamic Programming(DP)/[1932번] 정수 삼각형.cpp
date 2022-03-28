#include <bits/stdc++.h>
using namespace std;

int arr[501][501];
int d[501][501];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(&d[0][0], &d[500][501], -1);
	fill(&arr[0][0], &arr[500][501], -1);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	d[1][1] = arr[1][1];

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			if (d[i + 1][j] == -1) 
				d[i + 1][j] = d[i][j] + arr[i + 1][j];
			else 
				d[i + 1][j] = max(d[i][j] + arr[i + 1][j], d[i + 1][j]);

			if (d[i + 1][j + 1] == -1) 
				d[i + 1][j + 1] = d[i][j] + arr[i + 1][j + 1];
			else 
				d[i + 1][j + 1] = max(d[i][j] + arr[i + 1][j + 1], d[i + 1][j + 1]);
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res, d[n][i]);

	cout << res;
	
	return 0;
}