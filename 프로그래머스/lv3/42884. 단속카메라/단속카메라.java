import java.util.*;

public class Pair implements Comparable<Pair> {
    int start;
    int end;
    
    Pair(int start, int end) {
        this.start = start;
        this.end = end;
    }
    
    @Override
    public int compareTo(Pair p) {
        int ans = this.end - p.end; //진출 기준
        return ans;
    }
    
    @Override
    public String toString() {
        return "["+start+"~"+end+"]";
    }
}

class Solution {
    public int solution(int[][] routes) {
        Pair[] list = new Pair[routes.length];
        int answer = 0;
        
        for(int i=0; i<routes.length; i++) {
            list[i]=new Pair(routes[i][0], routes[i][1]);    
        }
        Arrays.sort(list);
        // for(Pair p : list) System.out.println(p);
        
        int camera=list[0].end; //카메라 한대 설치
        answer++;
        for(int i=1; i<list.length; i++) {
            if(list[i].start<=camera) continue;
            camera=list[i].end;
            answer++;
        }
        return answer;
    }
}