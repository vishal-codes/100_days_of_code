class Solution {
public:
    string defangIPaddr(string adress) {
        string ans ;
        for(int i=0;i<adress.size();i++)
        {
            if(adress[i]=='.')
                ans += "[.]";
            else
                ans += adress[i];
        }
        return ans;
    }
};