int Solution::longestValidParentheses(string A) {
    
    stack<string> s;
    int mx = 0;
    int n = A.size();
    for(int i=0;i<n;i++)
    {
        if(A[i]=='(')
            s.push("(");
        else
        {
            int count = 0;
            int flag=0;
            while(!s.empty())
            {
                    if(s.top()=="(")
                    {
                        
                        if(flag)
                        {
                            break;
                        }
                        count+=2;
                        mx=max(mx,count);
                        flag=1;
                        
                        
                    }
                    else
                    {
                        
                        count += stoi(s.top());
                        mx=max(mx,count);
                    }
                    s.pop();
                    
            }
            if(flag==0)
            {
                    count=0;
            }
            s.push(to_string(count));
                
            
        }
    }
    return mx;
}
