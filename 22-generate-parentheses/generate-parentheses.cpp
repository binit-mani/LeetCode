class Solution {
public:
    bool isValid(string s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else balance--;
            if (balance < 0) return false;
        }
        return balance == 0;
    }
    void generateAll(int n,string curr,vector<string> &s){
        if(curr.size() == 2*n){
            s.push_back(curr);
            return;
        }
        generateAll(n,curr+'(',s);
        generateAll(n,curr+')',s);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        generateAll(n,"(",s);
        vector<string> ans;
        for(int i = 0;i<s.size();i++){
            if(isValid(s[i]))ans.push_back(s[i]);
        }
        return ans;
    }
};