#include <bits/stdc++.h>
using namespace std;

int hx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int hy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int arr[201][201];
bool vis[31][201][201];
int dis[31][201][201];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, h, w;
	int xx, yy;
	int kk;
	queue<pair<int, pair<int, int>>> q;
	pair<int, pair<int, int>> p;
	cin >> k;
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
		}
	}

	q.push({ 0, {0, 0} });
	vis[0][0][0] = 1;

	while (!q.empty()) {
		p = q.front();
		q.pop();
		kk = p.first;

		if (p.second.first == h - 1 && p.second.second == w - 1) {
			cout << dis[kk][p.second.first][p.second.second];
			return 0;
		}

		if (kk < k) {
			for (int i = 0; i < 8; i++) {
				xx = p.second.first + hx[i];
				yy = p.second.second + hy[i];

				if (xx < 0 || xx >= h || yy < 0 || yy >= w) continue;
				if (arr[xx][yy] == 1) continue;
				if (vis[kk + 1][xx][yy]) continue;

				q.push({ kk + 1, {xx, yy} });
				vis[kk + 1][xx][yy] = 1;
				dis[kk + 1][xx][yy] = dis[kk][p.second.first][p.second.second] + 1;
			}
		}
		for (int i = 0; i < 4; i++) {
			xx = p.second.first + dx[i];
			yy = p.second.second + dy[i];

			if (xx < 0 || xx >= h || yy < 0 || yy >= w) continue;
			if (vis[kk][xx][yy]) continue;
			if (arr[xx][yy] == 1) continue;

			q.push({ kk, {xx, yy} });
			vis[kk][xx][yy] = 1;
			dis[kk][xx][yy] = dis[kk][p.second.first][p.second.second] + 1;
		}
	}

	cout << "-1";
}