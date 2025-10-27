class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int count = 0, ans = 0;
        for(int i = 0; i<n; i++){
            int currcount = 0;
            for(char c : bank[i]){
                if(c == '1'){
                    currcount++;
                }
            }
            if(currcount > 0){
                ans = ans + count*currcount;
                count = currcount;
            }
        }
        return ans;
    }
};