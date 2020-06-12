class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
    
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,height[i]);
            left[i]=mx;
        }
        mx=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            mx=max(mx,height[i]);
            right[i]=mx;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans+ min(left[i],right[i])-height[i];
        }
        return ans;
    }
};