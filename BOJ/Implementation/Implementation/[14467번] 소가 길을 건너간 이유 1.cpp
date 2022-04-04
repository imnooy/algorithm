#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2][100];

pair<int, int> cnt[11]; //i번 소의 바꾼 횟수, 현재 위치

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> n;
	for (int j = 0; j < n; j++) {
		cin >> a >> b;
		arr[b][j] = a;
	}
	for (int i = 0; i < 11; i++) cnt[i].second = -1;
	int cow = -1;
	for (int i = 0; i < n; i++) {
		if (arr[0][i] == 0) { //1번에 소있음
			cow = arr[1][i];
			if (cnt[cow].second == -1) cnt[cow].second = 1;
			else if (cnt[cow].second == 0) { //근데 원래 위치 0일 때
				cnt[cow].first += 1;
				cnt[cow].second = 1;
			}
		}
		else { //0번에 소있음
			cow = arr[0][i];
			if (cnt[cow].second == -1) cnt[cow].second = 0;
			else if (cnt[cow].second == 1) { //근데 원래 위치 1일 때
				cnt[cow].first += 1;
				cnt[cow].second = 0;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < 11; i++) res += cnt[i].first;

	cout << res;

	return 0;
}