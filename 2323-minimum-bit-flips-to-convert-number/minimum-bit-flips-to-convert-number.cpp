class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        while(start!=0 || goal!=0){
            int r1 = start&1;
            int r2 = goal&1;
            if(r1!=r2)ans++;
            start = (start>>1);
            goal = (goal>>1);
        }
        return ans;
    }
};