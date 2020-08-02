/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (39.73%)
 * Likes:    1521
 * Dislikes: 107
 * Total Accepted:    89.2K
 * Total Submissions: 224.5K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * 
 * 
 * Example 1: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[0,0,0]]
 * 
 * Output:
 * [[0,0,0],
 * [0,1,0],
 * [0,0,0]]
 * 
 * 
 * Example 2: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,1,1]]
 * 
 * Output:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,2,1]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& v)
    {
        // cout<<i<<" "<<j<<endl;
       
        if(v[i][j]!=-1)
        {
            return v[i][j];
        }
        int n = mat.size();
        int m = mat[0].size();
        int mn = 100000;
        v[i][j]=mn;
        if(i+1<n and v[i+1][j]<=0)
        {
            mn = min(mn,helper(i+1,j,mat,v));
        }
        if(j+1<m and v[i][j+1]<=0)
        {
            mn = min(mn,helper(i,j+1,mat,v));
        }
        if(i-1>=0 and v[i-1][j]<=0)
        {
            mn = min(mn,helper(i-1,j,mat,v));

        }
        if(j-1>=0 and v[i][j-1]>=0)
        {
            mn = min(mn,helper(i,j-1,mat,v));

        }
        v[i][j]=mn+1;
        return mn;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> v = mat;
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                v[i][j]=-1;
                else 
                v[i][j]=0;
            }
        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==-1 )
                {
                  v[i][j] =  helper(i,j,mat,v);
                }
            }
        }

        return v;
    }
};
// @lc code=end

