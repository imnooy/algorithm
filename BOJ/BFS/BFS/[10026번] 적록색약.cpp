#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

char arr[101][101];
bool vis[101][101];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int r = 0;
	int g = 0;
	int b = 0;
	int rg = 0;
	pair<int, int> p;
	int xx, yy;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	queue<pair<int, int>> q1;
	for (int i = 0; i < n; i++) { //o
		for (int j = 0; j < n; j++) {
			if (vis[i][j]) continue;

			if (arr[i][j] == 'R') r++;
			else if (arr[i][j] == 'G') g++;
			else if (arr[i][j] == 'B') b++;


			q1.push({ i, j });
			vis[i][j] = 1;

			while (!q1.empty()) {
				p = q1.front();
				q1.pop();

				for (int a = 0; a < 4; a++) {
					xx = p.x + dx[a];
					yy = p.y + dy[a];

					if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
					if (vis[xx][yy]) continue;

					if (arr[i][j] == 'R') {
						if (arr[xx][yy] == 'G' || arr[xx][yy] == 'B') continue;
					}

					else if (arr[i][j] == 'G') {
						if (arr[xx][yy] == 'R' || arr[xx][yy] == 'B') continue;
					}

					else if (arr[i][j] == 'B') {
						if (arr[xx][yy] == 'R' || arr[xx][yy] == 'G') continue;
					}

					vis[xx][yy] = 1;
					q1.push({ xx, yy });
				}
			}	
		}
	}
	int cnt = r + g + b;

	fill(&vis[0][0], &vis[100][101], 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'G') arr[i][j] = 'R';
		}
	}
	queue<pair<int, int>> q2;
	b = 0;
	for (int i = 0; i < n; i++) { //o
		for (int j = 0; j < n; j++) {
			if (vis[i][j]) continue;

			if (arr[i][j] == 'R') rg++;
			else if (arr[i][j] == 'B') b++;


			q2.push({ i, j });
			vis[i][j] = 1;

			while (!q2.empty()) {
				p = q2.front();
				q2.pop();

				for (int a = 0; a < 4; a++) {
					xx = p.x + dx[a];
					yy = p.y + dy[a];

					if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
					if (vis[xx][yy]) continue;

					if (arr[i][j] == 'R') {
						if (arr[xx][yy] == 'B') continue;
					}

					else if (arr[i][j] == 'B') {
						if (arr[xx][yy] == 'R') continue;
					}

					vis[xx][yy] = 1;
					q2.push({ xx, yy });
				}
			}
		}
	}
	cout << cnt << " " << rg + b;
}