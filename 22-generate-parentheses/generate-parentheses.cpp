class Solution {
public:
    void generateS(vector<string> &s,int n,string curr,int open,int close){
        if(curr.size() == 2*n){
            s.push_back(curr);
            return;
        }
        if(open<n){
            generateS(s,n,curr+'(',open+1,close);
        }
        if(close<open){
            generateS(s,n,curr+')',open,close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        generateS(s,n,"",0,0);
        return s;
    }
};