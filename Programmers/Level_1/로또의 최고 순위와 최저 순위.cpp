#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	int res = 0;
	int zero_cnt = 0;
	for (int i = 0; i < lottos.size(); i++) {
		if (lottos[i] == 0) {
			zero_cnt++;
			continue;
		}
		for (int j = 0; j < win_nums.size(); j++) {
			if (lottos[i] == win_nums[j]) {
				res++;
			}
		}
	}


	vector<int> answer;
	switch (res + zero_cnt) {
	case 6:
		answer.push_back(1);
		break;
	case 5:
		answer.push_back(2);
		break;
	case 4:
		answer.push_back(3);
		break;
	case 3:
		answer.push_back(4);
		break;
	case 2:
		answer.push_back(5);
		break;
	default:
		answer.push_back(6);
	}

	switch (res) {
	case 6:
		answer.push_back(1);
		break;
	case 5:
		answer.push_back(2);
		break;
	case 4:
		answer.push_back(3);
		break;
	case 3:
		answer.push_back(4);
		break;
	case 2:
		answer.push_back(5);
		break;
	default:
		answer.push_back(6);
	}

	return answer;
}