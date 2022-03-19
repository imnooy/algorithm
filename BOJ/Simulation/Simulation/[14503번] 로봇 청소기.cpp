#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 }; //북 동 남 서

int n, m;
int r, c, d;

int arr[55][55];
bool vis[55][55];

bool isExist = false;
int cnt = 0;

void clean() {
	vis[r][c] = 1; //1.  현재 위치 청소
	cnt++;
}

bool search() {
	int dir;
	for (int i = 0; i < 4; i++) {
		if ((d - 1) < 4) d += 4;
		dir = (d - 1) % 4; //2. 현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 차례대로 인접한 칸을 탐색한다.
		d = dir;
		if ((r + dx[dir] < 0) || (r + dx[dir] >= n) || (c + dy[dir] < 0) || (c + dy[dir] >= m)) continue;
		if (!vis[r + dx[dir]][c + dy[dir]] && arr[r + dx[dir]][c + dy[dir]] == 0) { //a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
			r += dx[dir];
			c += dy[dir];
			return true;
		}
		//b. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
	}
	return false;
}

int main() {
	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	bool isExist = true;
	while (1) {
		if(isExist) clean();
		isExist = search();
		if (!isExist) { //네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 
			if (arr[r + dx[(d + 2) % 4]][c + dy[(d + 2) % 4]] != 1) { //후진할 곳이 벽이 아닐 떄
				r += dx[(d + 2) % 4];
				c += dy[(d + 2) % 4];
				//바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
			}
			else { //뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}