#include <iostream>
using namespace std;

int main() {
	int t, k, n, i, j, m;
	cin >> t;

	for (m = 0; m < t; m++) {
		cin >> k >> n;
		k = k + 1;
		n = n + 1;
		int **arr = new int*[k];
		for (i = 0; i < k; i++) {
			arr[i] = new int[n];
		} //2���� �迭 ����
		for (i = 0; i < k; i++) {
			for (j = 1; j < n; j++) {
				arr[i][j] = 0;
			}
		} //�迭 �ʱ�ȭ
		for (j = 1; j < n; j++) {
			arr[0][j] = j; //0�� �ֹ� �� 
		}
		for (i = 1; i < k; i++) {
			for (j = 1; j < n; j++) {
				for (int k = 1; k <= j; k++) {
					arr[i][j] += arr[i - 1][k];
				}
			}
		}
		cout << arr[k-1][n-1] << endl;
		for (i = 0; i < k; i++) {
			delete[] arr[i];
		}
		delete[]arr;
	}

	return 0;
}