int Solution::longestConsecutive(const vector<int> &A) {
    
    unordered_map<int,int> map;
    int n = A.size();
    
    for(int i=0;i<n;i++)
    map[A[i]]++;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(map[A[i]]>0)
        {
            int count = 0;
            int s = A[i]-1;
            while(map[s]>0)
            {
                map[s]--;
                s--;
                count++;
            }
            s=A[i];
            while(map[s]>0)
            {
                map[s]--;
                s++;
                count++;
            }
            ans = max(ans,count);
        }
    }
    return ans;
}
