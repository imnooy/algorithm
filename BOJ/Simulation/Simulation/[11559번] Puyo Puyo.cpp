#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char arr[12][6];
bool vis[12][6];

queue<pair<int, int>> q;
bool check[12][6]; //터뜨림 여부 체크

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs(char c) { //한 그룹 찾기
	vector<pair<int, int>> vec;
	int cnt = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		vec.push_back(cur);
		cnt++;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx > 11 || ny < 0 || ny > 5) continue;
			if (arr[nx][ny] != c || vis[nx][ny] == 1) continue;

			vis[nx][ny] = 1;
			q.push({ nx, ny });

		}
	}

	fill(&vis[0][0], &vis[11][6], 0);

	if (cnt >= 4) { //4개 이상 모여있으면 터뜨리기
		for (int i = 0; i < vec.size(); i++) { 
			check[vec[i].X][vec[i].Y] = 1;
			arr[vec[i].X][vec[i].Y] = '0';
		}
		return 1;
	}

	else return 0;
}

void arr_down() { //터졌으면 밑으로 
	for (int i = 11; i >= 0; i--) { //제일 밑줄에서부터 윗줄 탐색
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] == '0') {
				for (int k = i - 1; k >= 0; k--) { //0인 칸의 윗 줄 보기
					if (arr[k][j] != '0' && arr[k][j] != '.') {
						swap(arr[k][j], arr[i][j]);
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] != '.' && arr[i][j] == '0')
				arr[i][j] = '.';
		}
	}

}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}
	int res = 0; //연쇄
	int bomb = 0; //색깔마다 터진 횟수

	while (1) {
		bomb = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] == '.') continue;
				if (check[i][j]) continue; //이미 터졌으면 지나감

				else {
					q.push({ i, j });
					vis[i][j] = 1;
					bomb += bfs(arr[i][j]); //한 그룹 찾기
					q = queue<pair<int, int>>(); //큐 초기화
				}
			}
		}
		if (bomb == 0) break;
		else {
			res++;
			arr_down();
			fill(&check[0][0], &check[11][6], 0);
		}
	}

	cout << res;

	return 0;
}