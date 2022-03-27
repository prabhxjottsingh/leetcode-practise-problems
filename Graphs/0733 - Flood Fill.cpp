//Problem Link: https://leetcode.com/problems/flood-fill/

//Time Complexity: O(N*M)
//Space Complexity: O(1)

class Solution {
private:
    void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>> &image){
        int n = image.size();
        int m = image[0].size();
        
        if(i < 0 || j < 0 || i > n-1 || j > m)
            return;
        
        if(image[i][j] != initialColor)
            return;
        
        image[i][j] = newColor;
        
        dfs(i + 1, j, initialColor, newColor, image);
        dfs(i - 1, j, initialColor, newColor, image);
        dfs(i, j - 1, initialColor, newColor, image);
        dfs(i, j + 1, initialColor, newColor, image);
    }
        
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int intialColor = image[sr][sc];
        if(intialColor != newColor)
            dfs(sr, sc, intialColor, newColor, image);
        
        return image;
    }
};