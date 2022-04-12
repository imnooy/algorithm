#include <bits/stdc++.h>
using namespace std;

long long arr[10];
long long d[1001];
long long tmp;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	fill(arr, arr + 10, 1);

	int n;
	cin >> n;

	d[1] = 10;

	for (int i = 2; i <= n; i++) {
		arr[9] = 1;
		long long sum = 1;
		for (int j = 8; j >= 0; j--) {
			arr[j] = (arr[j + 1] + arr[j]) % 10007;
			sum = (sum + arr[j]) % 10007;
		}
		d[i] = sum;
	}
	cout << d[n] % 10007;
	return 0;
}