#include <bits/stdc++.h>
using namespace std;

int dz[6] = { 0, 0, 0, 0, -1, 1 };
int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };

int arr[5][5][5];
int filed[5][5][5]; //������� ���� �ǵ�
bool vis[5][5][5]; //bfs �湮 ����

int order[5]; //order[0]=3�̸� 0��° ������ ���� 3��° ��

int res = 300; //�ּ� �̵��Ÿ�
int dis[5][5][5]; //�̵� �Ÿ� ���� �迭

void file() {
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				filed[k][i][j] = arr[order[k]][i][j];
				dis[k][i][j] = -1; //�Ÿ� �迭�� ���� �ʱ�ȭ ������
			}
		}
	}
}

void bfs() {
	queue<pair<int, pair<int, int>>> q;
	dis[0][0][0] = 0;
	if (filed[0][0][0] == 0 || filed[4][4][4] == 0) return;
	q.push({ 0, {0, 0}});

	while (!q.empty()) {
		pair<int, pair<int, int>> cur = q.front();
		q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.second.first + dx[dir];
			int ny = cur.second.second + dy[dir];
			int nz = cur.first + dz[dir];

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
			if (filed[nz][nx][ny] != 1 || dis[nz][nx][ny] != -1) continue;
			dis[nz][nx][ny] = dis[cur.first][cur.second.first][cur.second.second] + 1;
			q.push({ nz, {nx, ny} });
		}
	}
	if (dis[4][4][4] != -1) res = min(res, dis[4][4][4]);
}

void rotate(int k) { //k��° �� ȸ��
	int pre[5][5];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			pre[j][4 - i] = arr[k][i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[k][i][j] = pre[i][j];
		}
	}
}

void permu() { //�� �׾����� �������ϱ� ��->�� => ��->�Ʒ�
	int a[5] = { 0, 1, 2, 3, 4 }; //����
	do {
		for (int i = 0; i < 5; i++) {
			order[i] = a[i];
		}
		file();
		bfs();
	} while (next_permutation(a, a + 5));

	fill(order, order + 5, 0);
}

void first(int k) {
	if (k == 5) {
		//���� �������Ϸ� ����
		permu();
		return;
	}
	for (int i = 1; i <= 4; i++) { //ȸ�� ��Ʈ��ŷ
		rotate(k);
		first(k + 1);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> arr[i][j][k];
			}
		}
	}

	first(0);

	if (res == 300) res = -1;
	cout << res;

	return 0;
}