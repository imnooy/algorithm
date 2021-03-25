/*연결리스트 직접 구현*/
#include <iostream>
#include <string>
using namespace std;

const int n = 100001;
int pre[n], nxt[n];
char dat[n];
int unused = 1;

void insert(int cur, char c) {
	dat[unused] = c;
	pre[unused] = cur;
	nxt[unused] = nxt[cur];

	if(nxt[cur]!=-1) pre[nxt[cur]] = unused;
	nxt[cur] = unused;

	unused++;
}

void erase(int cur) {
	nxt[pre[cur]] = nxt[cur];
	if (nxt[cur] != -1) pre[nxt[cur]] = pre[cur];
}

int main() {
	int cur = 0;
	char a, b;
	fill(pre, pre + n, -1);
	fill(nxt, nxt + n, -1);

	string s;
	cin >> s;

	for (auto c : s) {
		insert(cur, c); //커서의 왼쪽에 추가
		cur++;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a == 'L') {
			if(pre[cur]!=-1) cur=pre[cur];
		}
		else if (a == 'D') {
			if(nxt[cur]!=-1) cur=nxt[cur];
		}
		else if (a == 'B') {
			if (cur != 0) {
				erase(cur);
				cur=pre[cur];
			}
		}
		else if (a == 'P') {
			cin >> b;
			insert(cur, b);
			cur=nxt[cur];
		}
	}
	int	res = nxt[0];
	while(res!=-1) {
		cout << dat[res];
		res=nxt[res];
	}

}