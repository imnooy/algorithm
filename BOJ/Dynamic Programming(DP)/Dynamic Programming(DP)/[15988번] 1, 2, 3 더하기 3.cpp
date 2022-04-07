#include <bits/stdc++.h>
using namespace std;

int t, n;
long long arr[1000001];
long long d[1000001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for (int i = 4; i <= 1000000; i++) {
		d[i] = ((d[i - 3] % 1000000009) + (d[i - 2] % 1000000009) + (d[i - 1] % 1000000009)) % 1000000009;
	}

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << d[n] % 1000000009 << '\n';
	}

	return 0;
}