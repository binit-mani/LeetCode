class Solution {
public:
    bool checkValidString(string s) {
        // int cnt = 0,str = 0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i] == '(')cnt++;
        //     else if(s[i] == ')')cnt--;
        //     else if(cnt !=0) str++;
        //     if(cnt == -1){
        //         if(str == 0){
        //             return false;
        //         }
        //         cnt++;str--;
        //     }
        // }
        // if(cnt) return false;
        // return true;

        stack<int> sta,st;
        for(int i=0;i<s.size();i++){
            if(s[i] == ')'){
                if(sta.empty()){
                    if(st.empty())return false;
                    else st.pop();
                }
                else sta.pop();
            }
            else if(s[i] == '(')sta.push(i);
            else st.push(i);
        }
        while(!sta.empty() && !st.empty()){
            if(sta.top()>st.top())return false;
            sta.pop();
            st.pop();
        }
        if(!sta.empty()) return false;
        return true;
    }
};