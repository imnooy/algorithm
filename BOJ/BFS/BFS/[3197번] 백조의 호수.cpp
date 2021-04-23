#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

char arr[1501][1501];
bool vis[1501][1501];

queue<pair<int, int>> lq;
queue<pair<int, int>> lq1;

queue<pair<int, int>> wq;

vector<pair<int, int>> v;

int n, m;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


void melt() {
	int xx, yy;
	pair<int, int> wp;

	int s = wq.size();

	while (s > 0) {
		wp = wq.front();
		wq.pop();
		s--;

		for (int i = 0; i < 4; i++) {
			xx = wp.x + dx[i];
			yy = wp.y + dy[i];

			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if (arr[xx][yy] == 'X') {
				wq.push({ xx, yy });
				arr[xx][yy] = '.';
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char ch;
	int count = 0;
	pair<int, int> lp;
	int xx, yy;
	int l;
	bool isend = false;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ch;
			arr[i][j] = ch;
			if (ch == 'L') {
				v.push_back({ i, j });
			}
			if (ch != 'X') {
				wq.push({ i, j });
			}
		}
	}

	lq.push(v[0]);
	vis[v[0].x][v[0].y] = 1;

	while (1) {
		while (!lq.empty()) {
			lp = lq.front();
			lq.pop();

			if (lp.x == v[1].x && lp.y == v[1].y) {
				isend = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				xx = lp.x + dx[i];
				yy = lp.y + dy[i];

				if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
				if (vis[xx][yy]) continue;
				if (arr[xx][yy] == 'X') {
					lq1.push({ xx, yy });
				}
				else lq.push({ xx, yy });

				vis[xx][yy] = 1;
			}
		}

		if (isend) break;

		lq = lq1;
		while (!lq1.empty()) lq1.pop();

		melt();
		count++;
	}
	cout << count;
}