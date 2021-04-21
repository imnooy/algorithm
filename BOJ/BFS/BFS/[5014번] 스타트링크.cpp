#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
bool vis[1000001];
int dis[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int f, s, g, u, d;
	queue<int> q;
	int a;

	cin >> f >> s >> g >> u >> d;

	if (s == g) {
		cout << "0";
		return 0;
	}

	q.push(s);
	vis[s] = 1;
	dis[s] = 0;

	while (!q.empty()) {
		a = q.front();
		q.pop();

		if (a == g) {
			cout << dis[g];
			return 0;
		}

		if ((a + u <= f) && !vis[a + u]) { //처음 방문
			dis[a + u] = dis[a] + 1;
			vis[a + u] = 1;
			q.push(a + u);
		}

		if ((a - d > 0) && !vis[a - d]) {
			dis[a - d] = dis[a] + 1;
			vis[a - d] = 1;
			q.push(a - d);
		}
	}
	cout << "use the stairs";
}