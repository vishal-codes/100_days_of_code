int getSum(int n)
{
    string s = to_string(n);
    long long sum = 0;
    for(int i=0;i<s.size();i++)
    {
        int a = s[i]-'0';
        sum += a*a;
    }
    return sum;
}
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool> m;
    
        while(n<INT_MAX and n!=1)
        {
            
          m[n]=true;
          n=getSum(n);
            
          if(m.find(n)!=m.end())break;
            
          
        }
        return n==1;
    }
};