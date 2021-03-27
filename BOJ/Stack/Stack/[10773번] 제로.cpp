#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<int> st;
	int sum = 0;
	int n, a;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) {
			if (!st.empty()) st.pop();
		}
		else st.push(a);
	}

	while(!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum;
}