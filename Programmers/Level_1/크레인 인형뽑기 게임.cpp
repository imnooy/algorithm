#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int sz = board.size(); //n
	int arr[36][36]; //인형 좌표
	int top[36]; //각 열의 맨 위 행 정보
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
		int col = moves[i] - 1; //집어야하는 열
		if (top[col] != sz) {
			int row = top[col]; //제거해야 할 인형의 행 위치
			int doll = arr[row][col]; //제거해야 할 인형
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