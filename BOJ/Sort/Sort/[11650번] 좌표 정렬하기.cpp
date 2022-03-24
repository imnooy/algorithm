#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[100001];
pair<int, int> tmp[100001];
int n;

void merge(int st, int en) { //arr[st:mid]랑 arr[mid:en]합치기
	int mid = (st + en) / 2;
	int a_index = st;
	int b_index = mid;
	for (int i = st; i < en; i++) {
		if (a_index >= mid) {
			tmp[i].first = arr[b_index].first;
			tmp[i].second = arr[b_index++].second;
			continue;
		}
		else if (b_index >= en) {
			tmp[i].first = arr[a_index].first;
			tmp[i].second = arr[a_index++].second;
			continue;
		}

		if (arr[a_index].first > arr[b_index].first) {
			tmp[i].first = arr[b_index].first;
			tmp[i].second = arr[b_index++].second;
		}
		else if(arr[a_index].first < arr[b_index].first) {
			tmp[i].first = arr[a_index].first;
			tmp[i].second = arr[a_index++].second;
		}
		else if (arr[a_index].first == arr[b_index].first) {
			if (arr[a_index].second >= arr[b_index].second) {
				tmp[i].first = arr[b_index].first;
				tmp[i].second = arr[b_index++].second;
			}
			else if (arr[a_index].second < arr[b_index].second) {
				tmp[i].first = arr[a_index].first;
				tmp[i].second = arr[a_index++].second;
			}
		}
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
		cin >> arr[i].first >> arr[i].second;
	}

	merge_sort(0, n);

	for (int i = 0; i < n; i++) cout << arr[i].first << " " << arr[i].second << '\n';

	return 0;
}