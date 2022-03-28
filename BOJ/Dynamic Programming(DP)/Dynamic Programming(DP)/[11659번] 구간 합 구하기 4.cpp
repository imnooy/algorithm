#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[100001];
int arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	d[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + arr[i];
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << d[b] - d[a - 1] << '\n';
	}
	
	return 0;
}