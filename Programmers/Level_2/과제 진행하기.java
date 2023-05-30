import java.util.*;
import java.time.*;

public class Pair implements Comparable<Pair>{
    String name;
    int start;;
    int minute;
    
    Pair(String name, int start, int minute) {
        this.name=name;
        this.start=start;
        this.minute=minute;
    }
    
    public int compareTo(Pair p) {
        return (this.start)-(p.start);
    }
}

class Solution {
    public int toMinute(String date) {
        int hour = Integer.parseInt(date.substring(0, 2));
        int minute=Integer.parseInt(date.substring(3));
        return hour*60+minute;
    }
    
    public String[] solution(String[][] plans) {
        String[] answer;
        List<String> list = new ArrayList<>();
        
        Queue<Pair> deq = new ArrayDeque<>();
        Stack<Pair> st=new Stack<>();
        List<Pair>tmp=new ArrayList<>();
        
        for(int i=0; i<plans.length; i++) {
            String name=plans[i][0];
            String date = plans[i][1];
            int start=toMinute(date);
            int minute=Integer.parseInt(plans[i][2]);
            Pair p = new Pair(name, start, minute);
            tmp.add(p);
        }
        Collections.sort(tmp);
        
        for(Pair p : tmp) {
            deq.add(p);
        }
        
        boolean isSufficient=false;
        int nextStartTime=0;
        while(!deq.isEmpty()) {
            Pair p = null;
            if(isSufficient) {
                if(st.isEmpty()) {
                    p=deq.poll();
                }
                else {
                    p=st.pop();
                    p.start=nextStartTime;
                }
            }
            else p = deq.poll();
            if(deq.isEmpty() && st.isEmpty()) {
                list.add(p.name);
                break;
            }
            
            Pair next=deq.isEmpty() ? st.peek() : deq.peek(); //다음꺼 보자
            isSufficient=false;
            if((p.start+p.minute)>next.start) { //다 못 끝냄
                p.minute-=(next.start-p.start);
                st.push(p);
            }
            else {
                isSufficient=true;
                list.add(p.name);
                nextStartTime=p.start+p.minute;
            }
        }
        
        while(!st.isEmpty()) {
            list.add(st.pop().name);
        }
        
        answer=new String[list.size()];
        for(int i=0; i<list.size(); i++) {
            answer[i]=list.get(i);
        }
        
        return answer;
    }
}
