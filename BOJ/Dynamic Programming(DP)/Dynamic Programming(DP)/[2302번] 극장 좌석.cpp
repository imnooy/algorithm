#include <bits/stdc++.h>
using namespace std;

long long d[41];
int n, m, num;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		d[num] = -1;
	}
	d[0] = -1;
	int first = 2;
	int second = 3;

	int res = 1;

	for (int i = 1; i < n; i++) {
		if (d[i] == -1) continue;
		
		if (d[i - 1] == -1 && d[i + 1] == -1) d[i] = 1;
		
		else if (d[i - 1] == -1 && d[i + 1] != -1) d[i] = first;
		else if (d[i - 1] == first && d[i + 1] != -1) d[i] = second;

		else if (d[i + 1] == -1) d[i] = d[i - 1];

		else if (d[i - 1] != -1 && d[i + 1] != -1) d[i] = d[i - 2] + d[i - 1];

		if (d[i + 1] == -1) res *= d[i];
	}

	if (d[n] != -1) {
		res *= d[n - 1];
	}

	cout << res;

	return 0;
}