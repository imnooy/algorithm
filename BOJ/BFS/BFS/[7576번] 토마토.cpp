#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int arr[1002][1002];
int dis[1002][1002];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a;
	queue<pair<int, int>> q;
	int n, m;
	pair<int, int> p;
	int xx, yy;
	bool isCorrect = true;
	int ans = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) q.push({ i, j });
			if (arr[i][j] == 0) dis[i][j] = -1;
		}
	}

	while (!q.empty()) {
		p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			xx = p.x + dx[i];
			yy = p.y + dy[i];

			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if (dis[xx][yy] >= 0) continue;

			dis[xx][yy] = dis[p.x][p.y] + 1;
			q.push({ xx, yy });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dis[i][j] == -1) {
				isCorrect = false;
			}
			ans = max(ans, dis[i][j]);
		}
	}
	if(isCorrect) cout << ans;
	else cout << "-1";
}