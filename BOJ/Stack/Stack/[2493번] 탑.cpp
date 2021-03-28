#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a;
	stack<pair<int, int>> st;

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a;
		while (!st.empty()) {
			if (st.top().second < a) {
				st.pop();
			}
			else {
				cout << st.top().first << " ";
				break;
			}
		}
		if (st.empty()) {
			cout << 0 << " ";
		}

		st.push(make_pair(i, a));
	}

}