/*
 * @lc app=leetcode id=1286 lang=cpp
 *
 * [1286] Iterator for Combination
 *
 * https://leetcode.com/problems/iterator-for-combination/description/
 *
 * algorithms
 * Medium (68.08%)
 * Likes:    375
 * Dislikes: 37
 * Total Accepted:    25.3K
 * Total Submissions: 36K
 * Testcase Example:  '["CombinationIterator","next","hasNext","next","hasNext","next","hasNext"]\r\n' +
  '[["abc",2],[],[],[],[],[],[]]\r'
 *
 * Design an Iterator class, which has:
 * 
 * 
 * A constructor that takes a string characters of sorted distinct lowercase
 * English letters and a number combinationLength as arguments.
 * A function next() that returns the next combination of length
 * combinationLength in lexicographical order.
 * A function hasNext() that returns True if and only if there exists a next
 * combination.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * CombinationIterator iterator = new CombinationIterator("abc", 2); // creates
 * the iterator.
 * 
 * iterator.next(); // returns "ab"
 * iterator.hasNext(); // returns true
 * iterator.next(); // returns "ac"
 * iterator.hasNext(); // returns true
 * iterator.next(); // returns "bc"
 * iterator.hasNext(); // returns false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= combinationLength <= characters.length <= 15
 * There will be at most 10^4 function calls per test.
 * It's guaranteed that all calls of the function next are valid.
 * 
 * 
 */

// @lc code=start
class CombinationIterator {
public:
    vector<string> v;
    vector<string> helpers(string chars,int length)
    {
        vector<string> ans;
        if(length==0)
        {
            ans.push_back("");
            return ans;
        }
        
        for(int i=0;i<chars.size();i++)
        {
            vector<string>  s = helpers(chars.substr(i+1),length-1);
            for(string t :s)
            {
                ans.push_back(chars[i]+t);
            }
        }
        return ans;
    }
    CombinationIterator(string chars, int length) {
     
        v = helpers(chars,length);
        sort(v.begin(),v.end(),greater<string>());
    }
    
    string next() {
        string s = v[v.size()-1];
        v.pop_back();
        return s;
    }
    
    bool hasNext() {
     
            return v.size()>0;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

