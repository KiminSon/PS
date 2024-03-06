class Solution {
    public int[] solution(int[] arr, int[] delete_list) {
        int arrSize = arr.length;
        for(int i = 0; i < arr.length; i++){
            for(int j = 0; j < delete_list.length; j++){
                if(arr[i] == delete_list[j]){
                    arr[i] = 0;
                    arrSize--;
                }
            }
        }
        int[] answer = new int[arrSize];
        arrSize = 0;
        for(int i = 0; i < arr.length; i++){
            if(arr[i] != 0){
                answer[arrSize] = arr[i];
                arrSize++;
            }
        }
        return answer;
    }
}