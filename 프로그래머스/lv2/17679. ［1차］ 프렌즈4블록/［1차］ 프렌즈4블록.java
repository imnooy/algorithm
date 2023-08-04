import java.util.*;

class Solution {
    static class Pair {
        int x; 
        int y;
        
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public static boolean boom(int m, int n) {
        List<Pair> list = new ArrayList<>();
        boolean[][] isused = new boolean[m][n];
        
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n - 1; j++) {
                char c = arr[i][j];
                if(c == '0') continue;
                if(arr[i][j+1] != c || arr[i + 1][j] != c || arr[i + 1][j + 1] != c) continue;
                if(!isused[i][j]) {
                    list.add(new Pair(i, j));
                }
                isused[i][j]=true;
                
                if(!isused[i][j+1]) {
                    list.add(new Pair(i, j+1));
                }
                isused[i][j+1]=true;
                
                if(!isused[i+1][j]) {
                    list.add(new Pair(i+1, j));
                }
                isused[i+1][j]=true;
                
                if(!isused[i+1][j+1]) {
                    list.add(new Pair(i+1, j+1));
                }
                isused[i+1][j+1]=true;
                
            }
        }
        
        for(Pair p : list) {
            arr[p.x][p.y] = '0';
            ans++;
        }
        
        if(list.size() > 0) return true;
        return false;
    }
    
    public static void down(int m, int n) {
        for(int j = 0; j < n; j++) {
            int des = m - 1;
            boolean desUsed = false;
            for(int i = m - 1; i >= 0; i--) {
                if(arr[i][j] == '0' && !desUsed) {
                    des = i;
                    desUsed = true;
                }
                else if(arr[i][j] != '0') {
                    arr[des][j] = arr[i][j];
                    if(des != i) arr[i][j] = '0';
                    des--;
                    if(des >= 0 && arr[des][j] != '0') desUsed = false;
                }
            }
        }
    }
    
    static int ans;
    static char[][] arr;
    
    public static void print(int m, int n) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
    
    public int solution(int m, int n, String[] board) {
        int answer = 0;
        ans = 0;
        arr = new char[m][n];
        for(int i = 0; i < board.length; i++) {
            arr[i] = board[i].toCharArray();
        }
        
        while(true) {
            if(!boom(m, n)) break;
            down(m, n);
        }
        answer = ans;
        return answer;
    }
}