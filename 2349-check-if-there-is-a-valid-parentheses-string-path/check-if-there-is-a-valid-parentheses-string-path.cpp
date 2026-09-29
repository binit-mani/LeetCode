class Solution {
    bool visited[100][100][201];
public:
    void func(vector<vector<char>> &grid,int ind1,int ind2,int cnt,bool &ans){
        if(ans == true)return;
        if(cnt < 0)return;
        if(ind1 >= grid.size() || ind2 >= grid[0].size())return;
        int val = (grid[ind1][ind2] == '(')? 1:-1;
        cnt += val;
        if(ind1 == grid.size()-1 && ind2 == grid[0].size()-1)if(cnt == 0){
            ans = true;return;
        }
        if(cnt < 0)return;
        // MEMOIZATION CHECK: If we have already visited (ind1, ind2) with this exact cnt, return
        if (visited[ind1][ind2][cnt]) return;
        visited[ind1][ind2][cnt] = true;


        func(grid,ind1+1,ind2,cnt,ans);
        func(grid,ind1,ind2+1,cnt,ans);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        bool ans = false;
        func(grid,0,0,0,ans);
        return ans;
    }
};