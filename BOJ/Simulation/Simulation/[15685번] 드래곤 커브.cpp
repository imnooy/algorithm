#include <bits/stdc++.h>
using namespace std;

int n;
int x, y, d, g; //시작점, 시작방향, 세대

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 }; //->, ↑, <-, ↓

vector<pair<int, int>> curving; //회전시켜야 하는 좌표들
pair<int, int> endpoint;

bool dragon[101][101];

int find_dir(pair<int, int> diff) {
	if (diff.first == 0 && diff.second == 1) return 1;
	else if (diff.first == -1 && diff.second == 0) return 2;
	else if (diff.first == 0 && diff.second == -1) return 3;
	else return 0;
}

void curve() {
	int sz = curving.size(); //curving의 마지막 좌표가 endpoint
	endpoint = curving[sz - 1]; //기준 좌표
	for (int i = sz - 1; i > 0; i--) {
		pair<int, int> cur = curving[i];
		pair<int, int> move_cur = curving[i - 1]; //회전해야 하는 좌표
		int dir = find_dir({ cur.first - move_cur.first, cur.second - move_cur.second });
		dragon[endpoint.first + dx[dir]][endpoint.second + dy[dir]] = 1;
		endpoint.first += dx[dir];
		endpoint.second += dy[dir];
		curving.push_back(endpoint);
	}
}


int main() {
	cin >> n;
	int back; //반대 방향

	for (int i = 0; i < n; i++) {
		curving.clear();
		cin >> y >> x >> d >> g; //d: 시작방향, g: 세대
		dragon[x][y] = 1;
		dragon[x + dx[d]][y + dy[d]] = 1; //0세대
		curving.push_back({ x, y });
		curving.push_back({ x + dx[d], y + dy[d] });
		for (int j = 0; j < g; j++) {
			curve();
		}
	}

	int res = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (!dragon[i][j] || !dragon[i][j + 1] || !dragon[i + 1][j] || !dragon[i + 1][j + 1]) continue;
			res++;
		}
	}

	cout << res;
	return 0;
}