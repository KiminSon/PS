class Solution {
    public String solution(int age) {
        String answer = "";
        char[] alpha = {'a','b','c','d','e','f','g','h','i','j'} ;
        while(age > 0){
            answer = alpha[age%10] + answer;
            age /= 10;
        }
        return answer;
    }
}