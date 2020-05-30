int merge(vector<int> &A,int start,int m,int end)
{
    vector<int> left,right;
    
    for(int i=start;i<=m;i++)
    left.push_back(A[i]);
    
    for(int i=m+1;i<=end;i++)
    right.push_back(A[i]);

    
    int count = 0;
    int i=0;
    int j=0;
    m=left.size();
    end=right.size();
    int k = start;
    while(i<m and j<end)
    {
        
        if(left[i]<=right[j])
        {
            A[k]=left[i];
            i++;
            k++;
        }
        else if(left[i]>right[j])
        {
            A[k]=right[j];
            count += m - i;
            j++;
            k++;
        }
    }
    while(i<m)
    {
        A[k]=left[i];
        i++;
        k++;
    }
    while(j<end)
    {
        A[k]=right[j];
        j++;
        k++;
    }
    return count;
}
int mergeSort(vector<int>& A,int start,int end)
{
    if(start>=end)
    {
        return 0;
    }
    int m = (start + end )/2;
    int a1 = mergeSort(A,start,m);
    int a2 = mergeSort(A,m+1,end);
    int a3 = merge(A,start,m,end);
    // int a3 =0;
    return a1+a2+a3;
}
int Solution::countInversions(vector<int> &A) {
    return mergeSort(A,0,A.size()-1);
}
