#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0, -1, 0, 1};
int dy[4] = { -1, 0, 1, 0}; //왼 위 오 아래

int n, l; //크기, 경사로 길이
int arr[103][103];
bool isl0[103][103];
bool isl1[103][103];

int res = 0;

//dir=0이면 왼쪽, dir=1이면 위로
bool func(pair<int, int> start, int dir, int standard) { 
	int cnt = 0;
	int nx = start.first;
	int ny = start.second;
	while (cnt != l) {
		nx += dx[dir];
		ny += dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
		if (dir == 0 || dir == 2) {
			if (arr[nx][ny] != standard || isl0[nx][ny]) return false;
			if (arr[nx][ny] == standard && !isl0[nx][ny]) {
				isl0[nx][ny] = 1;
				cnt++;
			}
		}
		else if (dir == 1 || dir == 3) {
			if (arr[nx][ny] != standard || isl1[nx][ny]) return false;
			if (arr[nx][ny] == standard && !isl1[nx][ny]) {
				isl1[nx][ny] = 1;
				cnt++;
			}
		}
	}
	return true;
}

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j]; //높이
		}
	}

	for (int i = 0; i < n; i++) {
		pair<int, int> start1 = { i, 0 };
		bool isthrough1 = false;
		int standard = 0;
		for (int j = 1; j < n; j++) { //가로 탐색
			if (arr[start1.first][start1.second] == arr[i][j]) {
				start1.second++;
				isthrough1 = true;
				continue;
			}
			else {
				if (arr[start1.first][start1.second] < arr[i][j]) { //왼쪽 탐색해야함
					standard = arr[i][j] - 1;
					if (!func({ i, j }, 0, standard)) {
						isthrough1 = false;
						break;
					}
					else {
						isthrough1 = true;
						start1 = { i, j };
					}
				}
				else if (arr[start1.first][start1.second] > arr[i][j]) { //오른쪽 탐색해야함
					standard = arr[start1.first][start1.second] - 1;
					if (!func({ start1.first, start1.second }, 2, standard)) {
						isthrough1 = false;
						break;
					}
					else {
						isthrough1 = true;
						start1.second += l;
						j = start1.second;
					}
				}
			}
		}
		if (isthrough1) {
			res++;
		}
	}

	for (int j = 0; j < n; j++) {
		pair<int, int> start2 = { 0, j };
		bool isthrough2 = false;
		int standard = 0;
		for (int i = 1; i < n; i++) { //세로 탐색
			if (arr[start2.first][start2.second] == arr[i][j]) {
				start2.first++;
				isthrough2 = true;
				continue;
			}
			else {
				if (arr[start2.first][start2.second] < arr[i][j]) { //위쪽 탐색해야함
					standard = arr[i][j] - 1;
					if (!func({ i, j }, 1, standard)) {
						isthrough2 = false;
						break;
					}
					else {
						isthrough2 = true;
						start2 = { i, j };
					}
				}
				else if (arr[start2.first][start2.second] > arr[i][j]) { //아래쪽 탐색해야함
					standard = arr[start2.first][start2.second] - 1;
					if (!func({ start2.first, start2.second }, 3, standard)) {
						isthrough2 = false;
						break;
					}
					else {
						isthrough2 = true;
						start2.first += l;
						i = start2.first;
					}
				}
			}
		}
		if (isthrough2) {
			res++;
		}
	}

	cout << res;

	return 0;
}