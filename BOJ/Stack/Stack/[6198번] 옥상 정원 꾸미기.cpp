#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair< int, int >> st1; //누적합, 값
	stack <int> st;
	int n, a;
	int aa = 0;
	int index = 0;
	long long int sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		st.push(a);
	}

	for (int i = 0; i < n; i++) {
		index = 0;
		if (!st.empty()) aa = st.top();

		if (!st1.empty()) {
			while (!st1.empty()) {
				if (aa > st1.top().second) {
					index += st1.top().first;
					index++;
					st1.pop();
				}
				else {
					break;
				}
			}
		}
		 st1.push(make_pair(index, aa));

		if (!st.empty()) st.pop();
		sum += index;
	}

	cout << sum;
}