#include <bits/stdc++.h>
using namespace std;

int arr[100002][4];
int d[100002][4];


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	int index = 1;
	while (1) {

		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> arr[i][j];
			}
		}

		arr[1][1] = arr[1][2];
		arr[1][3] += arr[1][1];
		for (int j = 1; j <= 3; j++) d[1][j] = arr[1][j];

		for (int i = 2; i <= n; i++) {
			d[i][1] = min(d[i - 1][1], d[i - 1][2]) + arr[i][1];

			d[i][2] = min({ d[i - 1][1], d[i - 1][2], d[i - 1][3], d[i][1] }) + arr[i][2];

			d[i][3] = min({ d[i - 1][2], d[i - 1][3], d[i][2] }) + arr[i][3];
		}

		cout << index++ << ". " << d[n][2] << '\n';
	}

	return 0;
}