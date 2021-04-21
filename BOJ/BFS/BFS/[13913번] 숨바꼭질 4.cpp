#include <bits/stdc++.h>
using namespace std;

int arr[200001];
bool vis[200001];
int dis[200001];
int road[200001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	queue<int> q;
	int a;
	vector<int> v;

	cin >> n >> k;

	if (n == k) {
		cout << "0" << '\n';
		cout << n;
		return 0;
	}

	if (n > k) {
		cout << n - k << '\n';
		for (int i = n; i >= k; i--) cout << i << " ";
		return 0;
	}

	q.push(n);
	vis[n] = 1;
	dis[n] = 0;

	while (dis[k] == 0) {
		a = q.front();
		q.pop();

		if (a < 0 || a > 100000) continue;

		if (!vis[a - 1]) {
			dis[a - 1] = dis[a] + 1;
			road[a - 1] = a;
			vis[a - 1] = 1;
			q.push(a - 1);
		}

		if (!vis[a + 1]) {
			dis[a + 1] = dis[a] + 1;
			vis[a + 1] = 1;
			road[a + 1] = a;
			q.push(a + 1);
		}

		if (!vis[2 * a]) {
			dis[2 * a] = dis[a] + 1;
			vis[2 * a] = 1;
			road[2 * a] = a;
			q.push(2 * a);
		}
	}
	cout << dis[k] << '\n';
	int res = k;
	while (res != n) {
		v.push_back(road[res]);
		res = road[res];
	}
	for (auto ir = v.rbegin(); ir != v.rend(); ++ir)
		cout << *ir << " ";
	cout << k;
}