class Solution {
    public int solution(String ineq, String eq, int n, int m) {        
        if(eq.equals("=") && n == m){
            return 1; 
        }
        
        if(ineq.equals("<") && n < m){
            return 1;
        }
        
        if(ineq.equals(">") && n > m){
            return 1;
        }
        return 0;
    }
}