/*
 * @lc app=leetcode id=636 lang=cpp
 *
 * [636] Exclusive Time of Functions
 */

// @lc code=start
class Solution {
public:
    pair<int,pair<int,int>> split(string s)
    {
        string time ="";
        string id = "";
        string so ="";

        int i = 0;
        int c = 0;
        string temp ="";
        while(i<s.size())
        {
            if(s[i]==':' and c==0)
            {
                id = temp;
                temp = "";
                c++;
            }
            else if(s[i]==':' and c==1)
            {
                so = temp;
                temp = "";
                c++;
            }
            else
                temp+=s[i];
            i++;
        }
        time = temp;

        int t = stoi[time];
        int id2 = stoi[id];
        if(so=="start")
            return {t,{id2,0}};
        return {t,{id2,1}};
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        // {time,{id,start-off}}
        vector<pair<int,pair<int,int>> p;


    }
};
// @lc code=end

