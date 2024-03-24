class Solution {
    public int solution(int n) {
        int answer = 1;
        int m = 1;
        while(true){
            m *= answer;
            if(m > n){
                answer--;
                break;
            }
            answer++;
        }
        return answer;
    }
}