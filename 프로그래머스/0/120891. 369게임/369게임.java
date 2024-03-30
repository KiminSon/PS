class Solution {
    public int solution(int order) {
        String s = order + "";
        s = s.replace("0", "");
        s = s.replace("1", "");
        s = s.replace("2", "");
        s = s.replace("4", "");
        s = s.replace("5", "");
        s = s.replace("7", "");
        s = s.replace("8", "");
        return s.length();
    }
}