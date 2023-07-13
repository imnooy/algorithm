import java.util.*;

class Solution {
    public int[] solution(long begin, long end) {
        int[] answer = new int[(int)(end-begin)+1];
        for(long i=begin; i<=end; i++) {
            int block = i==1? 0 : 1;
            for(int j=2; j<=Math.sqrt(i); j++) {
                if(i%j==0) {
                    if(i/j>10000000) {
                        block=j;
                        continue;
                    }
                    block=(int)(i/j);
                    break;
                }
            }
            answer[(int)(i-begin)]=block;
        }

        return answer;
    }
}

/*
[444247,1447178,9009009,10000000]
*/