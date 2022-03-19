#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 }; //�� �� �� ��

int n, m;
int r, c, d;

int arr[55][55];
bool vis[55][55];

bool isExist = false;
int cnt = 0;

void clean() {
	vis[r][c] = 1; //1.  ���� ��ġ û��
	cnt++;
}

bool search() {
	int dir;
	for (int i = 0; i < 4; i++) {
		if ((d - 1) < 4) d += 4;
		dir = (d - 1) % 4; //2. ���� ��ġ���� ���� ������ �������� ���� ������� ���ʴ�� ������ ĭ�� Ž���Ѵ�.
		d = dir;
		if ((r + dx[dir] < 0) || (r + dx[dir] >= n) || (c + dy[dir] < 0) || (c + dy[dir] >= m)) continue;
		if (!vis[r + dx[dir]][c + dy[dir]] && arr[r + dx[dir]][c + dy[dir]] == 0) { //a. ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
			r += dx[dir];
			c += dy[dir];
			return true;
		}
		//b. ���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
	}
	return false;
}

int main() {
	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	bool isExist = true;
	while (1) {
		if(isExist) clean();
		isExist = search();
		if (!isExist) { //�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, 
			if (arr[r + dx[(d + 2) % 4]][c + dy[(d + 2) % 4]] != 1) { //������ ���� ���� �ƴ� ��
				r += dx[(d + 2) % 4];
				c += dy[(d + 2) % 4];
				//�ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
			}
			else { //���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}