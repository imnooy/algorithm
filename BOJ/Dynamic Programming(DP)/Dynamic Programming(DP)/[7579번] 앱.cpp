#include <bits/stdc++.h>
using namespace std;

int m[101];
int c[101];
int d[101][10001];
//i�� ��Ȱ��ȭ�ؼ� j���� �� �޸��� �ִ�
//-> �ִ��� mb���� Ŀ����!

int n, mb;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> mb;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		sum += c[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j - c[i] >= 0) {
				d[i][j] = max(d[i - 1][j], d[i - 1][j - c[i]] + m[i]);
			}
			else d[i][j] = d[i - 1][j];	
		}
	}

	int res = sum;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (d[i][j] >= mb) {
				res = min(j, res);
				break;
			}
		}
	}
	cout << res;
	return 0;
}