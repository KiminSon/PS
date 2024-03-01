class Solution {
    public int solution(String myString, String pat) {
        return myString.replace('A', 'T').replace('B', 'A').replace('T', 'B').contains(pat) ? 1 : 0;
    }
}