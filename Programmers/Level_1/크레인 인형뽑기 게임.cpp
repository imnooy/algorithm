#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int sz = board.size(); //n
	int arr[36][36]; //���� ��ǥ
	int top[36]; //�� ���� �� �� �� ����
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			arr[i][j] = board[i][j];
		}
	}

	for (int j = 0; j < sz; j++) {
		for (int i = sz - 1; i >= 0; i--) {
			if (arr[i][j] == 0) break;
			top[j] = i;
		}
	}

	stack<int> st;
	for (int i = 0; i < moves.size(); i++) {
		int col = moves[i] - 1; //������ϴ� ��
		if (top[col] != sz) {
			int row = top[col]; //�����ؾ� �� ������ �� ��ġ
			int doll = arr[row][col]; //�����ؾ� �� ����
			if (!st.empty() && st.top() == doll) {
				st.pop();
				answer += 2;
			}
			else st.push(doll);
			top[col] += 1;
		}
	}

	return answer;
}