#include <bits/stdc++.h>
using namespace std;

int n, c; //숫자 개수, 숫자 최댓값
pair<long long, int> arr[1001];
//숫자, 개수

bool cmp(pair<long long, int> a, pair<long long, int> b) {
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a;

	int index = 0;
	bool flag = false;

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a;
		flag = false;
		for (int j = 0; j < index; j++) {
			if (arr[j].first == a) {
				arr[j].second++;
				flag = true;
				break;
			}
		}
		if (!flag) {
			arr[index] = { a, 1 };
			index++;
		}
	}

	stable_sort(arr, arr + index, cmp);

	for (int i = 0; i < index; i++) {
		for (int j = 0; j < arr[i].second; j++)
			cout << arr[i].first << '\n';
	}
	return 0;
}