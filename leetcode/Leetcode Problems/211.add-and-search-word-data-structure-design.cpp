/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (36.95%)
 * Likes:    2076
 * Dislikes: 98
 * Total Accepted:    211.5K
 * Total Submissions: 561.2K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one
 * letter.
 * 
 * Example:
 * 
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 * 
 */

// @lc code=start
class TrieNode
{
    public:
    bool isWord ;
    vector<TrieNode*> children;

    TrieNode()
    {
        isWord = false;
        
        for(int i=0;i<26;i++)
        {
            children.push_back(NULL);
        }
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        
        TrieNode* c = root;
        for(int i=0;i<word.size();i++)
        {
            int index = word[i] - 'a';
            if(c->children[index]==NULL)
            {
                c->children[index] = new TrieNode();
            }
            c = c->children[index];
        }
        c->isWord=true;
    }
    bool helper(TrieNode* root,string word)
    {
        if(root==NULL)
        {
            return false;
        }
        if(word.size()==0)
        {
            return root->isWord==true;
        }
        
            if(word[0]=='.')
            {
                vector<TrieNode*> children = root->children;
                for(int i=0;i<children.size();i++)
                {
                    if(helper(children[i],word.substr(1)))
                        return true;
                }
                return false;
            }
        
        return helper(root->children[word[0]-'a'],word.substr(1));
            
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return helper(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

