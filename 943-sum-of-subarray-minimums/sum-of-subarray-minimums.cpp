class Solution {
public:
    long long mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        long long n = arr.size();
        vector<long long> nse(n);
        stack<long long> st;
        for(long long i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = (st.empty())?n:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        vector<long long> psee(n);
        for(long long i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            psee[i] = (st.empty())?-1:st.top();
            st.push(i);
        }
        long long total = 0;
        for(long long i=0;i<n;i++){
            long long right = nse[i]-i;
            long long left = i-psee[i];
            total += (right*left*arr[i])%mod;
            total %= mod;
        }
        return (int)total;
    }
};