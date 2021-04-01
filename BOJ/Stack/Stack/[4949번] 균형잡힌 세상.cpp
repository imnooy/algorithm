#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool isMatch = true;
	string s;
	

	while(1) {
		isMatch = true;
		stack<char> st;
		getline(cin, s);
		if (s == ".") break;
		for (int i = 0; i < s.length(); i++) {
			if (i == s.length() - 1 && s[i] == '.') {
				break;
			}
			else if (s[i] == '(' || s[i] == '[') st.push(s[i]);
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

		if (isMatch) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
}