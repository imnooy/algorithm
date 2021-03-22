#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	set<int> s;
	set<int>::iterator iter;
	cin >> a >> b >> c;
	s.insert(a);
	s.insert(b);
	s.insert(c);

	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << " ";
	}
	return 0;
}