class Solution {
    
    public class Pair {
        int need; //필요한 최소 피로도
        int use; //소모 피로도
        
        Pair(int need, int use) {
            this.need=need;
            this.use=use;
        }
    }
    
    public void dfs(int cnt) { //현재 탐험한 던전 개수
        for(int i=0; i<arr.length; i++) {
            if(arr[i].need>curK) continue; //해당 던전을 탐험하기 위해 가지고 있어야 하는 최소한의 피로도세요?
            if(isused[i]) continue;
            isused[i]=true;
            curK-=arr[i].use;
            ans=Math.max(ans, cnt+1);
            dfs(cnt+1);
            curK+=arr[i].use;
            isused[i]=false;
        }
    }
    
    public int curK; //k 복사
    public Pair[] arr; //던전들의 정보 배열
    public boolean[]isused;
    public int ans; //최대 던전 수
    
    public int solution(int k, int[][] dungeons) {
        int answer = -1;
        curK=k;
        arr=new Pair[dungeons.length];
        isused=new boolean[dungeons.length];
        for(int i=0; i<dungeons.length; i++) {
            arr[i]=new Pair(dungeons[i][0], dungeons[i][1]);
        }
        ans=Integer.MIN_VALUE; //최대 던전 수 구하기
        dfs(0); //탐험 던전 개수
        answer=ans;
        return answer;
    }
}
