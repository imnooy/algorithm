#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.length() / 2; j++) {
			char tmp = s[j];
			s[j] = s[s.length() - j - 1];
			s[s.length() - j - 1] = tmp;
		}
		arr[i] = stoll(s);
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}