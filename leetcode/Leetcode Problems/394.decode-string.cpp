/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (49.85%)
 * Likes:    3260
 * Dislikes: 166
 * Total Accepted:    214.3K
 * Total Submissions: 429.8K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * 
 * Example 1:
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * Example 2:
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * Example 3:
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * Example 4:
 * Input: s = "abc3[cd]xyz"
 * Output: "abccdcdcdxyz"
 * 
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        
        stack<string> s1;
        int i=0;
        int n=s.size();
        string temp = "";
        while(i<n)
        {
            if(s[i]>='0' and s[i]<='9')
            {
                if(temp.size()!=0)
                {
                    s1.push(temp);
                    temp="";

                }
                while(s[i]!='[')
                {
                    temp += s[i];
                    i++;
                }
                s1.push(temp);
                temp=""; 
                i++;
            }
            else if(s[i]==']')
            {
                while(!(s1.top()[0]>='0' and s1.top()[0]<='9'))
                {
                    temp = s1.top()+temp;
                    s1.pop();
                }
                int a = stoi(s1.top());
                s1.pop();
                string t1 ="";
                for(int i=0;i<a;i++)
                {
                    t1+=temp;
                }
                s1.push(t1);
                i++;
                temp="";
            }
            else
                temp+=s[i++];
        }

        while(!s1.empty())
        {
            temp = s1.top() + temp;
            s1.pop();
        }

        return temp;
    }
};
// @lc code=end

