#include <iostream>
using namespace std;

int main() {
	int n; //테스트 케이스
	int a, b, m;
	int x, y;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> m;
		if (m % a == 0) {
			x = a;
			y = m / a;
		}
		else {
			x = m % a;
			y = (m / a) + 1;
		}
		if(y>=10) cout << x << y << endl;
		else cout << x << "0" << y << endl;
	}

	return 0;
}