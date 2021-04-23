#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

bool light[103][103];
bool vis[103][103];
bool newvis[103][103];
vector<pair<int, int>> v[103][103];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int n, m;
int xx, yy;
queue<pair<int, int>> q;
pair<int, int> p;
vector<pair<int, int>>::iterator iter;

bool bfs() {
	bool ischanged = false;

	while (!q.empty()) {
		p = q.front();
		q.pop();

		if (!newvis[p.x][p.y] && v[p.x][p.y].size() != 0) {
			for (iter = v[p.x][p.y].begin(); iter != v[p.x][p.y].end(); iter++) {
				light[iter->first][iter->second] = 1;
			}
			newvis[p.x][p.y] = 1;
			ischanged = true;
		}

		for (int i = 0; i < 4; i++) {
			xx = p.x + dx[i];
			yy = p.y + dy[i];

			if (xx<1 || xx>n || yy<1 || yy>n) continue;
			if (vis[xx][yy]) continue;

			if (light[xx][yy]) {
				q.push({ xx, yy });
				vis[xx][yy] = 1;
			}
		}
	}
	return ischanged;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int x1, y1, x2, y2;
	int cnt = 0;

	cin >> n >> m;

	light[1][1] = 1;
	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		v[x1][y1].push_back({ x2, y2 });
	}

	while (1) {
		q.push({ 1, 1 });
		vis[1][1] = 1;
		fill(&vis[0][0], &vis[102][103], 0);
		if (!bfs()) break;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (light[i][j]) cnt++;
		}
	}
	cout << cnt;
}