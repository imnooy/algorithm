#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	sort(arr, arr + n);
	
	int cnt = 1;
	int mcnt = 0; //���� ���� ������ �ִ� ������ ����
	long long res = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] == arr[i]) cnt++;
		else {
			if (cnt > mcnt) {
				mcnt = cnt;
				res = arr[i - 1];
			}
			cnt = 1;
		}
	}
	if (cnt > mcnt) res = arr[n - 1]; //������ �� ���ֱ�

	cout << res;

	return 0;
}