#include <bits/stdc++.h>
using namespace std;

bool isRight(string s) {
	bool isMatch = true;
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '[') st.push(s[i]);
		else if (s[i] == ')') {
			if (!st.empty()) {
				if (st.top() == '(') st.pop();
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
				if (st.top() == '[') st.pop();
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
	return isMatch;
}

stack<string> stck;
int a;

void check() {
	if (!stck.empty() && (stck.top() != "(" && stck.top() != "[")) {
		a = stoi(stck.top());
		stck.pop();
		if (!stck.empty() && (stck.top() != "(" && stck.top() != "[")) {
			a = stoi(stck.top()) + a;
			stck.pop();
		}
		stck.push(to_string(a));
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	int sum = 0;
	
	if (isRight(s)) {
		for (int i = 0; i < s.length(); i++) {
			a = 1;
			if (s[i] == '(') stck.push("(");
			else if (s[i] == '[') stck.push("[");
			else if (s[i] == ')') {
				if (s[i - 1] == '(' && !stck.empty()) {
					stck.pop();
					stck.push("2");
					check();
				}
				else if (s[i - 1] != '(' && !stck.empty()) {
					while (stck.top() != "(") {
						a *= stoi(stck.top());
						stck.pop();
					}
					a *= 2;
					if (!stck.empty()) stck.pop();
					stck.push(to_string(a));
					check();
				}
			}
			else if (s[i] == ']') {
				if (s[i - 1] == '[' && !stck.empty()) {
					stck.pop();
					stck.push("3");
					check();
				}
				else if (s[i - 1] != '[' && !stck.empty()) {
					while (stck.top() != "[") {
						a *= stoi(stck.top());
						stck.pop();
					}
					a *= 3;
					if (!stck.empty()) stck.pop();
					stck.push(to_string(a));
					check();
				}
			}
		}
	}
	else cout << "0";

	if (!stck.empty()) cout << stck.top();
}