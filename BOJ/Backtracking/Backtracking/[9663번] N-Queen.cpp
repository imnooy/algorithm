#include <bits/stdc++.h>
using namespace std;

bool isused1[40];
bool isused2[40];
bool isused3[40];

int cnt = 0;
int n;

void func(int cur) { //cur번째 행에 배치
	if (cur == n) { //n개를 놓는데 성공
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isused1[i] || isused2[i + cur] || isused3[cur - i + n - 1]) continue;

		isused1[i] = 1; //열
		isused2[cur + i] = 1; //왼->오 대각선
		isused3[cur - i + n - 1] = 1; //오->왼 대각선
		func(cur + 1);
		isused1[i] = 0;
		isused2[cur + i] = 0;
		isused3[cur - i + n - 1] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(0);
	cout << cnt;
}