class Solution {
    public int solution(int[] arr1, int[] arr2) {
        if(arr1.length > arr2.length)
            return 1;
        if(arr1.length < arr2.length)
            return -1;
        
        int arr1sum = 0;
        for(int i = 0 ; i < arr1.length; i++){
            arr1sum += arr1[i];
        }
        
        int arr2sum = 0;
        for(int i = 0 ; i < arr2.length; i++){
            arr2sum += arr2[i];
        }
        
        return arr1sum == arr2sum ? 0 : arr1sum > arr2sum ? 1 : -1;
    }
}