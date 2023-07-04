import java.util.*;

public class Pair {
    int num;
    int index;
    
    Pair(int num, int index) {
        this.num = num;
        this.index = index;
    }
}

class Solution {    
    public Stack<Pair> st;
    public Pair[] arr;
    
    public int[] solution(int[] numbers) {
        int[] answer = {};
        answer=new int[numbers.length];
        st=new Stack<>();
        arr=new Pair[numbers.length];
        
        for(int i=0; i<numbers.length; i++) {
            answer[i]=-1;
            if(!st.isEmpty()) {
                int curNum=numbers[i];
                while(!st.isEmpty() && st.peek().num<curNum) { //현재 수가 스택 제일 위 수보다 클 때
                    Pair top=st.peek();
                    answer[top.index]=curNum;
                    st.pop();
                }  
            }
            st.push(new Pair(numbers[i], i));
        }
        
        return answer;
    }
}
