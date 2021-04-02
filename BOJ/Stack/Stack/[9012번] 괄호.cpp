#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool isMatch = true;
	string s;
	int n;
	cin >> n;

	for(int k = 0; k < n; k++) {
		isMatch = true;
		stack<char> st;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[') st.push(s[i]);
			else if (s[i] == ')') {
				if (!st.empty()) {
					if (st.top() == '(') {
						st.pop();
					}
					else {
						isMatch = false;
						break;
					}
				}
				else {
					isMatch = false;
					break;
				}
			}
			else if (s[i] == ']') {
				if (!st.empty()) {
					if (st.top() == '[') {
						st.pop();
					}
					else {
						isMatch = false;
						break;
					}
				}
				else {
					isMatch = false;
					break;
				}
			}
		}
		if (!st.empty()) isMatch = false;

		if (isMatch) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}