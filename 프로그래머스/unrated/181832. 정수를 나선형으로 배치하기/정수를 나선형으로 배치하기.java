class Solution {
    public int[][] solution(int n) {
        int[][] answer = new int[n][n];
        int move = 0;
        int x = 0;
        int y = 0;
        
        for(int i = 0; i < n * n; i++){
            answer[y][x] = i + 1;
            if(move == 0)
            {
                if(x + 1 == n || answer[y][x + 1] != 0){
                    move = 1;
                    y++;
                }
                else
                    x++;
            }
            else if(move == 1)
            {
                if(y + 1 == n || answer[y + 1][x] != 0){
                    move = 2;
                    x--;
                }
                else
                    y++;
            }
            else if(move == 2)
            {
                if(x - 1 == -1 || answer[y][x - 1] != 0){
                    move = 3;
                    y--;
                }
                else
                    x--;
            }
            else if(move == 3)
            {
                if(y - 1 == -1 || answer[y - 1][x] != 0){
                    move = 0;
                    x++;
                }
                else
                    y--;
            }
        }
        return answer;
    }
}