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


void move(int dir) { //�̵��غ��� (��������)
	fill(&cantAdd[0][0], &cantAdd[21][22], 0);

	if (dir == 0) { //���� �б�
		for (int j = 0; j < n; j++) { //�� ������
			for (int i = 1; i < n; i++) { //�� ���캸�� (�� �� �� ����)

				if (arr[i][j] != 0) { //���ڰ� �ִ� ����� ��
					int dis = 0; //�̵��� �Ÿ�
					for (int k = i - 1; k >= 0; k--) { //���� �ִ� ����� �� ��ϵ� ���캸��
						if (arr[k][j] == 0) dis++;
						else if (arr[k][j] == arr[i][j] && cantAdd[k][j]) {
							break;
						}
						else if (arr[k][j] == arr[i][j] && !cantAdd[k][j]) { //�� ��� �� ���ڰ� ���� ��� �ְ� ���� �� ���� ��
							arr[k][j] *= 2;
							arr[i][j] = 0;
							cantAdd[k][j] = 1;

							break;
						}
						else if (arr[k][j] != arr[i][j]) { //�� ��� �� ���ڰ� �ִµ� �ٸ� ��
							break;
						}
					}

					arr[i - dis][j] = arr[i][j]; //�̵�
					if (dis > 0) arr[i][j] = 0;
				}

			}
		}
	}

	else if (dir == 1) { //�Ʒ��� �б�
		for (int j = 0; j < n; j++) { //�� ������
			for (int i = n - 2; i >= 0; i--) { //�� ���캸�� (�� �Ʒ� �� ����)

				if (arr[i][j] != 0) { //���ڰ� �ִ� ����� ��
					int dis = 0; //�̵��� �Ÿ�
					for (int k = i + 1; k < n; k++) { //���� �ִ� ����� �Ʒ� ��ϵ� ���캸��
						if (arr[k][j] == 0) dis++;
						else if (arr[k][j] == arr[i][j] && cantAdd[k][j]) {
							break;
						}
						else if (arr[k][j] == arr[i][j] && !cantAdd[k][j]) { //�� ��� �� ���ڰ� ���� ��� �ְ� ���� �� ���� ��
							arr[k][j] *= 2;
							arr[i][j] = 0;
							cantAdd[k][j] = 1;
						}
						else if (arr[k][j] != arr[i][j]) { //�� ��� �� ���ڰ� �ִµ� �ٸ� ��
							break;
						}
					}

					arr[i + dis][j] = arr[i][j]; //�̵�
					if (dis > 0) arr[i][j] = 0;
				}

			}
		}
	}

	else if (dir == 2) { //�������� �б�
		for (int i = 0; i < n; i++) { //�� �ึ��
			for (int j = 1; j < n; j++) { //�� ���캸�� (�� ���� �� ����)

				if (arr[i][j] != 0) { //���ڰ� �ִ� ����� ��
					int dis = 0; //�̵��� �Ÿ�
					for (int k = j - 1; k >= 0; k--) { //���� �ִ� ����� �� ��ϵ� ���캸��
						if (arr[i][k] == 0) dis++;
						else if (arr[i][k] == arr[i][j] && cantAdd[i][k]) {
							break;
						}
						else if (arr[i][k] == arr[i][j] && !cantAdd[i][k]) { //�� ��� �� ���ڰ� ���� ��� �ְ� ���� �� ���� ��
							arr[i][k] *= 2;
							arr[i][j] = 0;
							cantAdd[i][k] = 1;
						}
						else if (arr[i][k] != arr[i][j]) { //�� ��� �� ���ڰ� �ִµ� �ٸ� ��
							break;
						}
					}

					arr[i][j - dis] = arr[i][j]; //�̵�
					if (dis > 0) arr[i][j] = 0;
				}

			}
		}
	}

	else if (dir == 3) { //���������� �б�
		for (int i = 0; i < n; i++) { //�� �ึ��
			for (int j = n - 2; j >= 0; j--) { //�� ���캸�� (�� ������ �� ����)

				if (arr[i][j] != 0) { //���ڰ� �ִ� ����� ��
					int dis = 0; //�̵��� �Ÿ�
					for (int k = j + 1; k < n; k++) { //���� �ִ� ����� ������ ��ϵ� ���캸��
						if (arr[i][k] == 0) dis++;
						else if (arr[i][k] == arr[i][j] && cantAdd[i][k]) {
							break;
						}
						else if (arr[i][k] == arr[i][j] && !cantAdd[i][k]) { //�� ��� �� ���ڰ� ���� ��� �ְ� ���� �� ���� ��
							arr[i][k] *= 2;
							arr[i][j] = 0;
							cantAdd[i][k] = 1;
						}
						else if (arr[i][k] != arr[i][j]) { //�� ��� �� ���ڰ� �ִµ� �ٸ� ��
							break;
						}
					}

					arr[i][j + dis] = arr[i][j]; //�̵�
					if (dis > 0) arr[i][j] = 0;
				}

			}
		}
	}
}

void func(int k) { //5�� �̵� �� k��° �̵� ���� ���ϱ�
	if (k == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				maximum = max(maximum, arr[i][j]); //�ִ�
			}
		}

		return;
	}


	for (int i = 0; i < 4; i++) {

		dir_arr[k] = i;

		move(i); //�����̱�
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