class Solution {
    public String[] solution(String[] todo_list, boolean[] finished) {
        int t = 0;
        for(int i = 0; i < finished.length; i++){
            if(!finished[i]){
                t++;
            }
        }
        String[] answer = new String[t];
        t = 0;
        for(int i = 0; i < finished.length; i++){
            if(!finished[i]){
                answer[t] = todo_list[i];
                t++;
            }
        }
        return answer;
    }
}