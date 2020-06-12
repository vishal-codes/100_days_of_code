class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i,j,k;
        int n = nums.size();
        i=0;
        j=n-1;
        k=0;
        while(k<n)
        {
            if(nums[k]==2 and j>k)
            {
                while(j!=0 and nums[j]==2)
                {
                    j--;
                }
                if(j>k)
                {
                    swap(nums[k],nums[j]);
                    j--;
                }
                else
                {
                    k++;
                }
            }
            else if(nums[k]==0 and i<k)
            {
                while(i!=n-1 and nums[i]==0)
                {
                    i++;
                }
                if(i<k)
                {
                    swap(nums[k],nums[i]);
                    i++;
                }
                else
                    k++;
            }
            else
                k++;
        }
    }
};