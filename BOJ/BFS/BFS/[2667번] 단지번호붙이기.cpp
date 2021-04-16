#include <bits/stdc++.h>
using namespace std;

int arr[30][30];
bool vis[30][30];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> sv;
	int size = 0;
	int n;
	queue<pair<int, int>> q;
	int xx, yy;
	int cnt = 0;
	cin >> n;
	char c;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			arr[i][j] = c - '0';
		}
	}

	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			if (vis[a][b]) continue;

			if (arr[a][b] == 1) {
				q.push({ a, b });
				vis[a][b] = 1;
				cnt++;

				while (!q.empty()) {
					pair<int, int> p = q.front();
					q.pop();
					for (int w = 0; w < 4; w++) {
						xx = p.first + dx[w];
						yy = p.second + dy[w];
						if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
						if (vis[xx][yy] || arr[xx][yy] == 0) continue;

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
		cout << sv[i] << '\n';
	}
}