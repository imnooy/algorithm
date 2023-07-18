import java.util.*;

class Solution {
    public String solution(String number, int k) {
        String answer = "";
        int kCopy = k;
        Stack<Character> st = new Stack<>();
        
        for(int i=0; i<number.length(); i++) {
            char c = number.charAt(i);
            while(!st.isEmpty() && k>0 && st.peek()<c) {
                //스택에 있는게 현재 수보다 작을때..
                k--; //작은거 한개 씀
                st.pop(); 
            }
            st.push(c); //아니면 답임
        }
        
        int cnt = 0;
        for(int i=0; i<number.length()-kCopy; i++) {
            answer+=(st.get(i)+"");
        }
        return answer;
    }
}