#include <bits/stdc++.h>
using namespace std;

char arr[31][31][31];
bool vis[31][31][31];
int dis[31][31][31];

int dz[6] = { 0, 0, 0, 0, 1, -1 };
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int l, r, c;
	char ch;
	int xx, yy, zz;

	while (1) {
		fill(dis[0][0], dis[31][0], 0);
		fill(vis[0][0], vis[31][0], 0);
		queue <pair<int, pair<int, int>>> q;
		pair<int, pair<int, int>> p;
		bool isEnd = true;

		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0) break;

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> ch;
					arr[i][j][k] = ch;
					if (ch == 'S') {
						q.push({ i, {j, k} });
						vis[i][j][k] = 1;
						dis[i][j][k] = 0;
					}
				}
			}
		}

		while (!q.empty()) {
			p = q.front();
			q.pop();

			if (arr[p.first][p.second.first][p.second.second] == 'E') {
				cout << "Escaped in " << dis[p.first][p.second.first][p.second.second] << " minute(s)." << '\n';
				isEnd = false;
				break;
			}

			for (int i = 0; i < 6; i++) {
				zz = p.first + dz[i];
				xx = p.second.first + dx[i];
				yy = p.second.second + dy[i];

				if (zz < 0 || zz >= l || xx < 0 || xx >= r || yy < 0 || yy >= c) continue;
				if (vis[zz][xx][yy]) continue;
				if (arr[zz][xx][yy] == '#') continue;

				q.push({ zz, {xx, yy} });
				vis[zz][xx][yy] = 1;
				dis[zz][xx][yy] = dis[p.first][p.second.first][p.second.second] + 1;

			}
		}
		if(isEnd) cout << "Trapped!" << '\n';
	}
}