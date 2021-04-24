#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int arr[1001][1001];
bool vis[1001][1001];
int res[10];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
pair<int, int> players[10];
queue<pair<int, int>> q[10];
pair<int, int> p;

int n, m, player;

bool bfs(int num, int many) { //라운드 진행
	int xx, yy;
	int qsize;

	for (int i = 0; i < many; i++) {
		if (q[num].empty()) {
			return true;
		}
		else {
			qsize = q[num].size();
			for (int j = 0; j < qsize; j++) {
				p = q[num].front();
				q[num].pop();

				for (int k = 0; k < 4; k++) {
					xx = p.x + dx[k];
					yy = p.y + dy[k];

					if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
					if (vis[xx][yy]) continue;
					if (arr[xx][yy] == '#') continue;

					q[num].push({ xx, yy });
					vis[xx][yy] = 1;
					res[num]++;
				}
			}
		}
	}
	return false;
}

bool round() { //라운드 돌리기
	bool isend = true;
	for (int i = 1; i <= player; i++) {
		if (!bfs(players[i].first, players[i].second)) {
			isend = false;
		}
	}
	return isend;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tmp;
	char ch;

	cin >> n >> m >> player;
	for (int i = 1; i <= player; i++) {
		cin >> tmp;
		players[i] = { i, tmp };
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> ch;
			arr[i][j] = ch;
			if (ch != '#' && ch != '.') {
				q[ch - '0'].push({ i, j });
				vis[i][j] = 1;
				res[ch - '0']++;
			}
		}
	}

	while (1) {
		if (round()) break;
	}

	for (int i = 1; i <= player; i++) cout << res[i] << " ";
}