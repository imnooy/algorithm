#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 }; //오 아래 왼 위 - 오른쪽 방향으로 도는 순서

int n, k, l; //크기, 사과 개수, 뱀의 방향 변환 횟수
int x; char c;

int arr[105][105];
queue<pair<int, char>> q; //방향 변환 정보 저장

pair<int, int> head = { 0, 0 };
pair<int, int> tail = { 0, 0 }; //뱀의 머리와 꼬리 좌표
int dir = 0; //뱀의 현재 방향

int sec = 0;

int main() {
	int a, b; //사과 좌표
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		arr[a - 1][b - 1] = 1; //사과 표시
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		q.push({ x, c });
	}

	arr[0][0] = 2; //뱀 자리 2라고 가정

	deque<pair<int, int>> snake; //뱀 좌표


	while (1) {
		head.first += dx[dir];
		head.second += dy[dir]; //먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
		snake.push_front(head);

		if (arr[head.first][head.second] == 2 || head.first >= n || head.second >= n || head.first < 0 || head.second < 0) break;
		//벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.

		if (arr[head.first][head.second] == 1) { //만약 이동한 칸에 사과가 있다면, 
			arr[head.first][head.second] = 0; //그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
		}

		else if (arr[head.first][head.second] == 0) { //만약 이동한 칸에 사과가 없다면,	
			arr[tail.first][tail.second] = 0; //몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
			tail = snake.back();
			snake.pop_back();
		}
		arr[head.first][head.second] = 2;
		sec++;
		if (!q.empty()) {
			if (q.front().first == sec) { //게임 시작 시간으로부터 X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전
				c = q.front().second;
				q.pop();
				if (c == 'L') { //왼쪽으로 틀기
					if (dir - 1 < 0) dir += 4;
					dir = (dir - 1) % 4;
				}
				else if (c == 'D') { //오른쪽으로 틀기
					dir = (dir + 1) % 4;
				}
			}
		}
	}

	cout << sec + 1;

	return 0;
}