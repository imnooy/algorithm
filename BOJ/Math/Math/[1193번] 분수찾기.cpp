#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int x = 1; //분자
	int y = 1; //분모

	int a, b;

	int s, t;

	int cnt = 1; //루프 카운트
	int i;

	while (1) {
		if (x > y) {
			a = x; //큰 수가 a
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
			if (cnt % 2 == 0) {//루프 짝수번 돌았을 때
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