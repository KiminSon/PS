import java.util.Arrays;

class Solution {
    public int solution(int[] arr) {
        Arrays.sort(arr);
        return arr[2] >= arr[0] + arr[1] ? 2 : 1;
    }
}