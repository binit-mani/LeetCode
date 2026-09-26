class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> mpp;
        for(int i=0;i<knowledge.size();i++){
            mpp[knowledge[i][0]] = knowledge[i][1];
        }
        int i=0;
        string ans = "";
        while(i<s.size()){
            if(s[i] == '('){
                string t = "";
                i++;
                while(i<s.size() && s[i] != ')'){
                    t += s[i];i++;
                }
                i++;
                if(mpp.find(t) == mpp.end()) ans += '?';
                else ans += mpp[t];
            }
            else {
                ans += s[i++];
            }
        }
        return ans;
    }
};