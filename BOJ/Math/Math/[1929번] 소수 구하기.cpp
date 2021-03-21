#include <iostream>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;

	//2 ~ n������ ���� �˻�
	bool *arr = new bool[n + 1]; //�Ҽ��� �ε����� ��ġ�ϵ���

	for (int i = 2; i <= n; i++) {
		arr[i] = true;
	} //�ʱ�ȭ

	for (int i = 2; i*i <= n; i++) {
		if (arr[i] == true) {//�˻�ȵ� ���� �Ҽ��� ����
			for (int j = i * 2; j <= n; j += i) {
				//i�� ����� üũ
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