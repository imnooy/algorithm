#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int arr[102][102];
bool vis[102][102];
int dis[102][102];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char c;
	int a;
	queue<pair<int, int>> q;
	int n, m;
	pair<int, int> p;
	int distance;
	int xx, yy;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			arr[i][j] = c - '0';
		}
	}

	q.push({ 0, 0 });
	vis[0][0] = 1;
	distance = 0;
	dis[0][0] = distance;
	
	while (!q.empty()) {
		p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				xx = p.x + dx[i];
				yy = p.y + dy[i];

				if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
				if (!arr[xx][yy]) continue;

				if (arr[xx][yy] && vis[xx][yy]) {
					dis[xx][yy] = min(dis[xx][yy], dis[p.x][p.y] + 1);
				}
				else if(arr[xx][yy] && !vis[xx][yy]) {
					vis[xx][yy] = 1;
					dis[xx][yy] = dis[p.x][p.y] + 1;
					q.push({ xx, yy });
				}
			}
		}
	}
	cout << dis[n - 1][m - 1] + 1;
}