#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define z third

int arr[102][102][102];
int dis[102][102][102];

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<tuple<int, int, int>> q;
	int m, n, h;
	tuple<int, int, int> t;
	int xx, yy, zz;
	bool isCorrect = true;
	bool allRiped = true;

	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push({ i, j, k });
					dis[i][j][k] = 1;
				}
				if (arr[i][j][k] == -1) dis[i][j][k] = -1;
				if (arr[i][j][k] == 0) allRiped = false;
			}
		}
	}

	if (allRiped) {
		cout << "0";
		return 0;
	}
	

	while (!q.empty()) {
		t = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			xx = dx[i] + get<0>(t);
			yy = dy[i] + get<1>(t);
			zz = dz[i] + get<2>(t);

			if (xx < 0 || xx >= h || yy < 0 || yy >= n || zz < 0 || zz >= m) continue;
			if (dis[xx][yy][zz] == -1) continue;

			if (dis[xx][yy][zz] > 0) {
				dis[xx][yy][zz] = min(dis[xx][yy][zz], dis[get<0>(t)][get<1>(t)][get<2>(t)] + 1);
			}
			else if (dis[xx][yy][zz] == 0) {
				dis[xx][yy][zz] = dis[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
				q.push({ xx, yy, zz });
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dis[i][j][k] == 0) isCorrect = false;
				ans = max(ans, dis[i][j][k]);
			}
		}
	}

	if (isCorrect) cout << ans - 1;
	else cout << "-1";
}