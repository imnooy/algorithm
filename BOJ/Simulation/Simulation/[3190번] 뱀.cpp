#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 }; //�� �Ʒ� �� �� - ������ �������� ���� ����

int n, k, l; //ũ��, ��� ����, ���� ���� ��ȯ Ƚ��
int x; char c;

int arr[105][105];
queue<pair<int, char>> q; //���� ��ȯ ���� ����

pair<int, int> head = { 0, 0 };
pair<int, int> tail = { 0, 0 }; //���� �Ӹ��� ���� ��ǥ
int dir = 0; //���� ���� ����

int sec = 0;

int main() {
	int a, b; //��� ��ǥ
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		arr[a - 1][b - 1] = 1; //��� ǥ��
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		q.push({ x, c });
	}

	arr[0][0] = 2; //�� �ڸ� 2��� ����

	deque<pair<int, int>> snake; //�� ��ǥ


	while (1) {
		head.first += dx[dir];
		head.second += dy[dir]; //���� ���� �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ų��.
		snake.push_front(head);

		if (arr[head.first][head.second] == 2 || head.first >= n || head.second >= n || head.first < 0 || head.second < 0) break;
		//�� �Ǵ� �ڱ��ڽ��� ���� �ε����� ������ ������.

		if (arr[head.first][head.second] == 1) { //���� �̵��� ĭ�� ����� �ִٸ�, 
			arr[head.first][head.second] = 0; //�� ĭ�� �ִ� ����� �������� ������ �������� �ʴ´�.
		}

		else if (arr[head.first][head.second] == 0) { //���� �̵��� ĭ�� ����� ���ٸ�,	
			arr[tail.first][tail.second] = 0; //�����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�. ��, �����̴� ������ �ʴ´�.
			tail = snake.back();
			snake.pop_back();
		}
		arr[head.first][head.second] = 2;
		sec++;
		if (!q.empty()) {
			if (q.front().first == sec) { //���� ���� �ð����κ��� X�ʰ� ���� �ڿ� ����(C�� 'L') �Ǵ� ������(C�� 'D')�� 90�� ������ ȸ��
				c = q.front().second;
				q.pop();
				if (c == 'L') { //�������� Ʋ��
					if (dir - 1 < 0) dir += 4;
					dir = (dir - 1) % 4;
				}
				else if (c == 'D') { //���������� Ʋ��
					dir = (dir + 1) % 4;
				}
			}
		}
	}

	cout << sec + 1;

	return 0;
}