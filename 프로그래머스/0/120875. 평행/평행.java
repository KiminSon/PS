class Solution {
    public int solution(int[][] dots) {
        for(int i =0; i<4;i++) {

                float temp =gradient(dots[i],dots[(i+1)%4]);
                float temp2 =gradient(dots[(i+2)%4],dots[(i+3)%4]);

                if(temp==temp2) {
                    return 1;
                }
        }
        return 0;
    }
    public static float gradient(int[]a1,int[]a2) {
        float denom,mole;

            denom= a1[0]-a2[0];
            mole= a1[1]-a2[1];

        return mole/denom;
    }
}