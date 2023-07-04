class Solution {
    public int delIndex, pickIndex, delStart, pickStart;
    public long toDel, toPick;
    public boolean delEnd, pickEnd;
    
    public void startDel(int[] deliveries, int cap) {
        toDel = 0;
        delStart = delIndex;
        if(delEnd) return;
        while(delIndex>=0) {
            int del = deliveries[delIndex];
            if(toDel == 0 && del == 0) delStart--;
            if(toDel + del <= cap) {
                toDel += del;
                deliveries[delIndex] = 0; //여긴 배달
                if(delIndex == 0) delEnd = true;
            }
            else { //배달 해야 한다.
                deliveries[delIndex] = (int)(toDel + del - cap);
                break;
            }
            delIndex--;
        }
    }
    
    public void startPick(int[] pickups, int cap) {
        toPick = 0;
        pickStart = pickIndex;
        if(pickEnd) return;
        while(pickIndex>=0) {
            int pick = pickups[pickIndex];
            if(toPick == 0 && pick == 0) pickStart--;
            if(toPick + pick <= cap) {
                toPick += pick;
                pickups[pickIndex] = 0; //여긴 배달
                if(pickIndex == 0) pickEnd = true;
            }
            else { //픽업 해야 한다.
                pickups[pickIndex] = (int)(toPick + pick - cap);
                break;
            }
            pickIndex--;
        }
    }
    
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;
        delIndex = n-1; //배달 해야하는 인덱스
        pickIndex = n-1; //픽업 해야하는 인덱스
        
        delStart = n-1; //배달 시작한 인덱스
        pickStart = n-1; //픽업 시작한 인덱스
        
        toDel = 0; //지금까지 배달가능한 택배 상자 수
        toPick = 0; //지금까지 픽업가능한 택배 상자 수
        delEnd = false;
        pickEnd = false;
        
        while(!delEnd || !pickEnd) {
            startDel(deliveries, cap);
            startPick(pickups, cap);
            answer+= (Math.max((delStart+1), (pickStart+1)) * 2);
        }
        
        return answer; 
    }
}