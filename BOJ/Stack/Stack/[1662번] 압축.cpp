#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;

	cin >> s;

	stack<pair<char, int>> st;
	
	for (int i = 0; i < s.length(); i++) {
		int cnt = 0;
		if (s[i] == ')') {
			if (!st.empty()) {
				while (st.top().first != '(') {
					if (st.top().second == -1) cnt++;
					else cnt += st.top().second;
					st.pop();
				}
				st.pop();

				if (!st.empty()) {
					if (st.top().first != '(' && st.top().first != ')') {
						int a = st.top().first - '0';
						st.top().second = a * cnt;
					}
				}
			}
		}
		else {
			st.push({ s[i], -1 });
		}
	}

	int ct = 0;
	while (!st.empty()) {
		if (st.top().second == -1) ct++;
		else ct += st.top().second;
		st.pop();
	}
	cout << ct;
}