import java.util.Arrays;

class Solution {
    public String solution(String my_string, int[] indices) {
        Arrays.sort(indices);
        StringBuilder sb = new StringBuilder(my_string);
        for (int i = indices.length - 1; i >= 0; i--) {
            if (indices[i] < sb.length()) {
                sb.deleteCharAt(indices[i]);
            }
        }
        return sb.toString();
    }
}