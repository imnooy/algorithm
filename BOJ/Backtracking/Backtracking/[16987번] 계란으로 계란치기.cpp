#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[8];
int ans;

int n, cnt;

void func(int k) { //k번째 계란 집음
	if (k == n) {
		cnt = 0;
		for (int i = 0; i < n; i++) { //내구도가 0이하인 계란의 개수 세기
			if (arr[i].first <= 0) cnt++;
		}
		ans = max(cnt, ans);
		return;
	}

	if (arr[k].first <= 0) func(k + 1); //k번째 계란 깨져있으면 다음 계란으로 넘어감
	else {
		bool hit = false;
		for (int i = 0; i < n; i++) {
			if (i == k || arr[i].first <= 0) continue; //다른 계란이 이미 깨져있거나 같은 계란이면 넘어감
			else {
				arr[k].first -= arr[i].second;
				arr[i].first -= arr[k].second; //쳐

				hit = true; //침

				func(k + 1);

				arr[i].first += arr[k].second;
				arr[k].first += arr[i].second;
			}
		}
		if (!hit) func(n); //칠 계란이 없으면 바로 넘어감
	}
}

int main() {
	int d, w; //내구도, 무게
	int max;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		arr[i] = { d, w };
	}

	func(0);

	cout << ans;

	return 0;
}