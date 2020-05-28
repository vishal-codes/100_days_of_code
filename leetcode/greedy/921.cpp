class Solution {
public:
    int minAddToMakeValid(string S) {
     
        stack<char> stack;
        long ans = 0;
        int n = S.size();
        for(int i=0;i<n;i++)
        {
            if(S[i]==')')
            {
                if(stack.empty())
                    ans++;
                else
                    stack.pop();
            }
            else
                stack.push(S[i]);
        }
        ans += stack.size();
        return ans;
    }
};