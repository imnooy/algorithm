#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int ans = 0; //답
char arr[5][5]; //input 저장 배열
int num[25] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; //각 칸을 0~24로 두고 7개 선택

int x[4] = { -1, 1, 0, 0 };
int y[4] = { 0, 0, -1, 1 };

bool visited[5][5];	 //bfs() check
bool Cchecked[5][5]; //7명 뽑은 거 check

void bfs() {
	int cnt = 0;
	queue<pair<int, int>> q;
	bool flag = false;

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < 5; i++) { //뽑은 7개 중 1개만 queue에 넣기
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

	//queue에 들어간 1개를 시작으로 bfs()해서 S가 7개이면 ans++

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

void ncr() { //25명 중 7명 뽑기
	int scnt;
	do {
		scnt = 0;
		memset(Cchecked, 0, sizeof(Cchecked));

		for (int i = 0; i < 25; i++) {
			if (num[i] == 0) {
				Cchecked[i / 5][i % 5] = 1; //선택된 7개 표시
				if (arr[i / 5][i % 5] == 'S')
					scnt++;
			}
		}

		if (scnt >= 4) { //S의 개수가 4개일 때만 인접한 지 검사
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