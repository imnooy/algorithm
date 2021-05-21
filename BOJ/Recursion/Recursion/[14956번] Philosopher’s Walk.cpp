#include <bits/stdc++.h>
using namespace std;

pair<int, int> phil(int n, int m) {
	if (n == 2) {
		if (m == 0) return { 1, 1 };
		else if (m == 1) return { 1, 2 };
		else if (m == 2) return { 2, 2 };
		else if (m == 3) return { 2, 1 };
	}

	int half = n / 2;
	int tmp = m / (half * half);
	pair<int, int> pp;

	if (tmp == 0) {
		pp = phil(half, m % (half * half ));
		swap(pp.first, pp.second);
		return pp;
	}

	else if (tmp == 1) {
		pp = phil(half, m % (half * half));
		pp.second += half;
		return pp;
	}

	else if (tmp == 2) {
		pp = phil(half, m % (half * half));
		pp.first += half;
		pp.second += half;
		return pp;
	}

	else if (tmp == 3) {
		pp = phil(half, m % (half * half));
		return { 2 * half - pp.second + 1, half - pp.first + 1 };
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	pair<int, int> res = phil(n, m - 1);
	cout << res.first << " " << res.second;

}