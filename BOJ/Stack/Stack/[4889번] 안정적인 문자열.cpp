#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool isMatch = true;
	string s;
	int cnt = 0;
	int number = 1;

	while (1) {
		cnt = 0;
		isMatch = true;
		stack<char> st;
		cin >> s;
		if (s.find("-") != string::npos) break;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '{') st.push(s[i]);

			else if (s[i] == '}') {
				if (!st.empty()) {
					if (st.top() == '{') {
						st.pop();
					}
					else {
						isMatch = false;
						st.push(s[i]);
					}
				}
				else {
					isMatch = false;
					st.push('{');
					cnt++;
				}
			}
		}
		if (!st.empty()) isMatch = false;

		std::cout << number << ". ";

		if (isMatch) std::cout << "0" << '\n';
		else std::cout << cnt + st.size() / 2 << '\n';

		number++;
	}
}