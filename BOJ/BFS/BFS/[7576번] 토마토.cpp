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

	queue<pair<int, int>> q;
	int m, n;
	pair<int, int> p;
	int xx, yy;
	bool isCorrect = true;

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push({ i, j });
				dis[i][j] = 1;
			}
			if (arr[i][j] == -1) dis[i][j] = -1;
		}
	}


	while (!q.empty()) {
		p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			xx = p.x + dx[i];
			yy = p.y + dy[i];

			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if (dis[xx][yy] == -1) continue;

			if (dis[xx][yy] > 0) {
				dis[xx][yy] = min(dis[xx][yy], dis[p.x][p.y] + 1);
			}
			else if (dis[xx][yy] == 0) {
				dis[xx][yy] = dis[p.x][p.y] + 1;
				q.push({ xx, yy });
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dis[i][j] == 0) isCorrect = false;
			ans = max(ans, dis[i][j]);
		}
	}

	if (isCorrect) cout << ans - 1;
	else cout << "-1";
}