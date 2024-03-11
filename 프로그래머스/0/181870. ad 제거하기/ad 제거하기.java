class Solution {
    public String[] solution(String[] strArr) {
        int idx = 0;
        for(int i = 0; i < strArr.length; i++)
            if(!strArr[i].contains("ad"))
                idx++;
        
        String[] answer = new String[idx];
        idx = 0;
        for(int i = 0; i < strArr.length; i++){
            if(!strArr[i].contains("ad")){
                answer[idx] = strArr[i];
                idx++;
            }
        }
        return answer;
    }
}