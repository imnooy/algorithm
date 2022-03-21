#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int arr[12][12];
int start[12][12];
bool vis[12][12];
int n, m;
int res = 0;

int a[144];

pair<int, int> emarr[144];
queue<pair<int, int>> virus;

void clr() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) sum++;
			arr[i][j] = start[i][j];
			if (start[i][j] == 2) {
				vis[i][j] = 1;
				virus.push({ i, j });
			}
			else if (start[i][j] != 2) vis[i][j] = 0;
		}
	}

	res = max(res, sum);
}

void bfs() {
	//¹ÙÀÌ·¯½º °³¼ö´Â 2º¸´Ù Å©°Å³ª °°À½
	while (!virus.empty()) {
		int qsize = virus.size();
		for (int i = 0; i < qsize; i++) {
			pair<int, int> cur = virus.front();
			virus.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (!arr[nx][ny] == 0 || vis[nx][ny]) continue;
				vis[nx][ny] = 1;
				arr[nx][ny] = 2;
				virus.push({ nx, ny });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	int index = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			start[i][j] = arr[i][j];
			if (arr[i][j] == 0) { //ºóÄ­
				emarr[index] = { i, j };
				index++; //ºóÄ­ °³¼ö
			}
			if (arr[i][j] == 2) {
				virus.push({ i, j });
				vis[i][j] = 1;
			}
		}
	}
	for (int i = 3; i < index; i++) a[i] = 1;

	do {
		for (int i = 0; i < index; i++) {
			if (a[i] == 0) {
				arr[emarr[i].first][emarr[i].second] = 1;
			}
		}
		bfs();
		clr();
	} while (next_permutation(a, a+index));

	cout << res;
	return 0;
}