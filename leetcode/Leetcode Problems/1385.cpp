class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
     


    int c = 0;;
        int n = arr1.size();
        int m = arr2.size();
    for(int i=0;i<n;i++)
    {
        bool f = true;
        for(int j=0;j<m;j++)
        {
            if(abs(arr1[i]-arr2[j])<=d)
            {
                f=false;
                break;
            }
        }
        if(f)c++;
        
    }

return c;











   }
};