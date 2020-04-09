class Solution {
public:
    bool backspaceCompare(string s, string t) {
     int i =s.size()-1;
     int j = t.size()-1;
     int countA=0;
     int countB=0;
    while(i>=0 or j>=0)
    {
        while(i>=0 and (s[i]=='#' or countA>0))
        {
            if(s[i]=='#')
                countA++;
            else
                countA--;
            i--;
        }
        
        while(j>=0 and (t[j]=='#' or countB>0))
        {
            if(t[j]=='#')
                countB++;
            else
                countB--;
            j--;
        }
        if(i<0 or j<0)
        {
            return i==j;
        }
        if(s[i]!=t[j])
        {
            return false;
        }
        else
        {
            i--;
            j--;
        }
        
    }
    return i==j;
    }
};