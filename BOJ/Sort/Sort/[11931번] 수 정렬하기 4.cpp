#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int tmp[1000001];
int n;

void merge(int st, int en) { //arr[st:mid]랑 arr[mid:en]합치기
	int mid = (st + en) / 2;
	int a_index = st;
	int b_index = mid;
	for (int i = st; i < en; i++) {
		if (a_index >= mid) {
			tmp[i] = arr[b_index++];
			continue;
		}
		else if (b_index >= en) {
			tmp[i] = arr[a_index++];
			continue;
		}

		if (arr[a_index] < arr[b_index]) tmp[i] = arr[b_index++];
		else tmp[i] = arr[a_index++];
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
	if (en - st == 1) return; //길이 1이면 return
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	merge_sort(0, n);

	for (int i = 0; i < n; i++) cout << arr[i] << '\n';

	return 0;
}