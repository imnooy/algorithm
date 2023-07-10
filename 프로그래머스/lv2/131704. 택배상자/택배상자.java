import java.util.*;

class Solution {
    public int solution(int[] order) {
        int answer = 0;
        Stack<Integer> st = new Stack<>();
        int n=order.length;
        boolean[] isused=new boolean[n+1];
        int cur = 1; //지금 들어오는 박스 번호
        for(int i=0; i<n; i++) {
            if(cur==order[i]) {
                cur++;
                isused[order[i]]=true;
                answer++;
            }
            else {
                if(cur<order[i]) { //들어오는 박스보다 더 큰 박스를 실어야할 때
                    st.push(order[i]-1);
                    isused[order[i]]=true;
                    answer++;
                    cur=order[i]+1; //들어오는 박스는 하나 증가..
                }
                else {
                    if(st.isEmpty()) return answer;
                    int num = st.peek();
                    if(num==order[i]) {
                        st.pop();
                        isused[num]=true;
                        if(!isused[num-1]) st.push(num-1);
                        answer++;
                    }
                    else return answer;
                }
            }
        }
        return answer;
    }
}