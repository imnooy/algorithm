#include <bits/stdc++.h>
using namespace std;

int t, w;
int arr[1001];
int d[1001][3][31]; //�̵� �ð�, ��ġ, �̵� Ƚ��

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> t >> w;
	for (int i = 1; i <= t; i++) cin >> arr[i];

	for (int i = 1; i <= t; i++) {
		if (arr[i] == 1) {
			d[i][1][0] = d[i - 1][1][0] + 1;
		}
		else d[i][1][0] = d[i - 1][1][0];
		//�̵����� ��

		for (int j = 1; j <= w; j++) {
			if (i < j) break; //���� �ð����� ���� �̵� �ȵ�

			if (arr[i] == 1) { //1���������� ������
				d[i][1][j] = max(d[i - 1][2][j - 1], d[i - 1][1][j]) + 1;
				d[i][2][j] = max(d[i - 1][1][j - 1], d[i - 1][2][j]);
			}

			else { //2���������� ������
				d[i][1][j] = max(d[i - 1][2][j - 1], d[i - 1][1][j]);
				d[i][2][j] = max(d[i - 1][1][j - 1], d[i - 1][2][j]) + 1;
			}
		}
	}

	int res = 0;
	for (int i = 0; i <= w; i++) res = max({ res, d[t][1][i], d[t][2][i] });
	cout << res;

	return 0;
}