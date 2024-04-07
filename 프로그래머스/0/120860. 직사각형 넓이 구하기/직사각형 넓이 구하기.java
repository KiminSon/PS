class Solution {
    public int solution(int[][] dots) {
        int x = 0, y = 0;
        for(int i = 1; i < 4; i++){
            if(dots[0][0] != dots[i][0] && dots[0][1] != dots[i][1]){
                x = dots[0][0] > dots[i][0] ? dots[0][0] - dots[i][0] : dots[i][0] - dots[0][0];
                y = dots[0][1] > dots[i][1] ? dots[0][1] - dots[i][1] : dots[i][1] - dots[0][1];
                break;
            }
        }
        return x * y;
    }
}