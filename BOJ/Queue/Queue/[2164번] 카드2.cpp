#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a;
	queue<int> q;

	cin >> n;
	for (int i = 1; i <= n; i++) q.push(i);

	while (1) {
		if (q.size() == 1) {
			cout << q.front();
			break;
		}
		if (!q.empty()) {
			q.pop();
		}
		if (!q.empty()) {
			a = q.front();
			if (q.size() == 1) {
				cout << q.front();
				break;
			}
			q.pop();
		}
		q.push(a);
	}
}