import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        Arrays.sort(citations);
        for(int i=citations.length-1; i>=0; i--) {
            int h = citations[i]; //현재 h : 배열의 i번째 값
            int count = citations.length-i; //h번 이상 인용된 논문의 개수
            int hh=h;
            int before=i==0?0:citations[i-1];
            while(hh>before) {
                 if(count>=hh) {
                    return hh;
                }
                hh--;
            }
            
            if(count>=h) {
                return h;
            }
        }
        return answer;
    }
}
