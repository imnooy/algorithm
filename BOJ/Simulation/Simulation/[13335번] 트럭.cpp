#include <bits/stdc++.h>
using namespace std;

int arr[1002]; //Ʈ�� ���Ե� ����
int n, w, l; //Ʈ�� ����, �ٸ� ����, �ٸ� �ִ� ����
int sec = 0, cur_l = 0;
int start;

queue<int> bridge; //�ٸ� ����

queue<int> q;

int main() {
	cin >> n >> w >> l; //Ʈ�� ����, �ٸ� ����, �ٸ� �ִ� ����

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; //Ʈ�� ���� �Է¹ޱ�
		q.push(i);
	}
	for (int i = 0; i < w; i++) {
		bridge.push(-1);
	}
	int cnt = 0; //�ٸ��� �ִ� Ʈ�� ����

	while (1) {
		if (q.empty()) break;

		if (bridge.front() != -1) {
			cur_l -= arr[bridge.front()];
			cnt--;
		}
		bridge.pop();

		start = q.front(); //Ʈ���� ť

		if (arr[start] + cur_l <= l && cnt < w) { //���� Ʈ�� ����, ���� �˻�
			q.pop();
			bridge.push(start); //�ٸ��� �ֱ�
			cur_l += arr[start];
			cnt++;
		}
		else bridge.push(-1);
		sec++;
	}
	while (!bridge.empty()) {
		sec++;
		bridge.pop();
	}

	cout << sec;

	return 0;
}