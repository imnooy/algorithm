#include <bits/stdc++.h>
using namespace std;

int arr[65][65];

int check(int i, int j, int tmp) {
	bool iseq = true;
	int val = arr[i][j];

	for (int a = i; a < i + tmp; a++) {
		for (int b = j; b < j + tmp; b++) {
			if (arr[a][b] != val) {
				iseq = false;
				return -1;
			}
		}
	}

	return val;
}

void print(int i, int j, int n) {
	int tmp = n / 2;

	int one = check(i, j, tmp);
	int two = check(i, j + tmp, tmp);
	int three = check(i + tmp, j, tmp);
	int four = check(i + tmp, j + tmp, tmp);

	if (one != -1 && one == two && two == three && three == four) {
		cout << one;
		return;
	}

	cout << "(";

	if (one != -1) { //첫번째 구역 
		cout << one;
		//return;
	}
	else print(i, j, tmp);

	if (two != -1) { //두번째 구역 
		cout << two;
		//return;
	}
	else print(i, j + tmp, tmp);

	if (three != -1) { //세번째 구역 
		cout << three;
		//return;
	}
	else print(i + tmp, j, tmp);

	if (four != -1) { //네번째 구역 
		cout << four;
		cout << ")";
		return;
	}
	else print(i + tmp, j + tmp, tmp);

	cout << ")";

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	char c;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			arr[i][j] = c - '0';
		}
	}

	print(0, 0, n);
}