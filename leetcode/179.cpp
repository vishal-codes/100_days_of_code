 bool compare(const string &s1,const string & s2)
    {
        string a = s1+s2;
        string b = s2+s1;
        return a > b;
    }
class Solution {
public:
   
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        vector<string> temp(n);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                flag=false;
            }
            temp[i]=to_string(nums[i]);
        }
        if(flag)
        {
            return "0";
        }
        sort(temp.begin(),temp.end(),compare);
        string ans;
        for(string s : temp)
        {
            ans += s;
        }
        return ans;
    }
};