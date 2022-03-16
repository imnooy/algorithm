#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int arr[10][10];
bool check[10][10];

bool issued1[4];
bool issued2[2];
bool issued3[4];
bool issued4[4];
bool issued5[1];
vector<pair<pair<int, int>, pair<int, int>>> cctvs;
//{¹øÈ£, ¹æÇâ}, {xÁÂÇ¥, yÁÂÇ¥}

int maximum = 0;

void one(int dir, pair<int, int> p) {
	if (dir == 0) { //»ó
		for (int i = p.X - 1; i >= 0; i--) {
			if (arr[i][p.Y] == 6) break;

			if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
		}
	}

	else if (dir == 1) { //¿ì
		for (int i = p.Y + 1; i < m; i++) {
			if (arr[p.X][i] == 6) break;

			if (arr[p.X][i] == 0) check[p.X][i] = 1;
		}
	}

	else if (dir == 2) { //ÇÏ
		for (int i = p.X + 1; i < n; i++) {
			if (arr[i][p.Y] == 6) break;

			if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
		}
	}

	else if (dir == 3) { //ÁÂ
		for (int i = p.Y - 1; i >= 0; i--) {
			if (arr[p.X][i] == 6) break;

			if (arr[p.X][i] == 0) check[p.X][i] = 1;
		}
	}
}

void two(int dir, pair<int, int> p) {
	if (dir == 0) { //»óÇÏ
		for (int i = p.X - 1; i >= 0; i--) {
			if (arr[i][p.Y] == 6) break;

			if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
		}

		for (int i = p.X + 1; i < n; i++) {
			if (arr[i][p.Y] == 6) break;

			if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
		}
	}

	else if (dir == 1) { //ÁÂ¿ì
		for (int i = p.Y - 1; i >= 0; i--) {
			if (arr[p.X][i] == 6) break;

			if (arr[p.X][i] == 0) check[p.X][i] = 1;
		}

		for (int i = p.Y + 1; i < m; i++) {
			if (arr[p.X][i] == 6) break;

			if (arr[p.X][i] == 0) check[p.X][i] = 1;
		}
	}
}

void three(int dir, pair<int, int> p) {
	if (dir == 0) { //»ó¿ì
		for (int i = p.X - 1; i >= 0; i--) {
			if (arr[i][p.Y] == 6) break;

			if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
		}

		for (int i = p.Y + 1; i < m; i++) {
			if (arr[p.X][i] == 6) break;

			if (arr[p.X][i] == 0) check[p.X][i] = 1;
		}
	}

	else if (dir == 1) { //»óÁÂ
		for (int i = p.X - 1; i >= 0; i--) {
			if (arr[i][p.Y] == 6) break;

			if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
		}

		for (int i = p.Y - 1; i >= 0; i--) {
			if (arr[p.X][i] == 6) break;

			if (arr[p.X][i] == 0) check[p.X][i] = 1;
		}
	}

	else if (dir == 2) { //ÇÏ¿ì
		for (int i = p.Y + 1; i < m; i++) {
			if (arr[p.X][i] == 6) break;

			if (arr[p.X][i] == 0) check[p.X][i] = 1;
		}

		for (int i = p.X + 1; i < n; i++) {
			if (arr[i][p.Y] == 6) break;

			if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
		}
	}

	else if (dir == 3) { //ÇÏÁÂ
		for (int i = p.Y - 1; i >= 0; i--) {
			if (arr[p.X][i] == 6) break;

			if (arr[p.X][i] == 0) check[p.X][i] = 1;
		}

		for (int i = p.X + 1; i < n; i++) {
			if (arr[i][p.Y] == 6) break;

			if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
		}
	}
}

void four(int dir, pair<int, int> p) {
	if (dir == 0) { //»óÁÂ¿ì
		for (int i = p.X - 1; i >= 0; i--) {
			if (arr[i][p.Y] == 6) break;

			if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
		}

		for (int i = p.Y - 1; i >= 0; i--) {
			if (arr[p.X][i] == 6) break;

			if (arr[p.X][i] == 0) check[p.X][i] = 1;
		}

		for (int i = p.Y + 1; i < m; i++) {
			if (arr[p.X][i] == 6) break;

			if (arr[p.X][i] == 0) check[p.X][i] = 1;
		}
	}

	else if (dir == 1) { //ÇÏÁÂ¿ì
		for (int i = p.X + 1; i < n; i++) {
			if (arr[i][p.Y] == 6) break;

			if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
		}

		for (int i = p.Y - 1; i >= 0; i--) {
			if (arr[p.X][i] == 6) break;

			if (arr[p.X][i] == 0) check[p.X][i] = 1;
		}

		for (int i = p.Y + 1; i < m; i++) {
			if (arr[p.X][i] == 6) break;

			if (arr[p.X][i] == 0) check[p.X][i] = 1;
		}
	}

	else if (dir == 2) { //»óÇÏÁÂ
		for (int i = p.X - 1; i >= 0; i--) {
			if (arr[i][p.Y] == 6) break;

			if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
		}

		for (int i = p.X + 1; i < n; i++) {
			if (arr[i][p.Y] == 6) break;

			if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
		}

		for (int i = p.Y - 1; i >= 0; i--) {
			if (arr[p.X][i] == 6) break;

			if (arr[p.X][i] == 0) check[p.X][i] = 1;
		}
	}

	else if (dir == 3) { //»óÇÏ¿ì
		for (int i = p.X - 1; i >= 0; i--) {
			if (arr[i][p.Y] == 6) break;

			if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
		}

		for (int i = p.X + 1; i < n; i++) {
			if (arr[i][p.Y] == 6) break;

			if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
		}

		for (int i = p.Y + 1; i < m; i++) {
			if (arr[p.X][i] == 6) break;

			if (arr[p.X][i] == 0) check[p.X][i] = 1;
		}
	}
}

void five(pair<int, int> p) {
	for (int i = p.X - 1; i >= 0; i--) {
		if (arr[i][p.Y] == 6) break;

		if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
	}

	for (int i = p.X + 1; i < n; i++) {
		if (arr[i][p.Y] == 6) break;

		if (arr[i][p.Y] == 0) check[i][p.Y] = 1;
	}

	for (int i = p.Y - 1; i >= 0; i--) {
		if (arr[p.X][i] == 6) break;

		if (arr[p.X][i] == 0) check[p.X][i] = 1;
	}

	for (int i = p.Y + 1; i < m; i++) {
		if (arr[p.X][i] == 6) break;

		if (arr[p.X][i] == 0) check[p.X][i] = 1;
	}
}

void bt(int k) { //k¹øÂ° ¿ø¼Ò ¹æÇâ Á¤ÇÏ±â
	if (k == cctvs.size()) {
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			if (cctvs[i].X.X == 1) one(cctvs[i].X.Y, cctvs[i].Y);
			else if (cctvs[i].X.X == 2) two(cctvs[i].X.Y, cctvs[i].Y);
			else if (cctvs[i].X.X == 3) three(cctvs[i].X.Y, cctvs[i].Y);
			else if (cctvs[i].X.X == 4) four(cctvs[i].X.Y, cctvs[i].Y);
			else if (cctvs[i].X.X == 5) five(cctvs[i].Y);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (check[i][j]) cnt++;
			}
		}
		maximum = max(maximum, cnt);
		fill(&check[0][0], &check[9][10], 0);

		return;
	}

	if (cctvs[k].X.X == 1) {
		for (int i = 0; i < 4; i++) {
			if (!issued1[i]) {
				cctvs[k].X.Y = i;
				bt(k + 1);
				issued1[i] = 0;
			}
		}
	}

	else if (cctvs[k].X.X == 2) {
		for (int i = 0; i < 2; i++) {
			if (!issued2[i]) {
				cctvs[k].X.Y = i;
				bt(k + 1);
				issued2[i] = 0;
			}
		}
	}

	else if (cctvs[k].X.X == 3) {
		for (int i = 0; i < 4; i++) {
			if (!issued3[i]) {
				cctvs[k].X.Y = i;
				bt(k + 1);
				issued3[i] = 0;
			}
		}
	}

	else if (cctvs[k].X.X == 4) {
		for (int i = 0; i < 4; i++) {
			if (!issued4[i]) {
				cctvs[k].X.Y = i;
				bt(k + 1);
				issued4[i] = 0;
			}
		}
	}

	else if (cctvs[k].X.X == 5) {
		for (int i = 0; i < 1; i++) {
			if (!issued5[i]) {
				cctvs[k].X.Y = i;
				bt(k + 1);
				issued5[i] = 0;
			}
		}
	}
	
}

int main() {
	cin >> n >> m;
	int minus = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 6) minus++;
			if (arr[i][j] == 0 || arr[i][j] == 6) continue;

			minus++;
			cctvs.push_back({ {arr[i][j], -1}, {i, j} });
		}
	}

	bt(0);

	cout << n * m - maximum - minus;

	return 0;
}