#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

char arr[1001][1001];
bool vis[1001][1001];
int dis[1001][1001];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char ch;
	int fs, js;
	queue<pair<int, int>> frq;
	queue<pair<int, int>> jhq;
	int r, c;
	pair<int, int> jhp;
	pair<int, int> frp;
	int distance;
	int xx, yy;
	bool isPossible = false;

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> ch;
			arr[i][j] = ch;
			if (ch == 'F') frq.push({ i, j });
			if (ch == 'J') {
				jhq.push({ i, j });
				vis[i][j] = true;
				dis[i][j] = 0;
			}
		}
	}

	while (!jhq.empty()) {
		if (!frq.empty()) {
			fs = frq.size();
			for (int k = 0; k < fs; k++) {
				frp = frq.front();
				frq.pop();
				for (int i = 0; i < 4; i++) {
					xx = frp.x + dx[i];
					yy = frp.y + dy[i];

					if (xx < 0 || xx >= r || yy < 0 || yy >= c) continue;
					if (arr[xx][yy] == '#' || arr[xx][yy] == 'F') continue;

					if (arr[xx][yy] == '.') {
						frq.push({ xx, yy });
						arr[xx][yy] = 'F';
					}
				}
			}
		}

		js = jhq.size();
		for (int k = 0; k < js; k++) {
			jhp = jhq.front();
			jhq.pop();

			for (int i = 0; i < 4; i++) {
				xx = jhp.x + dx[i];
				yy = jhp.y + dy[i];

				if (arr[xx][yy] == 'F' || arr[xx][yy] == '#') continue;

				//탈출할 때 처리
				if (xx < 0 || xx >= r || yy < 0 || yy >= c) {
					isPossible = true;
					distance = dis[jhp.x][jhp.y];
					break;
				}

				if (arr[xx][yy] == '.') {
					if (vis[xx][yy]) {
						dis[xx][yy] = min(dis[xx][yy], dis[jhp.x][jhp.y] + 1);
					}
					else { //!vis[xx][yy]
						vis[xx][yy] = 1;
						dis[xx][yy] = dis[jhp.x][jhp.y] + 1;
						jhq.push({ xx, yy });
					}
				}
			}
			if (isPossible) break;
		}
		if (isPossible) break;
	}
	
	//출력
	if (isPossible) cout << distance + 1;
	else cout << "IMPOSSIBLE";
}