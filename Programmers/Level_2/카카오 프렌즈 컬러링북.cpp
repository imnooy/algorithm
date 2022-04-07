#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool vis[102][102];
int cnt[102][102];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	fill(&vis[0][0], &vis[101][102], 0); //초기화
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	queue<pair<int, int>> q;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] == 0 || vis[i][j]) continue;
			q.push({ i, j });
			vis[i][j] = 1;
			number_of_area++;
			int num = picture[i][j];
			int cnt = 1;
			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (picture[nx][ny] != num) continue;
					if (vis[nx][ny]) continue;
					vis[nx][ny] = 1;
					cnt++;
					q.push({ nx, ny });
				}
			}
			max_size_of_one_area = max(max_size_of_one_area, cnt);
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}