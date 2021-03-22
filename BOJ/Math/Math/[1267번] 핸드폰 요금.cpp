#include <iostream> 
using namespace std;

int main() {
	int y = 0;
	int m = 0;
	int sum = 0;
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		y += (a / 30) + 1;
		m += (a / 60) + 1;
	}

	y = y * 10;
	m = m * 15;

	if (y > m) cout << "M " << m;
	else if (y < m) cout << "Y " << y;
	else if (y == m) cout << "Y M " << y;

	return 0;
}