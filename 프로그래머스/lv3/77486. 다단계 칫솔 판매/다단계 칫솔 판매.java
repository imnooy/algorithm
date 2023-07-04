import java.util.*;

class Solution {
    public Map<String, String> map;
    public Map<String, Integer> ans;
    
    public void sell(String name, int money) {
        String enr = name;
        String ref = map.get(enr);
        int myMoney, refMoney;
        while(true) {
            if(money == 0) break;
            refMoney = money * 10 / 100;
            myMoney = money - refMoney;
            
            int mine = ans.get(enr);
            int refs = ans.get(ref);
            
            // System.out.println(enr+"가 "+myMoney+"가지고 "+ref+"가 "+refMoney+"가짐");
            
            ans.put(enr, mine + myMoney);
            // if(map.get(ref).equals("-")) {
            //     ans.put(ref, refs + refMoney);
            // }
            
            enr = ref;
            if(enr.equals("-")) break;
            ref = map.get(enr);
            money = refMoney;
        }
    }
    
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        map = new HashMap<>();
        ans = new HashMap<>();
        
        int[] answer = new int[enroll.length];
        for(int i = 0; i < enroll.length; i++) {
            map.put(enroll[i], referral[i]);
            ans.put(enroll[i], 0);
        }
        ans.put("-", 0);
        
        for(int i=0; i<seller.length; i++) {
            sell(seller[i], amount[i] * 100);
        }
        
        for(int i=0; i<enroll.length; i++) {
            answer[i]=ans.get(enroll[i]);
        }
        return answer;
    }
}