class Solution {
public:
    string give(string s)
    {
        if(s=="&quot;")
        {
            return "\"";
        }
        else if(s=="&apos;")
        {
            return "\'";
        }
        else if(s=="&amp;")
        {
            return "&";
        }
        else if(s=="&gt;")
        {
            return ">";
        }
        else if(s=="&lt;")
        {
            return "<";
        }
        else if(s=="&frasl;")
        {
            return "/";
        }
        return s;
        
    }
    string entityParser(string text) {
        string ans;
        int i=0;
        while(i<text.size())
        {
            if(text[i]=='&')
            {
                string w;
                while(text[i]!=';')
                {
                    w+=text[i];
                    i++;
                }
                w+=text[i];
                
                ans+=give(w);
            }
            else
            {
                ans+=text[i];   
            }
            i++;
        }
        return ans;
    }
};