class Solution {
public:
    bool isSubstr(string s1,string s2)
    {
            if (s1.find(s2) != std::string::npos) {
                //  std::cout << "found!" << '\n';
                return true;
            }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(j!=i and isSubstr(words[j],words[i]))
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};