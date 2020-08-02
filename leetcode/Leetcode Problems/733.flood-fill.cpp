/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 *
 * https://leetcode.com/problems/flood-fill/description/
 *
 * algorithms
 * Easy (55.22%)
 * Likes:    1267
 * Dislikes: 194
 * Total Accepted:    171.6K
 * Total Submissions: 310.7K
 * Testcase Example:  '[[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2'
 *
 * 
 * An image is represented by a 2-D array of integers, each integer
 * representing the pixel value of the image (from 0 to 65535).
 * 
 * Given a coordinate (sr, sc) representing the starting pixel (row and column)
 * of the flood fill, and a pixel value newColor, "flood fill" the image.
 * 
 * To perform a "flood fill", consider the starting pixel, plus any pixels
 * connected 4-directionally to the starting pixel of the same color as the
 * starting pixel, plus any pixels connected 4-directionally to those pixels
 * (also with the same color as the starting pixel), and so on.  Replace the
 * color of all of the aforementioned pixels with the newColor.
 * 
 * At the end, return the modified image.
 * 
 * Example 1:
 * 
 * Input: 
 * image = [[1,1,1],[1,1,0],[1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation: 
 * From the center of the image (with position (sr, sc) = (1, 1)), all pixels
 * connected 
 * by a path of the same color as the starting pixel are colored with the new
 * color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally
 * connected
 * to the starting pixel.
 * 
 * 
 * 
 * Note:
 * The length of image and image[0] will be in the range [1, 50].
 * The given starting pixel will satisfy 0  and 0 .
 * The value of each color in image[i][j] and newColor will be an integer in
 * [0, 65535].
 * 
 */

// @lc code=start
class Solution {
public:
        void helper(vector<vector<int>> &ans,vector<vector<int>>& image,int s,int c,int nc)
    {
        int m = image.size();
        int n = image[0].size();
        int oc = image[s][c];
        ans[s][c]=nc;
        int x = s;
        int y = c;
        if(x+1<m &&  (ans[x+1][y]==-1 and image[x+1][y]==oc)){helper(ans,image,x+1,y,nc);}
        if(y+1<n &&  (ans[x][y+1]==-1 and image[x][y+1]==oc)){helper(ans,image,x,y+1,nc);}
        if(x-1>=0 && (ans[x-1][y]==-1 and image[x-1][y]==oc)){helper(ans,image,x-1,y,nc);}
        if(y-1>=0 && (ans[x][y-1]==-1 and image[x][y-1]==oc)){helper(ans,image,x,y-1,nc);}
         
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
     int m = image.size();
     int n = image[0].size();
        
     vector<vector<int>> ans;
    
     for(int i=0;i<m;i++)
     {
         vector<int> a;
         for(int j=0;j<n;j++)
         {
             a.push_back(-1);
         }
         ans.push_back(a);
     }
   
    helper(ans,image,sr,sc,newColor);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ans[i][j]==-1)
                ans[i][j]=image[i][j];
        }
    }
    return ans;
    }
};
// @lc code=end

