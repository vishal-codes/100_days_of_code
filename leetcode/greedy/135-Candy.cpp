class Solution {
public:
    int candy(vector<int>& ratings) {
    
        int n = ratings.size();
        vector<int> candies(n);
        candies[0]=1;
        for(int i=1;i<n;i++)
        {
            candies[i]=1;
            if(ratings[i]>ratings[i-1])
            {
                candies[i]=candies[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                if(candies[i]<=candies[i+1])
                {
                    candies[i]=candies[i+1]+1;
                }
            }
        }
        long ans = 0;
        for(int s:candies)
        {
            ans += s;
        }
        return ans;
    }
};