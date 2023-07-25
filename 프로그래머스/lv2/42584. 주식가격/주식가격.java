import java.util.*;

class Solution {
    static class Pair {
        int price;
        int second;
        
        Pair(int price, int second) {
            this.price = price;
            this.second = second;
        }
    }
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<Pair> st = new Stack<>();
        
        for(int i = 0; i < prices.length; i++) {
            Pair p = new Pair(prices[i], i);
            if(st.isEmpty()) {
                st.push(p);
            }
            else {
                Pair top = st.peek();
                while(!st.isEmpty() && st.peek().price > p.price) {
                    top = st.pop();
                    answer[top.second] = i - top.second;
                }
                st.push(p);
            }
        }
        
        while(!st.isEmpty()) {
            Pair p = st.pop();
            answer[p.second] = prices.length - p.second - 1;
        }
        
        return answer;
    }
}