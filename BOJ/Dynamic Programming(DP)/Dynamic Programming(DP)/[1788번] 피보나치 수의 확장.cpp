#include <bits/stdc++.h>
using namespace std;

long long d[2000002];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	d[1000000] = 0;
	d[1000001] = 1;

	for (int i = 1000002; i <= 2000000; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 1000000000;
	}

	for (int i = 999999; i >= 0; i--) {
		d[i] = (d[i + 2] - d[i + 1]) % 1000000000;
	}

	int n;
	cin >> n;
	int a = n + 1000000;
	if (d[a] > 0) cout << 1 << '\n';
	else if (d[a] == 0) cout << 0 << '\n';
	else cout << -1 << '\n';

	cout << abs(d[a]);

	return 0;
}