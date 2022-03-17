#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char arr[12][6];
bool vis[12][6];

queue<pair<int, int>> q;
bool check[12][6]; //�Ͷ߸� ���� üũ

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs(char c) { //�� �׷� ã��
	vector<pair<int, int>> vec;
	int cnt = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		vec.push_back(cur);
		cnt++;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx > 11 || ny < 0 || ny > 5) continue;
			if (arr[nx][ny] != c || vis[nx][ny] == 1) continue;

			vis[nx][ny] = 1;
			q.push({ nx, ny });

		}
	}

	fill(&vis[0][0], &vis[11][6], 0);

	if (cnt >= 4) { //4�� �̻� �������� �Ͷ߸���
		for (int i = 0; i < vec.size(); i++) { 
			check[vec[i].X][vec[i].Y] = 1;
			arr[vec[i].X][vec[i].Y] = '0';
		}
		return 1;
	}

	else return 0;
}

void arr_down() { //�������� ������ 
	for (int i = 11; i >= 0; i--) { //���� ���ٿ������� ���� Ž��
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] == '0') {
				for (int k = i - 1; k >= 0; k--) { //0�� ĭ�� �� �� ����
					if (arr[k][j] != '0' && arr[k][j] != '.') {
						swap(arr[k][j], arr[i][j]);
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] != '.' && arr[i][j] == '0')
				arr[i][j] = '.';
		}
	}

}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}
	int res = 0; //����
	int bomb = 0; //���򸶴� ���� Ƚ��

	while (1) {
		bomb = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] == '.') continue;
				if (check[i][j]) continue; //�̹� �������� ������

				else {
					q.push({ i, j });
					vis[i][j] = 1;
					bomb += bfs(arr[i][j]); //�� �׷� ã��
					q = queue<pair<int, int>>(); //ť �ʱ�ȭ
				}
			}
		}
		if (bomb == 0) break;
		else {
			res++;
			arr_down();
			fill(&check[0][0], &check[11][6], 0);
		}
	}

	cout << res;

	return 0;
}