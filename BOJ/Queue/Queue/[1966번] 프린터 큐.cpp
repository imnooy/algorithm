#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	int n, m, a, max;
	int pr = 0; //출력 순서

	cin >> t;
	for (int i = 0; i < t; i++) {
		queue<pair<int, int>> q;
		set<int> s;
		vector<int> v;
		
		pr = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a;
			q.push(make_pair(i, a));
			v.push_back(a);
		}
		sort(v.begin(), v.end());

		while (1) {
			max = v[v.size() - 1];
			if (!q.empty()) {
				if (q.front().second < max) { //queue의 맨 앞 원소가 최댓값보다 작으면
					q.push(q.front());
					q.pop(); //맨 앞 원소를 맨 뒤로 보내기.
				}
				else if (q.front().second == max) {
					pr++;
					if (q.front().first == m) {  //찾는 원소일 때
						cout << pr << '\n';
						q.pop();
						v.pop_back();
						break;
					}
					else {
						q.pop();
						v.pop_back();
					}
				}
			}
		}
	}


}