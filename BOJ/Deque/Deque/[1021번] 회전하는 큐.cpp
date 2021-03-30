#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> d;
	int n, m, a, b;
	int sum = 0;
	int index1, index2;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) d.push_back(i);

	deque<int> d1(d);
	deque<int> d2(d);

	for (int i = 0; i < m; i++) {
		cin >> a;
		
		index1 = 0; index2 = 0;
		if (a == d.front()) {
			d.pop_front();
		}
		else {
				while (!d1.empty()) {
					if (a == d1.front()) {
						d1.pop_front();
						break;
					}
					b = d1.front();
					d1.pop_front();
					d1.push_back(b);
					index1++;
				}
				while (!d2.empty()) {
					if (a == d2.front()) {
						d2.pop_front();
						break;
					}
					b = d2.back();
					d2.pop_back();
					d2.push_front(b);
					index2++;
			}
		}
		if (index1 == 0 && index2 == 0) {
			d1 = d;
			d2 = d;
		}
		else if (index1 <= index2) {
			sum += index1;
			d = d1;
			d2 = d1;
		}
		else if(index1 > index2) {
			sum += index2;
			d = d2;
			d1 = d2;
		}
	}
	cout << sum;
}