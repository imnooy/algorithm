#include <bits/stdc++.h>
using namespace std;

int n, m, h; //���μ� ����(��), ���μ� ����(��), ���μ����� ���μ� ���� �� �ִ� ��ġ�� ����
int wid[32][15]; //���μ� ���� �� �ִ� ��ġ ǥ��

int res = 4;

pair<int, int> possible[480];

bool func() { //i -> ���� ���������� �˻�
	for (int start = 1; start < n + 1; start++) { //�� ����
		int pos = start; //���� �� ��ġ
		for (int i = 1; i < h + 1; i++) { //�� ����
			if (wid[i][pos - 1] == 1) pos -= 1;
			else if (wid[i][pos] == 1) pos += 1;
		}
		if (pos != start) return false;
	}

	return true;
}

int main() {
	int a, b;
	int cnt = 0;
	cin >> n >> m >> h;

	if (m == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b; //a�� ���μ����� b�� b+1��° ���μ��� ���μ� �����
		wid[a][b] = 1;
		if ((b - 1) >= 1) wid[a][b - 1] = -1;
		if ((b + 1) <= n) wid[a][b + 1] = -1; //�����ϸ� �ȵ�
	}

	for (int i = 1; i < h + 1; i++) {
		for (int j = 1; j < n; j++) {
			if (wid[i][j] == 0) {
				possible[cnt] = { i, j };
				cnt++;
			}
		}
	}


	if (func()) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < cnt; i++) {
		wid[possible[i].first][possible[i].second] = 1;
		if (func()) res = min(res, 1);
		for (int j = i + 1; j < cnt; j++) {
			wid[possible[j].first][possible[j].second] = 1;
			if (func()) res = min(res, 2);
			for (int k = j + 1; k < cnt; k++) {
				wid[possible[k].first][possible[k].second] = 1;
				if (func()) res = min(res, 3);
				wid[possible[k].first][possible[k].second] = 0;
			}
			wid[possible[j].first][possible[j].second] = 0;
		}
		wid[possible[i].first][possible[i].second] = 0;
	}

	if (res > 3) res = -1;
	cout << res;
	return 0;
}