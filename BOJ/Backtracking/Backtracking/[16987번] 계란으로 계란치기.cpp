#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[8];
int ans;

int n, cnt;

void func(int k) { //k��° ��� ����
	if (k == n) {
		cnt = 0;
		for (int i = 0; i < n; i++) { //�������� 0������ ����� ���� ����
			if (arr[i].first <= 0) cnt++;
		}
		ans = max(cnt, ans);
		return;
	}

	if (arr[k].first <= 0) func(k + 1); //k��° ��� ���������� ���� ������� �Ѿ
	else {
		bool hit = false;
		for (int i = 0; i < n; i++) {
			if (i == k || arr[i].first <= 0) continue; //�ٸ� ����� �̹� �����ְų� ���� ����̸� �Ѿ
			else {
				arr[k].first -= arr[i].second;
				arr[i].first -= arr[k].second; //��

				hit = true; //ħ

				func(k + 1);

				arr[i].first += arr[k].second;
				arr[k].first += arr[i].second;
			}
		}
		if (!hit) func(n); //ĥ ����� ������ �ٷ� �Ѿ
	}
}

int main() {
	int d, w; //������, ����
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