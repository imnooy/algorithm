import java.util.*;

class Solution {
    
    static Set<Integer> set;
    static List<Integer> list;
    static boolean[]isUsed;
    
    static boolean isSosu(int num) {
        if(num==1) return false;
        for(int i=2; i<num; i++) {
            if(num%i==0) return false;
        }
        return true;
    }
    
    static void addSet(String str) {
        int num=Integer.parseInt(str);
        if(num==0) return;
        if(!isSosu(num)) return ;
        
        set.add(num);
    }
    
    static void func(int k, String str) {
        if(k>=1) addSet(str);
        
        if(k==list.size()) {
            return;
        }
        
        for(int i=0; i<list.size(); i++) {
            if(!isUsed[i]) {
                isUsed[i]=true;
                String tmp=str;
                
                str+=list.get(i);
                func(k+1, str);
                
                str=tmp;
                isUsed[i]=false;
            }
        }
    }
    
    public int solution(String numbers) {
        set=new HashSet<>();
        list=new ArrayList<>();
        
        int answer = 0;
        for(char c:numbers.toCharArray()) {
            list.add(c-'0');
        }
        isUsed=new boolean[list.size()];
        func(0, "");
        
        return set.size();
    }
}
