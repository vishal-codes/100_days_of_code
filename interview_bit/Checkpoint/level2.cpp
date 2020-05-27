vector<vector<int> > Solution::prettyPrint(int A) {
    
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        int start = 4;
        for(int j=0;j<n;j++)
        {
            cout<<start<<" ";
            if(j<i)
            {
                start--;
            }
        }
        cout<<endl;
    }
    
}
