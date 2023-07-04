import java.util.*;

class Solution {
    static class Pair {
        int from;
        int to;

        Pair(int from, int to) {
            this.from = from;
            this.to = to;
        }
    }
    
    //num개가 from에서 to로 가는데 그 외에 하나는 mid번이다
    public void hanoi(int num, int from, int mid, int to) {
        if(num == 1) {
            list.add(new Pair(from, to));
            return;
        }
        
        hanoi(num-1, from, to, mid);
        list.add(new Pair(from, to));
        hanoi(num-1, mid, from, to);
    }
    
    public List<Pair> list;
    
    public int[][] solution(int n) {
        
        list = new ArrayList<>();
        hanoi(n, 1, 2, 3);
        int[][] answer = new int[list.size()][2];
        for(int i = 0; i < list.size(); i++) {
            answer[i][0] = list.get(i).from;
            answer[i][1] = list.get(i).to;
        }
        return answer;
    }
}