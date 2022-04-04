#include <bits/stdc++.h>
using namespace std;

int n;

int t[1500002];
long long p[1500002];
long long d[1500002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
	long long maximum = 0;
	for (int i = 1; i <= n; i++) {
		maximum = max(maximum, d[i]);
		if (i + t[i] > n + 1) continue;
		d[i + t[i]] = max(d[i + t[i]], maximum + p[i]);
	}

	cout << *max_element(d, d + n + 2);

	return 0;
}