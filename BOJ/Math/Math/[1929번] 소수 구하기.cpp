#include <iostream>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;

	//2 ~ n까지의 수를 검사
	bool *arr = new bool[n + 1]; //소수와 인덱스가 일치하도록

	for (int i = 2; i <= n; i++) {
		arr[i] = true;
	} //초기화

	for (int i = 2; i*i <= n; i++) {
		if (arr[i] == true) {//검사안된 수나 소수일 때만
			for (int j = i * 2; j <= n; j += i) {
				//i의 배수를 체크
				arr[j] = false;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (arr[i] == true) {
			cout << i << '\n';
		}
	}

	return 0;
}