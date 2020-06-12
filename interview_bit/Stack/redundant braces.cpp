int Solution::braces(string A) {

    stack<char> s;
    for(int i=0;i<A.size();i++)
    {
        
        if(A[i]=='(' ||( A[i]=='*' || (A[i]=='/' ||( A[i]=='+' || A[i]=='-'))))
        {
            
            // if(A[i]!='(')
            //  cout<<A[i]<<endl;
            s.push(A[i]);
        }
        else if(A[i]==')')
        {
            
            if(!s.empty() and s.top()=='(')
            {
                return 1;
            }
            while(!s.empty() and s.top()!='(')
            {
                s.pop();
            }
            if(s.empty())
            {
                return 1;
            }
            else
                s.pop();
        }
    }
    // cout<<"sadsadsdads";
    return 0;
}
