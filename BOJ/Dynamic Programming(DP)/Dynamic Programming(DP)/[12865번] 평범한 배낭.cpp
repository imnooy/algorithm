#include <bits/stdc++.h>
using namespace std;

int w[100001];
int v[100001];
int d[101][100001];
//i개 물건이 j무게의 가방에 담겼을 때의 가치합의 최댓값
int n, k;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) { //i개
		for (int j = 1; j <= k; j++) { //j무게
			if (j - w[i] >= 0) {
				d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i]] + v[i]);
				//d[i-1][j]: i번째 물건 포함안할 때
				//d[i-1][j-w[i]]+v[i]: i번째 물건 포함 시킬 때
			}
			else d[i][j] = d[i - 1][j];
		}
	}
	
	int res = d[1][k];
	for (int i = 2; i <= n; i++) res = max(res, d[i][k]);
	cout << res;

	return 0;
}