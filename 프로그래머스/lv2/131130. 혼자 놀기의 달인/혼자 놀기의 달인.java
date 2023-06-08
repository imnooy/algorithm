import java.util.*;

class Solution {
    public int[]arr;
    public boolean[]visited;
    
    public int visit(int index) {
        int in=index;
        int cur=arr[in];
        visited[in]=true;
        int cnt=1;
        while(true) {
            in=cur;
            cur=arr[in];
            if(cur==arr[index]) break;
            visited[in]=true;
            cnt++;
        }
        return cnt;
    }
    
    public int solution(int[] cards) {
        int answer = 0;
        arr=new int[cards.length+1];
        visited=new boolean[cards.length+1];
        for(int i=1; i<=cards.length; i++) {
            arr[i]=cards[i-1];
        }
        
        List<Integer> list=new ArrayList<>();
        
        for(int i=1; i<=cards.length; i++) {
            if(visited[i]) continue;
            int cnt=visit(i);
            list.add(cnt);
            System.out.println(cnt);
        }
        Collections.sort(list);
        if(list.size()==1) return 0;
        answer=(list.get(list.size()-1))*(list.get(list.size()-2));
        
        return answer;
    }
}