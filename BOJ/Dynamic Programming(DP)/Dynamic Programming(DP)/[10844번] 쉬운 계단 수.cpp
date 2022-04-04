#include <bits/stdc++.h>
using namespace std;

int n;

long long d[101][10]; //끝자리 개수 저장 (0~9)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 1; i <= 9; i++) d[1][i] = 1;

	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j != 0) d[i][j] += d[i - 1][j - 1];
			if (j != 9) d[i][j] += d[i - 1][j + 1];
			d[i][j] = d[i][j] % 1000000000;
		}
	}
	
	long long res = 0;

	cin >> n;
	for (int i = 0; i <= 9; i++) res += d[n][i];
	cout << res % 1000000000;

	return 0;
}