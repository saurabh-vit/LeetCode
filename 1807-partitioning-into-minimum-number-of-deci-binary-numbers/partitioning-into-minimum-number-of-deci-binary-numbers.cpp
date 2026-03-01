class Solution {
public:
    int minPartitions(string n) 
    {
        int k = n.size();

        int ans = 0;

        
        for(char x: n)
        {
            ans = max(ans,(int)(x - '0'));

        }

        return ans;
        
    }
};