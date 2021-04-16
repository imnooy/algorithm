#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int arr[304][304];
bool vis[304][304];
int dis[304][304];

int dx[8] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dy[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	pair <int, int> p;
	int n, h;
	int x1, y1, x2, y2;
	int xx, yy;

	cin >> n;

	for (int w = 0; w < n; w++) {
		queue<pair<int, int>> q;
		fill(&arr[0][0], &arr[303][304], 0);
		fill(&vis[0][0], &vis[303][304], 0);
		fill(&dis[0][0], &dis[303][304], 0);
		cin >> h;
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 == x2 && y1 == y2) {
			cout << "0" << '\n';
			continue;
		}

		q.push({ x1, y1 });
		vis[x1][y1] = 1;

		while (!q.empty()) {

			p = q.front();
			q.pop();

			for (int i = 0; i < 8; i++) {
				xx = p.x + dx[i];
				yy = p.y + dy[i];

				if (xx < 0 || xx >= h || yy < 0 || yy >= h) continue;
				if (vis[xx][yy]) continue;

				vis[xx][yy] = 1;
				q.push({ xx, yy });
				if (dis[xx][yy] > 0) dis[xx][yy] = min(dis[xx][yy], dis[p.x][p.y] + 1);
				else dis[xx][yy] = dis[p.x][p.y] + 1;	
			}		
		}	
		cout << dis[x2][y2] << '\n';
	}


}