#include <iostream>
using namespace std;

float getAvg(int arr[], int n) {
	int sum = 0;
	float avg = 0.0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	avg = sum / n;
	return avg;
}

int main() {
	int n; //�׽�Ʈ ���̽�
	int m; //�л� ��
	int cnt; //����� �Ѵ� �л� �� 
	float per; //��� �Ѵ� ����
	cin >> n;

	for (int i = 0; i < n; i++) {
		cnt = 0;
		cin >> m;
		int *arr = new int[m]; //���� ���� �迭
		for (int j = 0; j < m; j++) { 
			cin >> arr[j];
		}
		float avg = getAvg(arr, m); //���� ��� ���ϱ�
		for (int j = 0; j < m; j++) {
			if (avg < arr[j]) cnt += 1;
		}
		per = (cnt * 100);
		per /= m;
		cout << fixed;
		cout.precision(3);
		cout << per << "%" << endl;

		delete[] arr;
	}

	return 0;
}