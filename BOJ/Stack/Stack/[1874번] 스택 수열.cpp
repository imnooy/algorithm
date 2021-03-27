#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> st, st1;
	vector<int> v;
	int n, a, max, max1;
	string s = "";

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	for (int i = n - 1; i >= 0; i--) st.push(v[i]);

	if(!st.empty()) max = st.top();

	for (int i = 1; i <= st.top(); i++) {
		st1.push(i);
		s += "+";
	}

	v.clear();

	while (!st.empty()) {
		if (!st1.empty()) max1 = st1.top();
		if (st.top() == max1) {
			if (st.top() > max) max = st.top();
			st.pop();
			st1.pop();
			s += "-";
		}
		else if (st.top() > max1) {
			for (int i = max + 1; i <= st.top(); i++) {
				st1.push(i);
				s += "+";
			}
			max = st.top();
		}
		else {
			s = "NO";
			break;
		}
	}
	if (s != "NO") {
		for (auto c : s) cout << c << '\n';
	}
	else cout << s << '\n';

}