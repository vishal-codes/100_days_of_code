int Solution::majorityElement(const vector<int> &a) {
    int n = a.size();
    int count = 1;
    int major = a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]!=major)
        {
            count--;
        }
        else
        {
            count++;
        }
        if(count==0)
        {
            count=1;
            major=a[i];
        }
    }
    return major;
}
