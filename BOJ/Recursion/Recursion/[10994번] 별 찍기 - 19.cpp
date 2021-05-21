#include <bits/stdc++.h>
using namespace std;

char arr[400][400];

void print(int n, int a, int b) { //n, 시작점
	int num = 1 + (n - 1) * 4;
	if (n == 1) {
		arr[a][b] = '*';
		return;
	}

	for (int i = a; i < a + num; i++) {
		arr[b][i] = '*';
		arr[b + num - 1][i] = '*';
	}
	for (int i = a + 1; i < a + num; i++) { //행 증가
		arr[i][b] = '*';
		arr[i][b + num - 1] = '*';
	}
	print(n - 1, a + 2, b + 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int tmp = 1 + (n - 1) * 4;

	for (int i = 0; i < tmp; i++) {
		for (int j = 0; j < tmp; j++) arr[i][j] = ' ';
	}

	print(n, 0, 0);

	for (int i = 0; i < tmp; i++) {
		for (int j = 0; j < tmp; j++) cout << arr[i][j];
		cout << '\n';
	}
}