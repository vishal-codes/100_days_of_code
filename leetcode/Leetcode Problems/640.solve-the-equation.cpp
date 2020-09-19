/*
 * @lc app=leetcode id=640 lang=cpp
 *
 * [640] Solve the Equation
 *
 * https://leetcode.com/problems/solve-the-equation/description/
 *
 * algorithms
 * Medium (42.00%)
 * Likes:    242
 * Dislikes: 538
 * Total Accepted:    25.1K
 * Total Submissions: 59.7K
 * Testcase Example:  '"x+5-3+x=6+x-2"'
 *
 * 
 * Solve a given equation and return the value of x in the form of string
 * "x=#value". The equation contains only '+', '-' operation, the variable x
 * and its coefficient.
 * 
 * 
 * 
 * If there is no solution for the equation, return "No solution".
 * 
 * 
 * If there are infinite solutions for the equation, return "Infinite
 * solutions".
 * 
 * 
 * If there is exactly one solution for the equation, we ensure that the value
 * of x is an integer.
 * 
 * 
 * Example 1:
 * 
 * Input: "x+5-3+x=6+x-2"
 * Output: "x=2"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "x=x"
 * Output: "Infinite solutions"
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: "2x=x"
 * Output: "x=0"
 * 
 * 
 * 
 * Example 4:
 * 
 * Input: "2x+3x-6x=x+2"
 * Output: "x=-1"
 * 
 * 
 * 
 * Example 5:
 * 
 * Input: "x=x+2"
 * Output: "No solution"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // separate coefficeint of x and number 
   //  
     int coefOfX(string s)
     {
         int sum = 0;
         
         for(int i=0;i<s.size();i++)
         {
             
             if(s[i]=='x')
             {
                 int j = i-1;
                 string t;
                 
                 while(j>=0)
                 {
                     // cout<<"h"<<endl;
                     if(s[j]=='+' or s[j]=='-')
                        break;
                    t =s[j]+t;
                    j--;
                 }
                // cout<<t.size()<<endl;
                 if(t.size()==0 and j==-1)
                 {
                     sum +=1;
                 }
                 else if(t.size()==0 and s[j]=='+')
                 {
                     sum +=1;
                 }
                 else if(t.size()==0 and s[j]=='-')
                 {
                     sum -=1;
                 }
                 else if(j==-1)
                 {
                     sum += stoi(t);
                 }
                 else
                 {
                     if(s[j]=='+')
                     {
                         sum+=stoi(t);
                     }
                     else
                        sum-=stoi(t);
                 }
             }
         }
         return sum;
     }
     int num(string s)
     {
         int sum = 0;
         for(int i=1;i<s.size();i++)
         {
             if((s[i]=='+' or s[i]=='-')and (s[i-1]>='0' and s[i-1]<='9'))
             {
                 int j = i-1;
                 string t ;
                 while(j>=0)
                 {
                     if(s[j]=='+' or s[j]=='-')
                        break;
                    t = s[j]+t;
                    j--;
                 }

                  if(j==-1)
                 {
                     sum +=stoi(t);
                 }
                 else
                 {
                     if(s[j]=='+')
                     {
                         sum+=stoi(t);
                     }
                     else
                        sum-=stoi(t);
                 }
             }
         }
         if(s[s.size()-1]>='0' and s[s.size()-1]<='9')
         {
              int j = s.size()-1;
                 string t ;
                 while(j>=0)
                 {
                     if(s[j]=='+' or s[j]=='-')
                        break;
                    t = s[j]+t;
                    j--;
                 }

                  if(j==-1)
                 {
                     sum +=stoi(t);
                 }
                 else
                 {
                     if(s[j]=='+')
                     {
                         sum+=stoi(t);
                     }
                     else
                        sum-=stoi(t);
                 }
         }
         return sum;
     }
    string solveEquation(string eq) {
        
        string lhs,rhs;
        int i = 0;
        while(eq[i]!='=' and i<eq.size())
        {
            lhs += eq[i];
            i++;
        }
        rhs = eq.substr(i+1);
        int lhsx = coefOfX(lhs);
        int rhsx = coefOfX(rhs);
        int lhsn = num(lhs);
        int rhsn = num(rhs);

        int d = lhsx-rhsx;
        int n = rhsn-lhsn;
        // cout<<d<<" "<<n<<endl;
        if(d==0 and n==0)
        {
            return "Infinite solutions";
        }
        else if(d==0)
        {
            return "No solution";
        }
        
            return "x="+to_string(n/d);
        
        return "randon";

        // coefficent
    }
};
// @lc code=end

