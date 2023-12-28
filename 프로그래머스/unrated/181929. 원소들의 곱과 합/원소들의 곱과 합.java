class Solution {
    public int solution(int[] num_list) {
        int sum = 0;
        int mux = 1;
        for(int i = 0; i < num_list.length; i++){
            sum += num_list[i];
            mux *= num_list[i];
        }
        return sum * sum > mux ? 1 : 0;
    }
}