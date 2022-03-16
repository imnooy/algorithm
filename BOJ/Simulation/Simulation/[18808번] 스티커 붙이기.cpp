#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c;
bool arr[42][42];
bool arr_copy[42][42];
bool sticker[12][12];
bool sticker_copy[12][12];

void sticker_cout() { //테스트용 함수
	cout << '\n';
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			cout << sticker[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void arr_cout() { //테스트용 함수
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//if (arr[i][j]) res++;
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

bool fit() { 
	// 혜윤이는 노트북의 위쪽부터 스티커를 채워 나가려고 해서, 스티커를 붙일 수 있는 위치가 여러 곳 있다면 가장 위쪽의 위치를 선택한다. 가장 위쪽에 해당하는 위치도 여러 곳이 있다면 그중에서 가장 왼쪽의 위치를 선택한다.
	if (r > n || c > m) return false;

	bool isfit = true;

	for (int i = 0; i < ((n - r) + 1); i++) { //가로 이동
		for (int j = 0; j < ((m - c) + 1); j++) { //세로 이동

			for (int a = 0; a < r; a++) {
				for (int b = 0; b < c; b++) {
					if (sticker[a][b] == 0) continue;

					else if (sticker[a][b] == 1 && arr[a + i][b + j] == 1) {
						isfit = false;
						break;
					}

					else if (sticker[a][b] == 1 && arr[a + i][b + j] == 0) {
						arr_copy[a + i][b + j] = 1;
					}
				}
				if (!isfit) break;
			}
			
			//스티커 대봤을 때
			if (isfit) {
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < m; b++) {
						if (arr_copy[a][b]) {
							arr[a][b] = arr_copy[a][b];
						}
					}
				}

				fill(&arr_copy[0][0], &arr_copy[41][42], 0);
				return true;
			}
			else {
				isfit = true;
				fill(&arr_copy[0][0], &arr_copy[41][42], 0);
			}
		}
	}
	return false;
}

void rotate() { //스티커 돌리기 - 시계방향
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			sticker_copy[j][r - i - 1] = sticker[i][j];
		}
	}

	fill(&sticker[0][0], &sticker[11][12], 0);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			sticker[i][j] = sticker_copy[i][j];
		}
	}

	fill(&sticker_copy[0][0], &sticker_copy[11][12], 0);
}

int main() {
	cin >> n >> m >> k; //행, 열, 스티커 개수

	for (int i = 0; i < k; i++) {
		int rotate_cnt = 0;
		fill(&sticker[0][0], &sticker[11][12], 0);

		cin >> r >> c;
		for (int a = 0; a < r; a++) {
			for (int b = 0; b < c; b++) {
				cin >> sticker[a][b];
			}
		}
		
		while (1) {
			if (rotate_cnt == 4) break;
			if (fit()) break;
			else {
				rotate();
				swap(r, c);
				rotate_cnt++;
			}
		}

	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]) res++;
			//cout << arr[i][j] << " ";
		}
		//cout << '\n';
	}
	cout << res;

	return 0;
}