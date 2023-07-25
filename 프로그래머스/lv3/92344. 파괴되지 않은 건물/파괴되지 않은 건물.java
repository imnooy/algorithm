class Solution {
    public int solution(int[][] board, int[][] skill) {
        int answer = 0;
        int[][] record = new int[board.length + 1][board[0].length + 1];
        for(int i = 0; i < skill.length; i++) {
            int type = skill[i][0];
            int r1 = skill[i][1];
            int c1 = skill[i][2];
            int r2 = skill[i][3];
            int c2 = skill[i][4];
            int degree = skill[i][5];
            
            if(type == 1) {
                record[r1][c1] += -degree;
                record[r1][c2 + 1] += degree;
                record[r2 + 1][c1] += degree;
                record[r2 + 1][c2 + 1] += -degree;
            }
            else {
                record[r1][c1] += degree;
                record[r1][c2 + 1] += -degree;
                record[r2 + 1][c1] += -degree;
                record[r2 + 1][c2 + 1] += degree;
            }
        }
        
        //행 누적
        for(int i = 0; i < record.length; i++) {
            for(int j = 1; j < record[0].length; j++) {
                record[i][j] += record[i][j - 1];
            }
        }
        
        //열 누적
        for(int j = 0; j < record[0].length; j++) {
            for(int i = 1; i < record.length; i++) {
                record[i][j] += record[i - 1][j];
            }
        }
        
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[0].length; j++) {
                // System.out.print(record[i][j] + " ");
                if(board[i][j] + record[i][j] >= 1) answer++; 
            }
            // System.out.println();
        }
        
        return answer;
    }
}