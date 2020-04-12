class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        sort(stones.begin(),stones.end());
        int l = stones.size();
        while(l>1)
        {
            int x = stones[l-1];
            int y = stones[l-2];
            
            
                stones.pop_back();
                stones.pop_back();
            if(x==y)
            {
                l=l-2;
            }
            else
            {
                l=l-1;
                stones.push_back(x-y);
            }
            sort(stones.begin(),stones.end());
        }
        if(l==0)
        {
            return 0;
        }
        return stones[0];
    }
};