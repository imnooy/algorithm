#include <bits/stdc++.h>
using namespace std;

int t; //tc 수
int n, m; //a 크기, b 크기
pair<bool, int> base = { 0, 0 };

pair<bool, int> arr[40001];
//a/b 여부, 숫자

int res = 0;

bool cmp(pair<bool, int> a, pair<bool, int> b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x;
	cin >> t;
	for (int i = 0; i < t; i++) {
		res = 0;
		cin >> n >> m;
		fill(arr, arr + n + m, base);

		for (int a = 0; a < n; a++) {
			cin >> x;
			arr[a] = { 1, x };
		}
		for (int b = n; b < n + m; b++) {
			cin >> x;
			arr[b] = { 0, x };
		}

		sort(arr, arr + n + m, cmp);

		int cnt = 0;
		int st = 20001;
		for (int i = 0; i < n + m; i++) {
			if (!arr[i].first) {
				cnt++;
				st = arr[i].second;
			}
			if (arr[i].first && arr[i].second > st) {
				res += cnt;
			}
		}
		
		cout << res << '\n';
	}

	return 0;
}