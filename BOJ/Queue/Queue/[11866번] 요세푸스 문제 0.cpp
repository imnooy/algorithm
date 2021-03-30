#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	vector<int> v;
	int n, k, a;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) q.push(i);

	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			a = q.front();
			q.pop();
			q.push(a);
		}
		v.push_back(q.front());
		q.pop();
	}

	cout << "<";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1) cout << ", ";
	}
	cout << ">";
}