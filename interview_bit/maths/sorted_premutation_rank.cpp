int Solution::findRank(string s) {
    	
    vector<int> fact(s.size());
	
	fact[0]=1;
	
	for(int i=1;i<s.size();i++)
		fact[i]=(i*fact[i-1])%1000003;

	long ans = 0;
	int n = s.size();
	for(int i=0;i<n;i++)
	{
		long count = 0;
		for(int j=i+1;j<n;j++)
		{
			if(s[j]<s[i])
				count++;
		}
		ans = (ans + (count*fact[n-i-1])%1000003)%1000003;

	}
	return (ans+1)%1000003;
}
