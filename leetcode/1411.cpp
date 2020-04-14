
class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        long long color3 = 6;
        long long color2 = 6;
        for(int i=2;i<=n;i++)
        {
            long temp = color3;
            color3 = ((2*color3)%mod+(2*color2)%mod)%mod;
            color2 = ((2*temp)%mod + (3*color2)%mod)%mod;
        }
        return(int) (color3+color2)%mod;
    }
};