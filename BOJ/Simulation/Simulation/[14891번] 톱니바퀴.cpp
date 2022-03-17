#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx1[4] = { 0, 1, 0, -1 };
int dy1[4] = { 1, 0, -1, 0 }; // ���� �Ʒ� �� �� - �ð�

int dx2[4] = { 1, 0, -1, 0 };
int dy2[4] = { 0, 1, 0, -1 }; //�Ʒ� ���� �� �� - �ݽð�

bool arr[4][3][3]; //��Ϲ���
int gear, dir;

bool r[4]; //ȸ����ų ��Ϲ��� ����
int gears[4]; //��Ϲ����� ���� ȸ���� ���� ����

void rotate() {
	int index = 0;
	int nx = 0, ny = 0, i = 0, j = 0;
	for (int a = 0; a < 4; a++) {
		if (r[a]) { //ȸ����ų ���̸�..
			bool pre[3][3];
			if (gears[a] == 1) { //�ð����
				while (1) {
					if ((j + dy1[index]) > 2 || (i + dx1[index]) > 2 || (j + dy1[index]) < 0) {
						index++;
					}

					nx = i + dx1[index];
					ny = j + dy1[index];

					pre[nx][ny] = arr[a][i][j];

					i = nx; j = ny;
					if (nx == 0 && ny == 0) break;
				}
				index = 0;
			}

			else if (gears[a] == -1) { //�ݽð����
				while (1) {
					if ((j + dy2[index]) > 2 || (i + dx2[index]) > 2 || (i + dx2[index]) < 0) {
						index++;
					}

					nx = i + dx2[index];
					ny = j + dy2[index];

					pre[nx][ny] = arr[a][i][j];

					i = nx; j = ny;
					if (nx == 0 && ny == 0) break;
				}
				index = 0;
			}

			for (int ii = 0; ii < 3; ii++) {
				for (int jj = 0; jj < 3; jj++) {
					arr[a][ii][jj] = pre[ii][jj];
				}
			}

		}
	}
}

int main() {
	int k;
	bool l_dir, r_dir;
	string s;

	for (int i = 0; i < 4; i++) {
		int a = 0, b = 0, index = 0, nx = 0, ny = 0;
		cin >> s;
		if (s[7] - '0' == 1) arr[i][0][0] = true;
		else if (s[7] - '0' == 0) arr[i][0][0] = false;
		for (int j = 0; j < 7; j++) {
			if ((b + dy1[index]) > 2 || (a + dx1[index]) > 2 || (b + dy1[index]) < 0) {
				index++;
			}

			nx = a + dx1[index];
			ny = b + dy1[index];

			if (s[j] - '0' == 1) arr[i][nx][ny] = true;
			else if (s[j] - '0' == 0) arr[i][nx][ny] = false;

			a = nx; b = ny;
		}
	}

	cin >> k;

	//(N��: 0), (S��: 1)
	for (int i = 0; i < k; i++) {
		cin >> gear >> dir;  //dir: (�ð� ����: 1), (�ݽð� ����: -1)

		r[gear - 1] = 1;
		gears[gear - 1] = dir;

		l_dir = arr[gear - 1][1][0];
		r_dir = arr[gear - 1][1][2];

		for (int j = gear - 2; j >= 0; j--) { //ȸ����Ű�� ��Ϲ����� ���ʿ� �ִ� ��Ϲ��� �� ȸ���� ��Ϲ��� ���ϱ�
			if (l_dir != arr[j][1][2]) {
				gears[j] = -gears[j + 1];
				r[j] = 1;
			}
			else {
				break;
			}
			l_dir = arr[j][1][0];
		}

		for (int j = gear; j < 4; j++) { //ȸ����Ű�� ��Ϲ����� �����ʿ� �ִ� ��Ϲ��� �� ȸ���� ��Ϲ��� ���ϱ�
			if (r_dir != arr[j][1][0]) {
				gears[j] = -gears[j - 1];
				r[j] = 1;
			}
			else {
				break;
			}
			r_dir = arr[j][1][2];
		}

		rotate();

		fill(r, r + 4, 0);
		fill(gears, gears + 4, 0);
	}

	int res = 0;
	if (arr[0][0][1] == 1) res += 1;
	if (arr[1][0][1] == 1) res += 2;
	if (arr[2][0][1] == 1) res += 4;
	if (arr[3][0][1] == 1) res += 8;

	cout << res;

	return 0;
}