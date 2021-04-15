#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
bool vis[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> sv;
	int size = 0;
	int m, n, k;
	int x1, y1, x2, y2;
	queue<pair<int, int>> q;
	int xx, yy;
	int cnt = 0;
	cin >> m >> n >> k;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = -1;
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		x2 = x2 - 1;
		y2 = y2 - 1;
		for (int a = 0; a <= x2 - x1; a++) {
			for (int b = 0; b <= y2 - y1; b++) {
				arr[x1 + a][y1 + b] = 1;
			}
		}
	}

	for (int a = 0; a < m; a++) {
		for (int b = 0; b < n; b++) {
			if (vis[a][b]) continue;

			if (arr[a][b] == -1) {
				q.push({ a, b });
				vis[a][b] = 1;
				cnt++;

				while (!q.empty()) {
					pair<int, int> p = q.front();
					q.pop();
					for (int w = 0; w < 4; w++) {
						xx = p.first + dx[w];
						yy = p.second + dy[w];
						if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
						if (vis[xx][yy] || arr[xx][yy] == 1) continue;

						vis[xx][yy] = 1;
						size++;
						q.push({ xx, yy });
					}
				}
				sv.push_back(size + 1);
				size = 0;
			}
		}
	}

	sort(sv.begin(), sv.end());
	cout << cnt << '\n';
	for (int i = 0; i < sv.size(); i++) {
		cout << sv[i] << " ";
	}
}