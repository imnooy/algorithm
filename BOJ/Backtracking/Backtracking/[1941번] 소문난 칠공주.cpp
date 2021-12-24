#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int ans = 0; //��
char arr[5][5]; //input ���� �迭
int num[25] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; //�� ĭ�� 0~24�� �ΰ� 7�� ����

int x[4] = { -1, 1, 0, 0 };
int y[4] = { 0, 0, -1, 1 };

bool visited[5][5];	 //bfs() check
bool Cchecked[5][5]; //7�� ���� �� check

void bfs() {
	int cnt = 0;
	queue<pair<int, int>> q;
	bool flag = false;

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < 5; i++) { //���� 7�� �� 1���� queue�� �ֱ�
		for (int j = 0; j < 5; j++) {
			if (Cchecked[i][j] && !visited[i][j]) {
				q.push({ i, j });
				visited[i][j] = 1;
				cnt++;
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	//queue�� �� 1���� �������� bfs()�ؼ� S�� 7���̸� ans++

	while (!q.empty()) {
		int qx = q.front().first;
		int qy = q.front().second;
		q.pop();
		if (cnt == 7) {
			ans++;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int xx = qx + x[i];
			int yy = qy + y[i];
			if (xx < 0 || xx >= 5 || yy < 0 || yy >= 5) continue;
			if (!visited[xx][yy] && Cchecked[xx][yy]) {
				visited[xx][yy] = 1;
				q.push({ xx, yy });
				cnt++;
			}
		}
	}

}

void ncr() { //25�� �� 7�� �̱�
	int scnt;
	do {
		scnt = 0;
		memset(Cchecked, 0, sizeof(Cchecked));

		for (int i = 0; i < 25; i++) {
			if (num[i] == 0) {
				Cchecked[i / 5][i % 5] = 1; //���õ� 7�� ǥ��
				if (arr[i / 5][i % 5] == 'S')
					scnt++;
			}
		}

		if (scnt >= 4) { //S�� ������ 4���� ���� ������ �� �˻�
			bfs();
		}

	} while (next_permutation(num, num + 25));
}

int main() {
	char c;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> c;
			arr[i][j] = c;
		}
	}

	ncr();

	cout << ans;

	return 0;
}