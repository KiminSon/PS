class Solution {
    public String solution(String code) {
        String answer = "";
        boolean mode = false;
        for(int i = 0; i < code.length(); i++){
            if(code.charAt(i) == '1'){
                if(mode){
                    mode = false;
                }else{
                    mode = true;
                }
            }
            if(mode && code.charAt(i) != '1' && i % 2 == 1){
                answer += code.charAt(i);
            }
            if(!mode && code.charAt(i) != '1' && i % 2 == 0){
                answer += code.charAt(i);
            }
            
        }
        if(answer.equals("")){
            answer = "EMPTY";
        }
        return answer;
    }
}