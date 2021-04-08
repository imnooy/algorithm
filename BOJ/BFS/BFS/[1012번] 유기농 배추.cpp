#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int arr[51][51];
bool vis[51][51];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, m, k;
	int a, b;
	int xx, yy;
	pair<int, int> p;
	queue<pair<int, int>> q;
	int cnt;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cnt = 0;
		fill(arr[0], arr[0] + 2601, 0);
		fill(vis[0], vis[0] + 2601, 0);
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			cin >> a >> b;
			arr[b][a] = 1;
		}

		for (int nn = 0; nn < n; nn++) {
			for (int mm = 0; mm < m; mm++) {
				if (arr[nn][mm] == 1 && !vis[nn][mm]) {
					cnt++;
					q.push({ nn, mm });
					vis[nn][mm] = 1;

					while (!q.empty()) {
						p = q.front();
						q.pop();

						for (int d = 0; d < 4; d++) {
							xx = p.x + dx[d];
							yy = p.y + dy[d];

							if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
							if (vis[xx][yy] || !arr[xx][yy]) continue;

							vis[xx][yy] = 1;
							q.push({ xx, yy });
						}
					}
				}
			}
		}
		cout << cnt << '\n';
	}
}