#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int, int>> st;
	int n, a;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (st.empty()) st.push(make_pair(i, a));
		else {
			if (st.top().second > a) st.push(make_pair(i, a));
			else {
				while (!st.empty() && st.top().second < a) {
					arr[st.top().first] = a;
					st.pop();
				}
				st.push(make_pair(i, a));
			}
		}
	}

	if (!st.empty()) while (!st.empty()) {
		arr[st.top().first] = -1;
		st.pop();
	}

	for (int i = 0; i < n; i++) cout << arr[i] << " ";

	delete[]arr;
}