#include <bits/stdc++.h>
using namespace std;

int main() {
	string input;
	cin >> input;
	stack<char>st;

	int tmp = 1;
	int sum = 0;

	bool flag = true;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') {
			tmp *= 2;
			st.push('(');
		}
		else if (input[i] == '[') {
			tmp *= 3;
			st.push('[');
		}
		else if (input[i] == ')') {
			if (st.empty()) {
				flag = false;
				break;
			}
			else if (st.top() == '(') {
				if (input[i - 1] == '(') {
					sum += tmp;
				}
				st.pop();
				tmp /= 2;	
			}
			else {
				flag = false;
				break;
			}
		}
		else if (input[i] == ']') {
			if (st.empty()) {
				flag = false;
				break;
			}
			else if (st.top() == '[') {
				if (input[i - 1] == '[') {
					sum += tmp;
				}
				st.pop();
				tmp /= 3;
			}
			else {
				flag = false;
				break;
			}
		}
	}

	if (!flag || !st.empty()) {
		cout << 0;
		return 0;
	}

	cout << sum;

	return 0;
}