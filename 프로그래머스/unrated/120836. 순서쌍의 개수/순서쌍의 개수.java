class Solution {
    public int solution(int n) {
        int answer = 0;
        for(int i = 1; i * i < n; i++)
            if(n % i == 0)
                answer++;
        return Math.sqrt(n) % 1 == 0 ? 1 + answer * 2 : answer * 2;
    }
}