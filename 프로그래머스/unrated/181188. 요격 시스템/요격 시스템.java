import java.util.*;

public class Pair implements Comparable<Pair> {
    int x;
    int y;
    
    Pair(int x, int y) {
        this.x=x;
        this.y=y;
    }
    
    @Override
    public int compareTo(Pair p) {
        int ans = this.y-p.y;
        if(ans==0) return this.x-p.x;
        return ans;
    }
}

class Solution {
    public boolean isRange(Pair cur, Pair p) {
        if(p.x < cur.y) return true;
        return false;
    }
    
    public int solution(int[][] targets) {
        int answer = 0;
        List<Pair> list = new ArrayList<>();
        for(int i=0; i<targets.length; i++) {
            Pair p = new Pair(targets[i][0], targets[i][1]);
            list.add(p);
        }
        
        Collections.sort(list);
        
        Pair cur = new Pair(-1, 0);
        
        for(Pair p : list) {
            if(isRange(cur, p)) continue;
            answer++;
            cur=p;
        }
        
        return answer;
    }
}