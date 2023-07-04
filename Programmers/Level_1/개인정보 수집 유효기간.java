import java.util.*;
import java.time.LocalDate;

class Solution {
    public Map<String, Integer> m;
    public int[] solution(String today, String[] terms, String[] privacies) {
        int[] answer = {};
        List<Integer> list = new ArrayList<>();
        m=new HashMap<>();
        today = today.replace('.', '-');
        LocalDate t = LocalDate.parse(today);
        for(int i=0; i<terms.length; i++) {
            String tmp=terms[i];
            String c = tmp.substring(0, 1);
            int month=Integer.parseInt(tmp.substring(2));
            m.put(c, month);
        }
        
        for(int i=0; i<privacies.length; i++) {
            String dstr = privacies[i].substring(0, 10);
            dstr=dstr.replace('.', '-');
            LocalDate d = LocalDate.parse(dstr);
            String month = privacies[i].substring(11);
            d = d.plusMonths(m.get(month));
            if(t.compareTo(d)>=0) list.add(i+1);
        }
        answer=new int[list.size()];
        for(int i=0; i<list.size(); i++) {
            answer[i]=list.get(i);
        }
        return answer;
    }
}
