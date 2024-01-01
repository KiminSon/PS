class Solution {
    public String solution(String str) {
        str = str.replace("a" , "");
        str = str.replace("e" , "");
        str = str.replace("i" , "");
        str = str.replace("o" , "");
        str = str.replace("u" , "");
        return str;
    }
}