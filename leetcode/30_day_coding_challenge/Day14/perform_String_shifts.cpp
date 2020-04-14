class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
     int sum = 0;
     int l = shift.size();
     int n = s.size();
     for(int i=0;i<l;i++)
     {
         if(shift[i][0]==1)
         {
             sum=sum + shift[i][1];
         }
         else
             sum = sum - shift[i][1];
     }
        string ans ;
     if(sum>0)
     {
         
         sum=abs(sum);
         sum = sum % n;
         int j = n-1;
         while(sum--)
         {
             j--;
         }
         // cout<<"j "<<j<<endl;
         for(int i=j+1;i<n;i++)
         {
             // cout<<s[i]<<" ";
             ans += s[i];
         }
         for(int i=0;i<=j;i++)
         {
             // cout<<s[i]<<" ";
             ans += s[i];
         }
         
     }
     else
     {
         sum=abs(sum);
         sum = sum%n;
         string temp;
         for(int i=0;i<sum;i++)
         {
             temp+=s[i];
         }
         for(int i=sum;i<n;i++)
             ans+=s[i];
         ans+=temp;
     }
        return ans;
    }
};