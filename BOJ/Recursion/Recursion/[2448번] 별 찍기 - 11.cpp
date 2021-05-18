#include <bits/stdc++.h>
using namespace std;

char arr[3073][6145];

void print(int h, int n, int m) { //ex) (24, 0, 23)
	if (h == 3) { //����
		arr[n][m] = '*';

		arr[n + 1][m - 1] = '*';
		arr[n + 1][m + 1] = '*';

		arr[n + 2][m - 2] = '*';
		arr[n + 2][m - 1] = '*';
		arr[n + 2][m] = '*';
		arr[n + 2][m + 1] = '*';
		arr[n + 2][m + 2] = '*';

		return;
	}

	print(h / 2, n, m); //�� �ﰢ�� ����, ������ ��ǥ
	print(h / 2, n + (h / 2), m - (h / 2)); //���� �ﰢ�� ����, ������ ��ǥ
	print(h / 2, n + (h / 2), m + (h / 2)); //������ �ﰢ�� ����, ������ ��ǥ
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			arr[i][j] = ' ';
		}
	}
	
	print(n, 0, n - 1); //�ﰢ���� ����, ������ ��ǥ ����

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}