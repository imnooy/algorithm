#include <bits/stdc++.h>
using namespace std;

//�ֻ������� 
//1: ����
//2: ���鿡�� �ڷ� �Ѿ�� ��
//3: ������ ����
//4: ���� ����
//5: ���鿡�� ������ �Ѿ���� ��
//6: �Ʒ�

int n, m;
int arr[22][22];
int dice[6]; //�ֻ���
//�ֻ��� ���: {���鿡�� �ڷ� �Ѿ�� ��, ����, ���鿡�� ������ �Ѿ���� ��, �Ʒ���, ���ʳ���, ������ ����}
//�̷��� ������

int pos[7] = { 0, 1, 0, 5, 4, 2, 3 }; //�ֻ��� ���� ���� ��ġ���� ����
//pos[3]: index�� 3�̴ϱ� ������ ����, pos[3]=5, ������ ������ ���� dice[5]�� �ִ�

pair<int, int> cur; //�ֻ��� ��ġ ����

void move(int k) { //�ֻ��� ������
	int tmp = pos[1];
	int nx = cur.first;
	int ny = cur.second;
	if (k == 1) { // ->
		ny += 1;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
		pos[1] = pos[4]; //���� ������ �������� ��
		pos[4] = pos[6]; //�Ʒ����� ���� ������ ��
		pos[6] = pos[3]; //������ ������ �Ʒ������� ��
		pos[3] = tmp; //������ ������ ������ ��
	}

	else if (k == 2) { // <-
		ny -= 1;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
		pos[1] = pos[3]; //������ ������ �������� ��
		pos[3] = pos[6]; //�Ʒ����� ������ ������ ��
		pos[6] = pos[4]; //���� ������ �Ʒ������� ��
		pos[4] = tmp;
	}

	else if (k == 3) { // ��
		nx -= 1;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
		pos[1] = pos[5];
		pos[5] = pos[6];
		pos[6] = pos[2];
		pos[2] = tmp;
	}

	else if (k == 4) { // ��
		nx += 1;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;

		pos[1] = pos[2];
		pos[2] = pos[6];
		pos[6] = pos[5];
		pos[5] = tmp;
	}

	cur = { nx, ny }; //�ֻ����� �̵�
	if (arr[nx][ny] == 0) arr[nx][ny] = dice[pos[6]];
	else {
		dice[pos[6]] = arr[nx][ny];
		arr[nx][ny] = 0;
	}
	cout << dice[pos[1]] << '\n';
}

int main() {
	int k, x, y;
	int dir;
	cin >> n >> m >> x >> y >> k;
	cur = { x, y };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	//k - (1: ->), (2: <-), (3: ��), (4: ��)
	for (int i = 0; i < k; i++) {
		cin >> dir;
		move(dir);
	}
	return 0;
}