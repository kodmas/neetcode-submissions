class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfsmaxArea(vector<vector<int>>& grid, int& area, int r, int c){
        if (r < 0 || c < 0 || r >= grid.size() ||
            c >= grid[0].size() || grid[r][c] == 0) {
            return;
        }

        grid[r][c] = 0;
        area++;

        for (int i=0;i<4;i++) dfsmaxArea(grid, area, r + directions[i][0], c + directions[i][1]);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int ans = 0;

        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                if(grid[r][c] == 1){
                    int curArea = 0;
                    dfsmaxArea(grid, curArea, r, c);
                    if(curArea >= ans) ans = curArea;
                }
            }
        }

        return ans;
        
    }
};
