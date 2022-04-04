#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int cnt[1001];
int pre[1001];

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	fill(cnt, cnt + 1001, 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] && cnt[i] < cnt[j] + 1) {
				cnt[i] = cnt[j] + 1;
				pre[i] = j;
			}
		}
	}
	int cur = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < cnt[i]) {
			ans = cnt[i];
			cur = i;
		}
	}
	cout << ans << '\n';
	vector<int> vec;
	for (int i = cur; i != 0; i = pre[i]) {
		vec.push_back(arr[i]);
	}

	for (auto i = vec.rbegin(); i != vec.rend(); ++i) {
		cout << *i << " ";
	}
	return 0;
}