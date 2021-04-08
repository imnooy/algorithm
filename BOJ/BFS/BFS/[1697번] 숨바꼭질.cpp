#include <bits/stdc++.h>
using namespace std;

int arr[200001];
bool vis[200001];
int dis[200001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	queue<int> q;
	int a;

	cin >> n >> k;

	if (n == k) {
		cout << "0";
		return 0;
	}

	q.push(n);
	vis[n] = 1;
	dis[n] = 0;

	while (dis[k] == 0) {
		a = q.front();
		q.pop();

		if (a < 0 || a>100000) continue;

		if (!vis[a - 1]) { //처음 방문
			dis[a - 1] = dis[a] + 1;
			vis[a - 1] = 1;
			q.push(a - 1);
		}

		if (!vis[a + 1]) {
			dis[a + 1] = dis[a] + 1;
			vis[a + 1] = 1;
			q.push(a + 1);
		}

		if (!vis[2 * a]) {
			dis[2 * a] = dis[a] + 1;
			vis[2 * a] = 1;
			q.push(2 * a);
		}
	}
	cout << dis[k];
}