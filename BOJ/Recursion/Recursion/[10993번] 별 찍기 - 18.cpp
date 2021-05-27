#include <bits/stdc++.h>
using namespace std;

char arr[2050][2050];

void star(int n, int a, int b) { //n, ���� ��ǥ
	int aa, bb;
	int x = pow(2, n) - 1;
	int y = x * 2 - 1;

	if (n == 1) {
		arr[a][b] = '*';
		return;
	}

	if (n % 2 == 0) { //n�� ¦���� ��

		int b1 = b + 1;
		int b2 = b + y - 2;
		for (int i = b; i < b + y; i++) arr[a][i] = '*';
		for (int i = a + 1; i < a + x; i++) {
			arr[i][b1] = '*';
			arr[i][b2] = '*';
			b1++;
			b2--;
		}

		star(n - 1, a + 1, b + (y / 4) + 1); //n���� �������ϴ��� 4�� �������ϴ���...
 	}

	else { //n�� Ȧ���� ��

		int b1 = b + (y / 2) - 1;
		int b2 = b + (y / 2) + 1;
		arr[a][b + (y / 2)] = '*';

		for (int i = a + 1; i < a + x - 1; i++) {
			arr[i][b1] = '*';
			arr[i][b2] = '*';
			b1--;
			b2++;
		}
		for (int i = b; i < b + y; i++) arr[a + x - 1][i] = '*';
		
		star(n - 1, a + (x / 2), b + (y / 4) + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int x = pow(2, n) - 1;
	int y = x * 2 - 1;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) arr[i][j] = ' ';
	}

	star(n, 0, 0);

	int yy = y;
	int yyy = (y / 2);

	if (n % 2 == 0) { //n�� ¦��
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (j < yy) cout << arr[i][j];
			}
			cout << '\n';
			yy--;
		}
	}

	else { //n�� Ȧ��
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (j <= yyy) cout << arr[i][j];
			}
			cout << '\n';
			yyy++;
		}
	}
}