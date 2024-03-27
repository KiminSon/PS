class Solution {
    public int[][] solution(int n) {
        int[][] answer = new int[n][n];
        int one = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == one){
                    answer[i][j] = 1;
                }else{
                    answer[i][j] = 0;
                }
            }
            one++;
        }
        return answer;
    }
}