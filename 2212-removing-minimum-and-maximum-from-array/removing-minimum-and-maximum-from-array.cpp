class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        int n = nums.size();
        int pos_m = 0,pos_mi = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == maxi){
                pos_m = i;
            }
            if(nums[i] == mini)pos_mi = i;
        }
        if(pos_m == pos_mi) return min(pos_mi+1,n-pos_mi);
        if(pos_m > pos_mi){
            return min({pos_mi+1+n-pos_m,pos_m+1,n-pos_mi});
        }
        if(pos_m < pos_mi){
            return min({pos_m+1+n-pos_mi,pos_mi+1,n-pos_m});
        }
        return 0;
    }
};