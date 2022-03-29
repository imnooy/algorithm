#include <bits/stdc++.h>
using namespace std;

int t, n;
long long d[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	d[1] = 1; d[2] = 1; d[3] = 1;
	for (int i = 4; i <= 100; i++) d[i] = d[i - 3] + d[i - 2];

	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << d[n] << '\n';
	}

	return 0;
}