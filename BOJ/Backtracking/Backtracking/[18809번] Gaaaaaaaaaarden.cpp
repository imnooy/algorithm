#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, g, r;
int arr[53][53];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

queue<pair<int, int>> g_q;
queue<pair<int, int>> r_q;

pair<int, int> vis[53][53];

//first
// 0 : �湮 x
// 1 : �ʷϻ� ���� �湮 �� (g)
// 2 : ������ ���� �湮 �� (r)
// 3 : �� 

//second : �ð�


int g_arr[11];
int r_arr[11];

pair<int, int> def = { 0, 0 };

int maximum = 0;

vector<pair<int, int>> cm; //���� ��ǥ ����
vector<pair<int, int>> res;

vector<int> flowers;

int g_cnt = 0;
int r_cnt = 0;

int sec = 1;

bool check[11];

void bfs() {
	int cnt = 0;
	while (!g_q.empty() && !r_q.empty()) {
		if (!g_q.empty()) {
			int g_size = g_q.size();
			for (int i = 0; i < g_size; i++) {
				pair<int, int> g_cur = g_q.front();
				g_q.pop();
				if (vis[g_cur.X][g_cur.Y].X == 3) continue;

				for (int dir = 0; dir < 4; dir++) {
					int nx = g_cur.X + dx[dir];
					int ny = g_cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny].X == 1 || vis[nx][ny].X == 3 || arr[nx][ny] == 0) continue;
					if (vis[nx][ny].X == 2 && vis[nx][ny].Y != sec) //�ʷϻ� �����ε� ���ÿ� ������ ���� ��
						continue;

					if (vis[nx][ny].X == 1 && vis[nx][ny].Y == sec) { // ���� ���� ������ ��
						vis[nx][ny].X = 3;
						cnt++;
						continue;
					}

					vis[nx][ny].X = 1;
					vis[nx][ny].Y = sec;
					g_q.push({ nx, ny });
				}
			}
		}

		if (!r_q.empty()) {
			int r_size = r_q.size();
			for (int i = 0; i < r_size; i++) {
				pair<int, int> r_cur = r_q.front();
				r_q.pop();
				if (vis[r_cur.X][r_cur.Y].X == 3) continue;

				for (int dir = 0; dir < 4; dir++) {
					int nx = r_cur.X + dx[dir];
					int ny = r_cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //���� üũ
					if (vis[nx][ny].X == 2 || vis[nx][ny].X == 3 || arr[nx][ny] == 0) //�̹� ������ ������ �ְų� ���� ���, ���� ȣ���� ���
						continue;
					if (vis[nx][ny].X == 1 && vis[nx][ny].Y != sec) //�ʷϻ� �����ε� ���ÿ� ������ ���� ��
						continue;

					if (vis[nx][ny].X == 1 && vis[nx][ny].Y == sec) { // �ʷϻ� ���� ������ ��
						vis[nx][ny].X = 3;
						cnt++;
						continue;
					}

					vis[nx][ny].X = 2;
					vis[nx][ny].Y = sec;
					r_q.push({ nx, ny });
				}
			}
		}
		sec++;
	}
	maximum = max(maximum, cnt);
}

int main() {
	cin >> n >> m >> g >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				cm.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < g; i++) g_arr[i] = 0;
	for (int i = 0; i < r; i++) r_arr[i] = 0;

	for (int i = g; i < cm.size(); i++) g_arr[i] = 1;
	for (int i = r; i < cm.size(); i++) r_arr[i] = 1;


	//arr[i][j]���� 2�� �� ����

	do {
		for (int i = 0; i < cm.size(); i++) {
			if (g_arr[i] == 0) {
				res.push_back(cm[i]);
				check[i] = 1;
				g_cnt++;
			}
		}

		do {
			for (int j = 0; j < cm.size(); j++) {
				if (r_arr[j] == 0 && !check[j]) {
					res.push_back(cm[j]);
					r_cnt++;
				}
			}

			if (r_cnt != r) {
				res.erase(res.begin() + g, res.begin() + g + r_cnt);
			}

			if (g_cnt == g && r_cnt == r) { //���⼭ �� �ǿ�� ����
				
				/*for (int k = 0; k < g; k++) {
					cout << "(g): (" << res[k].first << ", " << res[k].second << ") ";
				}

				for (int k = g; k < res.size(); k++) {
					cout << "(r): (" << res[k].first << ", " << res[k].second << ") ";
				}
				cout << '\n';*/

				for (int k = 0; k < g; k++) {
					vis[res[k].first][res[k].second].X = 1;
					vis[res[k].first][res[k].second].Y = 0; //�ð�
					g_q.push(res[k]);
				}

				for (int k = g; k < res.size(); k++) {
					vis[res[k].first][res[k].second].X = 2;
					vis[res[k].first][res[k].second].Y = 0; //�ð�
					r_q.push(res[k]);
				}

				bfs(); //bfs ����

				fill(&vis[0][0], &vis[52][53], def);
				g_q = queue<pair<int, int>>();
				r_q = queue<pair<int, int>>(); //�ʱ�ȭ

				res.erase(res.begin() + g, res.begin() + g + r);
			}
			r_cnt = 0;
		} while (next_permutation(r_arr, r_arr + cm.size()));

		res.clear();
		g_cnt = 0;
		fill(check, check + cm.size(), 0);
	} while (next_permutation(g_arr, g_arr + cm.size()));

	cout << maximum;

	return 0;
}