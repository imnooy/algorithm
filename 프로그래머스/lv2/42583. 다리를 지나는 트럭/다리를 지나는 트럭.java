import java.util.*;

public class Pair {
    int num;
    int time;
    
    Pair(int num, int time) {
        this.num = num;
        this.time = time;
    }
}

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        Queue<Integer> q = new ArrayDeque<>();
        for(int num : truck_weights) {
            q.add(num);
        }
        
        Queue<Pair> bridge = new ArrayDeque<>();
        int curSize = 0;
        
        while(!q.isEmpty() || !bridge.isEmpty()) {
            answer++;
            while(!bridge.isEmpty()) {
                Pair p = bridge.peek();
                if(answer - p.time >= bridge_length) {
                    bridge.poll();
                    curSize -= p.num;
                }
                else break;
            }
            
            if((bridge.size() < bridge_length) && (!q.isEmpty() && curSize + q.peek() <= weight)) {
                int num = q.poll();
                curSize += num;
                bridge.add(new Pair(num, answer));
            }
        }
        
        return answer;
    }
}