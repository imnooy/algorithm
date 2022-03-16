#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c;
bool arr[42][42];
bool arr_copy[42][42];
bool sticker[12][12];
bool sticker_copy[12][12];

void sticker_cout() { //�׽�Ʈ�� �Լ�
	cout << '\n';
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			cout << sticker[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void arr_cout() { //�׽�Ʈ�� �Լ�
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
	// �����̴� ��Ʈ���� ���ʺ��� ��ƼĿ�� ä�� �������� �ؼ�, ��ƼĿ�� ���� �� �ִ� ��ġ�� ���� �� �ִٸ� ���� ������ ��ġ�� �����Ѵ�. ���� ���ʿ� �ش��ϴ� ��ġ�� ���� ���� �ִٸ� ���߿��� ���� ������ ��ġ�� �����Ѵ�.
	if (r > n || c > m) return false;

	bool isfit = true;

	for (int i = 0; i < ((n - r) + 1); i++) { //���� �̵�
		for (int j = 0; j < ((m - c) + 1); j++) { //���� �̵�

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
			
			//��ƼĿ ����� ��
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

void rotate() { //��ƼĿ ������ - �ð����
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
	cin >> n >> m >> k; //��, ��, ��ƼĿ ����

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