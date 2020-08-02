/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int value(string num)
    {
    
        if(num[0]=='-')
        {
            return -stoi(num.substr(1));

        }
        return stoi(num);
    }
    int evalRPN(vector<string>& t) {
        stack<int> s;

        for(int i=0;i<t.size();i++)
        {
            if(t[i]=="+")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if(t[i]=="-")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(t[i]=="*")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b*a);
            }
            else if(t[i]=="/")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            }
            else
            {
                s.push(value(t[i]));
            }
        }
        return s.top();
    }
};
// @lc code=end

