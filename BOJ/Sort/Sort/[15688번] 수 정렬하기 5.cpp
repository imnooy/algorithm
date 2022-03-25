#include <bits/stdc++.h>
using namespace std;

int cnt[2000001];
int n, a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cnt[1000000 + a]++;
	}

	for (int i = 0; i < 2000001; i++)
		for (int j = 0; j < cnt[i]; j++)
			cout << i - 1000000 << '\n';

	return 0;
}