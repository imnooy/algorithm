import java.util.*;

class Solution {
    
    public long solution(int[] weights) {
        long answer = 0;
        long[]arr=new long[2001];
        Set<Integer> set=new TreeSet<>();
        
        for(int i=0; i<weights.length; i++) {
            arr[weights[i]]++;
            set.add(weights[i]);
        }
        
        for(int num : set) {
            answer+=(arr[num]*(arr[num]-1)/2);
            answer+=arr[num]*arr[2*num]; //2배
            if((3*num)%2==0) answer+=arr[num]*arr[3*num/2];
            if((4*num)%3==0) answer+=arr[num]*arr[4*num/3];
        }
        
        return answer;
    }
}

/*
100 2개
180
270
360
*/