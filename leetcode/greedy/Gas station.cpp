class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = 0;
        int sumCost = 0;
        int tank = 0;
        int start =0;
        for(int i=0;i<gas.size();i++)
        {
            sumGas +=  gas[i];
            sumCost += cost[i];
            
            tank += gas[i]-cost[i];
            if(tank<0)
            {
                tank=0;
                start=i+1;
            }
        }
        if(sumCost>sumGas)
            return -1;
        return start;
    }
};