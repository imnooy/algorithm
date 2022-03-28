#include <bits/stdc++.h>
using namespace std;

long long arr[100001];
long long d[100001];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		d[i] = arr[i];
	}

	for (int i = 2; i <= n; i++) {
		d[i] = max(d[i], d[i - 1] + arr[i]);
	}

	long long res = d[1];

	for (int i = 1; i <= n; i++) res = max(res, d[i]);
	
	cout << res;
	
	return 0;
}