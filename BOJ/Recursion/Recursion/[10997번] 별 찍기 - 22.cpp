#include <bits/stdc++.h>
using namespace std;

char arr[400][400];

void star(int n, int a, int b) { //n, 시작점
	int x = 3 + (n - 1) * 4; //행 수
	int y = 1 + (n - 1) * 4; //열 수
	if (n == 1) { //기저
		arr[a][b] = '*';
		arr[a + 1][b] = '*';
		arr[a + 2][b] = '*';
		return;
	}

	for (int i = b; i < b + y; i++) {
		arr[a][i] = '*'; //맨 윗줄
		arr[a + x - 1][i] = '*'; //맨 아랫줄
	}

	for (int i = a + 1; i < a + x - 1; i++) {
		arr[i][b] = '*'; //왼쪽 가장자리
		arr[i][b + y - 1] = '*'; //오른쪽 가장자리
	}

	arr[a + 1][b + y - 1] = ' '; 
	arr[a + 2][b + y - 2] = '*';

	star(n - 1, a + 2, b + 2);

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n == 1) {
		cout << '*';
		return 0;
	}

	int x = 3 + (n - 1) * 4;
	int y = 1 + (n - 1) * 4;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) arr[i][j] = ' ';
	}

	star(n, 0, 0);

	for (int i = 0; i < y; i++) cout << arr[0][i];
	cout << '\n';
	cout << '*' << '\n';

	for (int i = 2; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}