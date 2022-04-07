#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	pair<int, int> l_cur = { 3, 0 };
	pair<int, int> r_cur = { 3, 2 };
	for (int i = 0; i < numbers.size(); i++) {
		int num = numbers[i];
		pair<int, int> pos = { (num - 1) / 3, (num - 1) % 3 };
		if (num == 0) pos = { 3, 1 };
		if (num == 1 || num == 4 || num == 7) {
			answer += "L";
			l_cur = pos;
		}
		else if (num == 3 || num == 6 || num == 9) {
			answer += "R";
			r_cur = pos;
		}
		else {
			int l_dis = abs(l_cur.first - pos.first) + abs(l_cur.second - pos.second); //왼손으로부터의 거리
			int r_dis = abs(r_cur.first - pos.first) + abs(r_cur.second - pos.second); //오른손으로부터의 거리
			if (l_dis < r_dis || ((l_dis == r_dis) && hand == "left")) {
				l_cur = pos;
				answer += "L";
			}
			else if (l_dis > r_dis || ((l_dis == r_dis) && hand == "right")) {
				r_cur = pos;
				answer += "R";
			}
		}
	}
	return answer;
}