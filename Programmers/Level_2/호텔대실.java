import java.util.*;

class Pair implements Comparable<Pair>{
    int start;
    int end;
    
    Pair(int x, int y) {
        this.start=x;
        this.end=y;
    }
    
    public int compareTo(Pair p) {
        int ans=this.start-p.start;
        if(ans==0) ans=this.end-p.end;
        return ans;
    }
}

class Room {
    int end;
    boolean isEmpty;
    
    Room(int end, boolean isEmpty) {
        this.end=end;
        this.isEmpty=isEmpty;
    }
}



class Solution {
    int getMinute(String str) {
        int h=Integer.parseInt(str.substring(0, 2));
        int m=Integer.parseInt(str.substring(3));

        return (h*60)+m;
    }
    
    public PriorityQueue<Pair> pq;
    public List<Room> list;
    
    public int solution(String[][] book_time) {
        int answer = 0;
        // System.out.println(getMinute("09:59"));
        pq = new PriorityQueue<>();
        list = new ArrayList<>();
        
        for(int i=0; i<book_time.length; i++) {
            int start=getMinute(book_time[i][0]);
            int end=getMinute(book_time[i][1]);
            
            pq.add(new Pair(start, end+10));
        }
        
        while(!pq.isEmpty()) {
            // Pair p = pq.poll();
            // System.out.println(p.x + " " +p.y);
            
            Pair p=pq.poll();
            
            boolean isPossible=false;
            for(int i=0; i<list.size(); i++) {
                Room room = list.get(i);
                if(!room.isEmpty && room.end>p.start) continue;
                
                room.isEmpty=false;
                room.end=p.end;
                isPossible=true;
                break;
            }
            
            if(!isPossible) {
                Room newRoom = new Room(p.end, false);
                list.add(newRoom);
            }
        }
        
        return list.size();
    }
}
