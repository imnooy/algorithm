#include <bits/stdc++.h>
using namespace std;

int n, m;
char arr[13][13];
char pre[10][13][13];
char a[13][13];
bool vis[13][13];

bool isused[10];
bool isSuccess = false;
bool isFail = false; //파란공이 먼저 골인하거나 동시에 골인

int res = 11;

pair<int, int> red;
pair<int, int> blue;

void before(int k) { //미리 저장
	int nn = 0;
	for (int i = 0; i < 13; i++) {
		if (arr[i][0] != '#') break;
		nn++;
	}
	int mm = 0;
	for (int j = 0; j < 13; j++) {
		if (arr[0][j] != '#') break;
		mm++;
	}
	n = nn;
	m = mm;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			if (i < n && j < m) pre[k][i][j] = arr[i][j];
			else pre[k][i][j] = NULL;
			
		}
	}
}

void after(int k) {
	int nn = 0;
	for (int i = 0; i < 13; i++) {
		if (pre[k][i][0] != '#') break;
		nn++;
	}
	int mm = 0;
	for (int j = 0; j < 13; j++) {
		if (pre[k][0][j] != '#') break;
		mm++;
	}
	n = nn;
	m = mm;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			if (i < n && j < m) {
				arr[i][j] = pre[k][i][j];
				if (pre[k][i][j] == 'R') red = { i, j };
				if (pre[k][i][j] == 'B') blue = { i, j };
			}
			else arr[i][j] = NULL;
		}
	}
}

void rotate() { //회전시켜서 위 왼 아래로도 이동하는 것처럼 - 시계
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[j][n - i - 1] = arr[i][j];
			arr[i][j] = NULL;
		}
	}
	swap(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = a[i][j];
			if (a[i][j] == 'R') red = { i, j };
			if (a[i][j] == 'B') blue = { i, j };
		}
	}
}

void move(int k) { //오른쪽으로만 이동
	before(k); //이동하기 전 저장
	int r_cnt = 0, b_cnt = 0;
	bool flag = false;
	for (int j = red.second + 1; j < m; j++) { //빨간거 먼저 이동
		if (arr[red.first][j] == 'O') {
			arr[red.first][red.second] = '.';
			isSuccess = true;
			break;
		}
		else if (arr[red.first][j] == '.') r_cnt++;
		else if (arr[red.first][j] == 'B') {
			flag = true; //나중에 같이 이동
			break;
		}
		else if (arr[red.first][j] == '#') break;
	}
	swap(arr[red.first][red.second], arr[red.first][red.second + r_cnt]);
	red.second += r_cnt;

	for (int j = blue.second + 1; j < m; j++) { //파란색 공 이동
		if (arr[blue.first][j] == 'O') {
			arr[blue.first][blue.second] = '.';
			isSuccess = false;
			isFail = true;
			break;
		}
		else if (arr[blue.first][j] == '.') b_cnt++;
		else if (arr[blue.first][j] == '#' || arr[blue.first][j] == 'R') break;
	}
	swap(arr[blue.first][blue.second], arr[blue.first][blue.second + b_cnt]);
	blue.second += b_cnt;
	if (flag) {
		swap(arr[red.first][red.second], arr[red.first][red.second + b_cnt]);
		red.second += r_cnt;
	}
}

void func(int k) {
	if (k == 10) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (!isused[k]) {
			isused[k] = 1;
			rotate();
			move(k);

			if(!isSuccess && !isFail) func(k + 1);
			if (isSuccess && !isFail) {
				res = min(res, k);
				isSuccess = false;
				after(k - 1);
				return;
			}
			if (isFail) {
				isFail = false;
			}
			after(k);
			isused[k] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			//pre[0][i][j] = arr[i][j];
			if (arr[i][j] == 'B') blue = { i, j };
			if (arr[i][j] == 'R') red = { i, j };
		}
	}
	func(0);

	if (res > 10) cout << "-1";
	else cout << res + 1;

	return 0;
}