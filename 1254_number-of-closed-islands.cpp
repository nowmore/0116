#include "all.h"


static auto __=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    int next[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    bool dfs(vector<vector<int>>& grid, int x, int y){
        if(x >= grid.size() || y >= grid[x].size())
            return false;

        bool res = true;    
        grid[x][y] = 1;
        if(x == 0 || y == 0 || x == grid.size() - 1|| y == grid[x].size() - 1)
            res = false;
        for(int i=0; i<4; ++i) {
            int tx = x + next[i][0];
            int ty = y + next[i][1];

            if(tx < 0 || ty < 0 || tx >= grid.size() || ty >= grid[tx].size()
            || grid[tx][ty])
                continue;

            res = (res && dfs(grid, tx, ty));
        }
        return res;
    }

void p(vector<vector<int>> &v) {
    for(int i=0; i<v.size(); ++i) {
        for(int j=0; j<v[i].size(); ++ j)
        cout << v[i][j];
        cout << endl;
    }
}
public:
    int closedIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        int cnt = 0;
        vector<vector<int>> v;
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid[i].size(); ++j) {
                if(!grid[i][j]) {
                    v.clear();
                    v = grid;
                    if(dfs(grid, i, j)) {
                        cout << i << '\t' << j << endl;
                        ++cnt;
                        p(v);
                        cout << endl;
                    }
                }
            }
        }
        return cnt;
    }
};


int main(int argc, char **argv){
    Solution so;
    vector<vector<int>> grid = 
    {{0,0,1,1,0,1,0,0,1,0},
     {1,1,0,1,1,0,1,1,1,0},
     {1,0,1,1,1,0,0,1,1,0},
     {0,1,1,0,0,0,0,1,0,1},
     {0,0,0,0,0,0,1,1,1,0},
     {0,1,0,1,0,1,0,1,1,1},
     {1,0,1,0,1,1,0,0,0,1},
     {1,1,1,1,1,1,0,0,0,0},
     {1,1,1,0,0,1,0,1,0,1},
     {1,1,1,0,1,1,0,1,1,0}};
     cout << so.closedIsland(grid) << endl;
    return 0;
}