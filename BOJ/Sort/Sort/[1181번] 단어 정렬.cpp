#include <bits/stdc++.h>
using namespace std;

int n;
string arr[20001];

bool cmp(const string &a, const string &b) {
	if (a.length() == b.length()) return a < b;
	else return a.length() < b.length();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n, cmp);

	cout << arr[0] << '\n';
	for (int i = 1; i < n; i++)
		if (arr[i] != arr[i - 1])
			cout << arr[i] << '\n';

	return 0;
}