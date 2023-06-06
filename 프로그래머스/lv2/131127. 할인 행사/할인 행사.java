import java.util.*;

class Solution {
    public int totalDays;
    
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        totalDays = discount.length;
        for(int i=0; i<totalDays - 9; i++) { //날짜 봄
            boolean isPossible=true;
            for(int j=0; j<want.length; j++) { //원하는 상품들 봄
                String w = want[j]; //원하는 상품
                int cnt = 0; //원하는 상품 개수
                int maxDay = i + 10;
                for(int k = i; k < maxDay; k++) {
                    if(discount[k].equals(w)) {
                        cnt++;
                    }
                }
                if(cnt < number[j]) {
                    isPossible = false;
                    break;
                }
            }
            if(isPossible) answer++;
        }
        
        return answer;
    }
}