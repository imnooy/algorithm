import java.util.*;

class Solution {
    
    public int days(int progress, int speed) { //필요한 작업일 반환
        int ans = (100-progress)/speed;
        int r=(100-progress)%speed;
        
        if(r!=0) ans+=1;
        
        return ans;
    }
    
    public int[] solution(int[] progresses, int[] speeds) {
        int size=progresses.length;
        int[] arr = new int[size];
        boolean[] isDeployed=new boolean[size];
        List<Integer> ans = new ArrayList<>();
        for(int i=0; i<size; i++) {
            arr[i]=days(progresses[i], speeds[i]);
        }

        int curIndex=0;
        while(true) {
            if(curIndex>=size) break;
            int cnt=1;
            System.out.println("현재 curIndex: "+curIndex);
            int max=arr[curIndex];
            int min=arr[curIndex];
            boolean isJChanged=false;
            for(int j=curIndex+1; j<size; j++) {
                if(arr[curIndex]<arr[j]) {
                    ans.add(cnt);
                    cnt=1;
                    curIndex=j;
                    isJChanged=true;
                    break;
                }
                else {
                    cnt++;
                }
            }
            if(!isJChanged) {
                ans.add(cnt);
                break;
            }
        }
        int answer[]=new int[ans.size()];
        for(int i=0; i<ans.size(); i++) {
            answer[i]=ans.get(i);
        }
        
        return answer;
    }
}
