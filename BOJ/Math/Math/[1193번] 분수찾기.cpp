#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int x = 1; //����
	int y = 1; //�и�

	int a, b;

	int s, t;

	int cnt = 1; //���� ī��Ʈ
	int i;

	while (1) {
		if (x > y) {
			a = x; //ū ���� a
			b = y;
		}
		else {
			a = y;
			b = x;
		}

		if (b <= n && n <= a) {
			if (cnt % 2 != 0) {
				s = cnt;
				t = 1;
				for (i = b; i < n; i++) {
					s--;
					t++;
				}
				break;
			}
			else {
				s = 1;
				t = cnt;
				for (i = b; i < n; i++) {
					s++;
					t--;
				}
				break;
			}
		}
		else {
			if (cnt % 2 == 0) {//���� ¦���� ������ ��
				x += 1;
				y += 2 * cnt;
			}
			else {
				x += 2 * cnt;
				y += 1;
			}
		}
		cnt++;
	}

	cout << s << "/" << t;

	return 0;
}