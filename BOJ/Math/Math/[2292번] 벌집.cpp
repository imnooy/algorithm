#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int x = 1;
	int y = 1;//���� �� ��
	int cnt = 1;

	if (n > 1) {
		while (1) {
			x = (y + 1);
			y += 6 * cnt;
			if (x <= n && n <= y) {
				cnt++;
				break;
			}
			else {
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}