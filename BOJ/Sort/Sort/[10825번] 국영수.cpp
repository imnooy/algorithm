#include <bits/stdc++.h>
using namespace std;

int n;
pair<string, pair<int, pair<int, int>>> arr[100001];
//이름, 국, 영, 수

bool cmp_math(pair<string, pair<int, pair<int, int>>> a, pair<string, pair<int, pair<int, int>>> b) {
	if (a.second.second.second == b.second.second.second) return a.first < b.first;
	return a.second.second.second > b.second.second.second;
}

bool cmp_eng(pair<string, pair<int, pair<int, int>>> a, pair<string, pair<int, pair<int, int>>> b) {
	if (a.second.second.first == b.second.second.first) return cmp_math(a, b);
	return a.second.second.first < b.second.second.first;
}

bool cmp_kor(pair<string, pair<int, pair<int, int>>> a, pair<string, pair<int, pair<int, int>>> b) {
	if (a.second.first == b.second.first) return cmp_eng(a, b);
	return a.second.first > b.second.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second.first >> arr[i].second.second.second;
	}

	sort(arr, arr + n, cmp_kor);

	for (int i = 0; i < n; i++) cout << arr[i].first << '\n';

	return 0;
}