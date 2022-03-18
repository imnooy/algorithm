#include <bits/stdc++.h>
using namespace std;

int arr[1002]; //트럭 무게들 저장
int n, w, l; //트럭 개수, 다리 길이, 다리 최대 하중
int sec = 0, cur_l = 0;
int start;

queue<int> bridge; //다리 상태

queue<int> q;

int main() {
	cin >> n >> w >> l; //트럭 개수, 다리 길이, 다리 최대 하중

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; //트럭 무게 입력받기
		q.push(i);
	}
	for (int i = 0; i < w; i++) {
		bridge.push(-1);
	}
	int cnt = 0; //다리에 있는 트럭 개수

	while (1) {
		if (q.empty()) break;

		if (bridge.front() != -1) {
			cur_l -= arr[bridge.front()];
			cnt--;
		}
		bridge.pop();

		start = q.front(); //트럭들 큐

		if (arr[start] + cur_l <= l && cnt < w) { //들어올 트럭 무게, 개수 검사
			q.pop();
			bridge.push(start); //다리에 넣기
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