#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int d[1001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		d[i] = arr[i];
	}
	

	for (int i = 1; i <= n; i++) { //n�� ī�� ������ ��
		for (int j = 1; j <= i; j++) { 
			d[i] = max(d[i - j] + d[j], d[i]); 
			//n-a�� ��� �������� a�� �� ��
		}
	}

	cout << d[n];

	return 0;
}