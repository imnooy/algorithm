#include <bits/stdc++.h>
using namespace std;

long long d[1000001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= 1000000; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 15746;
	}

	int n;
	cin >> n;
	cout << d[n];

	return 0;
}