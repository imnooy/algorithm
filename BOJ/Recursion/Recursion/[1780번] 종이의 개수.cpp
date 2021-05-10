#include <bits/stdc++.h>
using namespace std;

int arr[2188][2188];
int cnt[3];

int check(int i, int j, int tmp) {
	bool iseq = true;
	int val = arr[i][j];

	for (int a = i; a < i + tmp; a++) {
		for (int b = j; b < j + tmp; b++) {
			if (arr[a][b] != val) {
				iseq = false;
				return -2;
			}
		}
	}

	return val;
}

void print(int i, int j, int n) {
	int tmp = n / 3;
	
	int one = check(i, j, tmp);
	int two = check(i, j + tmp, tmp);
	int three = check(i, j + (2 * tmp), tmp);
	int four = check(i + tmp, j, tmp);
	int five = check(i + tmp, j + tmp, tmp);
	int six = check(i + tmp, j + (2 * tmp), tmp);
	int seven = check(i + (2 * tmp), j, tmp);
	int eight = check(i + (2 * tmp), j + tmp, tmp);
	int nine = check(i + (2 * tmp), j + (2 * tmp), tmp);

	if (one != -2 && one == two && two == three && three == four && 
		four == five && five == six && six == seven && seven == eight && eight == nine) {
		cnt[one + 1]++;
		return;
	}


	if (one != -2) { //첫번째 구역 
		cnt[one + 1]++;
		//return;
	}
	else print(i, j, tmp);

	if (two != -2) { //두번째 구역 
		cnt[two + 1]++;
		//return;
	}
	else print(i, j + tmp, tmp);

	if (three != -2) { //세번째 구역 
		cnt[three + 1]++;
		//return;
	}
	else print(i, j + (2 * tmp), tmp);

	if (four != -2) { //네번째 구역 
		cnt[four + 1]++;
		//return;
	}
	else print(i + tmp, j, tmp);

	if (five != -2) {
		cnt[five + 1]++;
	}
	else print(i + tmp, j + tmp, tmp);

	if (six != -2) {
		cnt[six + 1]++;
	}
	else print(i + tmp, j + (2 * tmp), tmp);

	if (seven != -2) {
		cnt[seven + 1]++;
	}
	else print(i + (2 * tmp), j, tmp);

	if (eight != -2) {
		cnt[eight + 1]++;
	}
	else print(i + (2 * tmp), j + tmp, tmp);

	if (nine != -2) {
		cnt[nine + 1]++;
		return;
	}
	else print(i + (2 * tmp), j + (2 * tmp), tmp);


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	char c;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	print(0, 0, n);

	for (int i = 0; i < 3; i++) cout << cnt[i] << '\n';
}