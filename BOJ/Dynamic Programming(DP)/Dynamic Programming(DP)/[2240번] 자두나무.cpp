#include <bits/stdc++.h>
using namespace std;

int t, w;
int arr[1001];
int d[1001][3][31]; //이동 시간, 위치, 이동 횟수

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> t >> w;
	for (int i = 1; i <= t; i++) cin >> arr[i];

	for (int i = 1; i <= t; i++) {
		if (arr[i] == 1) {
			d[i][1][0] = d[i - 1][1][0] + 1;
		}
		else d[i][1][0] = d[i - 1][1][0];
		//이동안할 때

		for (int j = 1; j <= w; j++) {
			if (i < j) break; //지금 시간보다 많이 이동 안됨

			if (arr[i] == 1) { //1번나무에서 떨어짐
				d[i][1][j] = max(d[i - 1][2][j - 1], d[i - 1][1][j]) + 1;
				d[i][2][j] = max(d[i - 1][1][j - 1], d[i - 1][2][j]);
			}

			else { //2번나무에서 떨어짐
				d[i][1][j] = max(d[i - 1][2][j - 1], d[i - 1][1][j]);
				d[i][2][j] = max(d[i - 1][1][j - 1], d[i - 1][2][j]) + 1;
			}
		}
	}

	int res = 0;
	for (int i = 0; i <= w; i++) res = max({ res, d[t][1][i], d[t][2][i] });
	cout << res;

	return 0;
}