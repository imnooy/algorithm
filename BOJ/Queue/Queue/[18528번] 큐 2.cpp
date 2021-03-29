#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	queue<int> q;
	string s;
	int a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> a;
			q.push(a);
		}
		else if (s == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else cout << "-1" << '\n';
		}
		else if (s == "size") {
			cout << q.size() << '\n';
		}
		else if (s == "empty") {
			if (q.empty()) cout << "1" << '\n';
			else cout << "0" << '\n';
		}
		else if (s == "front") {
			if (!q.empty()) cout << q.front() << '\n';
			else cout << "-1" << '\n';
		}
		else if (s == "back") {
			if (!q.empty()) cout << q.back() << '\n';
			else cout << "-1" << '\n';
		}
	}
}