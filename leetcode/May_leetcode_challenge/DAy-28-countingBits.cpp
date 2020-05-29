class Solution {
public:
    int setBits(int num)
    {
        int count = 0;
        while(num)
        {
            count += num & 1;
            num>>=1;
        }
        return count;
    }
    vector<int> countBits(int num) {
        vector<int> ans;
        for(int i=0;i<=num;i++){
        ans.push_back(__builtin_popcount(i));
        }
        return ans;
    }
};