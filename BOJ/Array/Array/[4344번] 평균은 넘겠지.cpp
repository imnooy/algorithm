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
	int n; //테스트 케이스
	int m; //학생 수
	int cnt; //평균을 넘는 학생 수 
	float per; //평균 넘는 비율
	cin >> n;

	for (int i = 0; i < n; i++) {
		cnt = 0;
		cin >> m;
		int *arr = new int[m]; //점수 저장 배열
		for (int j = 0; j < m; j++) { 
			cin >> arr[j];
		}
		float avg = getAvg(arr, m); //점수 평균 구하기
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