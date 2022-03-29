#include <bits/stdc++.h>
using namespace std;

int n;

int t[16];
long long p[16];
long long d[16];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
		d[i] = p[i];
	}
	
	for (int i = 1; i <= n; i++) {
		if (t[i] + i > n + 1) {
			d[i] = 0;
			continue;
		}
		for (int j = 1; j < i; j++) {
			if (t[j] + j - 1 < i) 
				d[i] = max(d[j] + p[i], d[i]);
		}
	}

	cout << *max_element(d, d + n + 1);

	return 0;
}