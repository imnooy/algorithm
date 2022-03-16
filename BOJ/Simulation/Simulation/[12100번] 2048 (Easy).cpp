#include <bits/stdc++.h>
using namespace std;

int start[22][22];

int arr[22][22];
int arr_back[5][22][22];
bool cantAdd[22][22];

int dir_arr[5];

int n;
int maximum = 0;

void arr_backup(int k) {
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			arr_back[k][a][b] = arr[a][b];
		}
	}
}

void arr_rollback(int k) {
	if (k == 0) {
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				arr[a][b] = start[a][b];
			}
		}
	}

	else {
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				arr[a][b] = arr_back[k - 1][a][b];
			}
		}
	}
}


void move(int dir) { //이동해보기 (동서남북)
	fill(&cantAdd[0][0], &cantAdd[21][22], 0);

	if (dir == 0) { //위로 밀기
		for (int j = 0; j < n; j++) { //각 열마다
			for (int i = 1; i < n; i++) { //행 살펴보기 (맨 위 행 제외)

				if (arr[i][j] != 0) { //숫자가 있는 블록일 때
					int dis = 0; //이동할 거리
					for (int k = i - 1; k >= 0; k--) { //숫자 있는 블록의 위 블록들 살펴보기
						if (arr[k][j] == 0) dis++;
						else if (arr[k][j] == arr[i][j] && cantAdd[k][j]) {
							break;
						}
						else if (arr[k][j] == arr[i][j] && !cantAdd[k][j]) { //위 블록 중 숫자가 같은 블록 있고 더할 수 있을 때
							arr[k][j] *= 2;
							arr[i][j] = 0;
							cantAdd[k][j] = 1;

							break;
						}
						else if (arr[k][j] != arr[i][j]) { //위 블록 중 숫자가 있는데 다를 때
							break;
						}
					}

					arr[i - dis][j] = arr[i][j]; //이동
					if (dis > 0) arr[i][j] = 0;
				}

			}
		}
	}

	else if (dir == 1) { //아래로 밀기
		for (int j = 0; j < n; j++) { //각 열마다
			for (int i = n - 2; i >= 0; i--) { //행 살펴보기 (맨 아래 행 제외)

				if (arr[i][j] != 0) { //숫자가 있는 블록일 때
					int dis = 0; //이동할 거리
					for (int k = i + 1; k < n; k++) { //숫자 있는 블록의 아래 블록들 살펴보기
						if (arr[k][j] == 0) dis++;
						else if (arr[k][j] == arr[i][j] && cantAdd[k][j]) {
							break;
						}
						else if (arr[k][j] == arr[i][j] && !cantAdd[k][j]) { //위 블록 중 숫자가 같은 블록 있고 더할 수 있을 때
							arr[k][j] *= 2;
							arr[i][j] = 0;
							cantAdd[k][j] = 1;
						}
						else if (arr[k][j] != arr[i][j]) { //위 블록 중 숫자가 있는데 다를 때
							break;
						}
					}

					arr[i + dis][j] = arr[i][j]; //이동
					if (dis > 0) arr[i][j] = 0;
				}

			}
		}
	}

	else if (dir == 2) { //왼쪽으로 밀기
		for (int i = 0; i < n; i++) { //각 행마다
			for (int j = 1; j < n; j++) { //열 살펴보기 (맨 왼쪽 열 제외)

				if (arr[i][j] != 0) { //숫자가 있는 블록일 때
					int dis = 0; //이동할 거리
					for (int k = j - 1; k >= 0; k--) { //숫자 있는 블록의 옆 블록들 살펴보기
						if (arr[i][k] == 0) dis++;
						else if (arr[i][k] == arr[i][j] && cantAdd[i][k]) {
							break;
						}
						else if (arr[i][k] == arr[i][j] && !cantAdd[i][k]) { //위 블록 중 숫자가 같은 블록 있고 더할 수 있을 때
							arr[i][k] *= 2;
							arr[i][j] = 0;
							cantAdd[i][k] = 1;
						}
						else if (arr[i][k] != arr[i][j]) { //위 블록 중 숫자가 있는데 다를 때
							break;
						}
					}

					arr[i][j - dis] = arr[i][j]; //이동
					if (dis > 0) arr[i][j] = 0;
				}

			}
		}
	}

	else if (dir == 3) { //오른쪽으로 밀기
		for (int i = 0; i < n; i++) { //각 행마다
			for (int j = n - 2; j >= 0; j--) { //열 살펴보기 (맨 오른쪽 열 제외)

				if (arr[i][j] != 0) { //숫자가 있는 블록일 때
					int dis = 0; //이동할 거리
					for (int k = j + 1; k < n; k++) { //숫자 있는 블록의 오른쪽 블록들 살펴보기
						if (arr[i][k] == 0) dis++;
						else if (arr[i][k] == arr[i][j] && cantAdd[i][k]) {
							break;
						}
						else if (arr[i][k] == arr[i][j] && !cantAdd[i][k]) { //위 블록 중 숫자가 같은 블록 있고 더할 수 있을 때
							arr[i][k] *= 2;
							arr[i][j] = 0;
							cantAdd[i][k] = 1;
						}
						else if (arr[i][k] != arr[i][j]) { //위 블록 중 숫자가 있는데 다를 때
							break;
						}
					}

					arr[i][j + dis] = arr[i][j]; //이동
					if (dis > 0) arr[i][j] = 0;
				}

			}
		}
	}
}

void func(int k) { //5번 이동 중 k번째 이동 방향 정하기
	if (k == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				maximum = max(maximum, arr[i][j]); //최댓값
			}
		}

		return;
	}


	for (int i = 0; i < 4; i++) {

		dir_arr[k] = i;

		move(i); //움직이기
		arr_backup(k);

		func(k + 1);
		arr_rollback(k);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			start[i][j] = arr[i][j];
		}
	}

	func(0);

	cout << maximum;

	return 0;
}