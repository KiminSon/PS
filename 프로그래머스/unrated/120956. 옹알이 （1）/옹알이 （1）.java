class Solution {
    public int solution(String[] s) {
        int answer = 0;
        for(int i = 0; i < s.length; i++){
            s[i] = s[i].replace("aya", "1");
            s[i] =  s[i].replace("ye", "1");
            s[i] = s[i].replace("woo", "1");
            s[i] = s[i].replace("ma", "1");
            s[i] = s[i].replace("1", "");
            if(s[i].isEmpty())
                answer++;
        }
        return answer;
    }
}