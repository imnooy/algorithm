#include <bits/stdc++.h>
using namespace std;

//주사위에서 
//1: 윗면
//2: 윗면에서 뒤로 넘어가는 면
//3: 오른쪽 날개
//4: 왼쪽 날개
//5: 윗면에서 앞으로 넘어오는 면
//6: 아래

int n, m;
int arr[22][22];
int dice[6]; //주사위
//주사위 모양: {윗면에서 뒤로 넘어가는 면, 윗면, 윗면에서 앞으로 넘어오는 면, 아랫면, 왼쪽날개, 오른쪽 날개}
//이렇게 생각함

int pos[7] = { 0, 1, 0, 5, 4, 2, 3 }; //주사위 면이 무슨 위치인지 저장
//pos[3]: index가 3이니까 오른쪽 날개, pos[3]=5, 오른쪽 날개가 지금 dice[5]에 있다

pair<int, int> cur; //주사위 위치 저장

void move(int k) { //주사위 굴리기
	int tmp = pos[1];
	int nx = cur.first;
	int ny = cur.second;
	if (k == 1) { // ->
		ny += 1;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
		pos[1] = pos[4]; //왼쪽 날개가 윗면으로 감
		pos[4] = pos[6]; //아랫면이 왼쪽 날개로 감
		pos[6] = pos[3]; //오른쪽 날개가 아랫면으로 감
		pos[3] = tmp; //윗면이 오른쪽 날개로 감
	}

	else if (k == 2) { // <-
		ny -= 1;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
		pos[1] = pos[3]; //오른쪽 날개가 윗면으로 감
		pos[3] = pos[6]; //아랫면이 오른쪽 날개로 감
		pos[6] = pos[4]; //왼쪽 날개가 아랫면으로 감
		pos[4] = tmp;
	}

	else if (k == 3) { // ↑
		nx -= 1;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
		pos[1] = pos[5];
		pos[5] = pos[6];
		pos[6] = pos[2];
		pos[2] = tmp;
	}

	else if (k == 4) { // ↓
		nx += 1;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;

		pos[1] = pos[2];
		pos[2] = pos[6];
		pos[6] = pos[5];
		pos[5] = tmp;
	}

	cur = { nx, ny }; //주사위도 이동
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

	//k - (1: ->), (2: <-), (3: ↑), (4: ↓)
	for (int i = 0; i < k; i++) {
		cin >> dir;
		move(dir);
	}
	return 0;
}