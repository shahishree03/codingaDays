class Solution {
    private:
    void dfs(int sr, int sc,vector<vector<int>>& ans, vector<vector<int>>&img ,int newColor, int delRow[], int delCol[], int inicol )
    {
        ans[sr][sc]=newColor;
        int m = img.size();
        int n = img[0].size();
        for(int i=0;i<4;i++)
        {
            int nr= sr+delRow[i];
            int nc = sc+ delCol[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n&& ans[nr][nc]!=newColor && img[nr][nc]==inicol)
            {
             dfs(nr, nc, ans, img, newColor, delRow, delCol, inicol);
            }
            
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int intColor =image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[]={-1,0, 1, 0};
        int delCol[] ={0, 1,0, -1};
        dfs(sr, sc, ans, image, color, delRow, delCol, intColor);
        return ans;
    }
};
