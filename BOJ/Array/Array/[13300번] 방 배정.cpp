#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	int a, b;
	int cnt = 0;
	int arr[12];
	cin >> n >> m; //�л� ���� �� ���� �ִ� �ο� ��

	fill(arr, arr + 12, 0); //�ʱ�ȭ

	for (int i = 0; i < n; i++) {
		cin >> a >> b; //������ �г�
		arr[((b - 1) * 2) + a]++;
	}

	for (int i = 0; i < 12; i++) {
		if (arr[i] % m == 0) cnt += (arr[i] / m);
		else cnt += ((arr[i] / m) + 1);
	}

	cout << cnt;

	return 0;
}