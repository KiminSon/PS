class Solution {
    public int solution(String my_string) {
        my_string = my_string.replaceAll("[a-zA-Z]", "");
        int answer = 0;
        
        for(int i = 0; i < my_string.length();i++){
            answer += Integer.valueOf(my_string.charAt(i)) - 48;
        }
        
        return answer;
    }
}