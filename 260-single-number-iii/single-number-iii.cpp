class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor1=0,xor2 = 0;
        long long xo = 0;
        for(long long num:nums) xo ^= num;
        xo = (xo&(xo-1))^xo;
        for(long long num:nums){
            if(num&xo) xor1 ^= num;
            else xor2 ^= num;
        }
        return {(int)xor1,(int)xor2};
    }
};