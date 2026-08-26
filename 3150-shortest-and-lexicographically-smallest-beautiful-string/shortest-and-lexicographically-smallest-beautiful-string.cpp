class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> v;
        int l = 0,r = 0;
        int cnt = 0;
        if(s[0] == '1')cnt++;
        while(l<s.size() && r<s.size()){
            if(cnt == k){
                v.push_back(s.substr(l,r-l+1));
                if(s[l] == '1')cnt--;
                l++;
            }
            else if(cnt<k){
                r++;
                if(r>=s.size())break;
                if(s[r] == '1')cnt++;
            }
            else {
                if(s[l] == '1')cnt--;
                l++;
            }
        }
        sort(v.begin(),v.end(),[](const string a,const string b){
            if(a.size()!=b.size())
                return a.size()<b.size();
            return a<b;
        });
        if(v.size() == 0)return "";
        return v[0];
    }
};