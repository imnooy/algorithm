#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[1001];
long long d[1001];
int cnt[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		d[i] = arr[i];
		cnt[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				d[i] = max(d[i], d[j] + arr[i]);
				cnt[i] = max(cnt[i], cnt[j] + 1);
			}
		}
	}

	cout << *max_element(cnt, cnt + n + 1);
	
	return 0;
}