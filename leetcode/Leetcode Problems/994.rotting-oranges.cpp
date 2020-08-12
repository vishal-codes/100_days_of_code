/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (47.70%)
 * Likes:    2192
 * Dislikes: 188
 * Total Accepted:    143.3K
 * Total Submissions: 291.2K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * In a given grid, each cell can have one of three values:
 * 
 * 
 * the value 0 representing an empty cell;
 * the value 1 representing a fresh orange;
 * the value 2 representing a rotten orange.
 * 
 * 
 * Every minute, any fresh orange that is adjacent (4-directionally) to a
 * rotten orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange.  If this is impossible, return -1 instead.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation:  The orange in the bottom left corner (row 2, column 0) is
 * never rotten, because rotting only happens 4-directionally.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[0,2]]
 * Output: 0
 * Explanation:  Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * grid[i][j] is only 0, 1, or 2.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        
        int m = g.size();
        int n = g[0].size();
        // {x ,{y,time}}
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]==2)
                {
                    q.push({i,{j,0}});
                }
            }
        }
        
    
        int ans = 0;
        

        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        // apply the bfs
        while(!q.empty())
        {
            pair<int,pair<int,int>> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second.first;
            int t = p.second.second;
            ans = max(ans,t);
            for(pair<int,int> p1 :directions)
            {
                int x1 = x + p1.first;
                int y1 = y + p1.second;
                if((x1>=0 and x1<m) and (y1>=0 and y1<n))
                {
                    if(g[x1][y1]==1)
                    {
                        q.push({x1,{y1,t+1}});
                        g[x1][y1]=2;
                    }
                }
            }
        }

        // check for any fresh oranages
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]==1)
                    return -1;
            }
        }

        return ans;
    }
};
// @lc code=end

