class Solution {
    public int[] solution(int num, int total) {
        int[] answer = new int[num];
        for(int i = 0; i < num; i++){
            answer[i] = total / num - (num - 1) / 2 + i;
        }
        return answer;
    }
}