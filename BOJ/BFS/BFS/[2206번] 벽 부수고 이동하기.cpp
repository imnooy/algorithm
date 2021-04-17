#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int dis[1001][1001][2]; //마지막 2는 벽 뚫기 여부
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int main()
{
	int n, m;
	cin >> n >> m;
	char c;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			arr[i][j] = c - '0';
		}
	}

	queue<pair<pair<int, int>, int>> q;
	pair<pair<int, int>, int> p;

	q.push({ {0, 0}, 0 }); //벽 아직 안뚫음

	dis[0][0][0] = 1;

	while (!q.empty()) {
		p = q.front();
		q.pop();

		int y = p.first.first;
		int x = p.first.second;
		int isBreak = p.second;

		if (y == n - 1 && x == m - 1) {
			cout << dis[y][x][isBreak];
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;

			if (arr[yy][xx] == 1 && isBreak == 0) {//벽이 있고 아직 안부쉈을 때
				dis[yy][xx][1] = dis[y][x][0] + 1;
				q.push({ { yy, xx }, 1 });
			}
			else if (arr[yy][xx] == 0 && dis[yy][xx][isBreak] == 0) { //벽이 없고 방문 안했을 때
				dis[yy][xx][isBreak] = dis[y][x][isBreak] + 1;
				q.push({ { yy, xx }, isBreak });
			}
		}
	}

	cout << "-1";
}