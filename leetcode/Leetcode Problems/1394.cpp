class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int count = 1;
        int li = -1;
        int n = arr.size();
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1])
            {
                count++;
            }
            else
            {
                if(count==arr[i-1])
                {
                    li=arr[i-1];
                 
                }
                   count=1;
            }
        }
        if(count==arr[n-1])
        {
            return count;
        }
        return li;
    }
};