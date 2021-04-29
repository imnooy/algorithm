#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n;
int arr[101][101];
int vis[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs(int num) {
	queue<pair<int, int>> q1;
	pair<int, int> p1;
	int xx, yy;
	int qsize;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == num) {
				q1.push({ i, j });
				vis[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	while (!q1.empty()) {
		qsize = q1.size();
		for (int i = 0; i < qsize; i++) {
			p1 = q1.front();
			q1.pop();
			for (int k = 0; k < 4; k++) {
				xx = p1.x + dx[k];
				yy = p1.y + dy[k];
				if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
				if (vis[xx][yy]) continue;
				if (arr[xx][yy] != 0 && arr[xx][yy] != num) {
					return cnt;
				}
				if (arr[xx][yy] == 0) {
					vis[xx][yy] = 1;
					q1.push({ xx, yy });

				}
			}
		}
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, pair<int, int>>> q;
	pair<int, pair<int, int>> p;
	vector<int> v;
	int zz;
	int xx, yy;
	int num = 1;
	int cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) continue;
			if (vis[i][j] != 0) continue;

			q.push({ num, {i, j} });
			arr[i][j] = num;
			vis[i][j] = 1;

			while (!q.empty()) {
				p = q.front();
				q.pop();
				int a = 0;

				zz = p.x;

				for (int k = 0; k < 4; k++) {
					xx = p.y.x + dx[k];
					yy = p.y.y + dy[k];

					if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
					if (vis[xx][yy] != 0) continue;

					if (arr[xx][yy] == 1) {
						q.push({ zz, {xx, yy} });
						vis[xx][yy] = 1;
						arr[xx][yy] = num;
					}
				}
			}
			num++;
		}
	}
	//cout << num;
	int m = 10000;
	for (int i = 1; i <= num - 1; i++) {
		fill(&vis[0][0], &vis[100][101], 0);
		m=min(m, bfs(i));
	}

	cout << m;
	
	//cout << arr[0][0];
}