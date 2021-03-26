#include <bits/stdc++.h>
using namespace std;

int main() {
	int x1, y1, r1, x2, y2, r2;
	int n;
	double dd, rpr, rmr;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		dd = ((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2));
		rpr = (r1 + r2)*(r1 + r2);
		rmr = (r1 - r2)*(r1 - r2);
		if (x1 == x2 && y1 == y2 && r1 == r2) { //동심원
			cout << "-1" << '\n';
		}
		else if (x1 == x2 && y1 == y2 && r1 != r2) { //반지름만 다름
			cout << "0" << '\n';
		}
		else if (rmr == dd) { //내접
			cout << "1" << '\n';
		}
		else if (rpr < dd) { //외부, 안만남
			cout << "0" << '\n';
		}
		else if (rpr == dd) { //외접
			cout << "1" << '\n';
		}
		else if (rmr < dd && dd < rpr) { //교점 2개
			cout << "2" << '\n';
		}
		else if (rmr > dd) { //포함, 안만남
			cout << "0" << '\n';
		}
	}
}