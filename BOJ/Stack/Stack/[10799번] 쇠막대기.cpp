#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<char> st;
	string s;
	char ch;
	int sum = 0;

	cin >> s;
	for (auto c : s) {
		if (c == '(') st.push(c);
		else if (c == ')') {
			if (!st.empty() && ch == '(') {
				st.pop();
				sum += st.size();
			}
			else {
				if (!st.empty()) {
					st.pop();
					sum += 1;
				}
			}
		}
		ch = c;
	}

	cout << sum;
}