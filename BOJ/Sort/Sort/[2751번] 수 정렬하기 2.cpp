#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];
int tmp[1000001]; // merge �Լ����� ����Ʈ 2���� ��ģ ����� �ӽ÷� �����ϰ� ���� ����

// mid = (st+en)/2��� �� �� arr[st:mid], arr[mid:en]�� �̹� ������ �Ǿ��ִ� ������ �� arr[st:mid]�� arr[mid:en]�� ��ģ��.
void merge(int st, int en) {
	int mid = (st + en) / 2;
	int a_index = st, b_index = mid;
	for (int i = st; i < en; i++) {
		if (a_index >= mid) tmp[i] = arr[b_index++];
		else if (b_index >= en) tmp[i] = arr[a_index++];
		else if (arr[a_index] >= arr[b_index]) tmp[i] = arr[b_index++];
		else tmp[i] = arr[a_index++];
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i];
}

// arr[st:en]�� �����ϰ� �ʹ�.
void merge_sort(int st, int en) { //st�� ����, en�� ���� ���� ��
	if (en - st == 1) 
		return; // ���� 1�� ���
	int mid = (st + en) / 2;
	merge_sort(st, mid); // arr[st:mid]�� �����Ѵ�.
	merge_sort(mid, en); // arr[mid:en]�� �����Ѵ�.
	merge(st, en); // arr[st:mid]�� arr[mid:en]�� ��ģ��.
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}