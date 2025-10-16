class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        int i = n-1;
        while(k!=0){
            int ch = min(25, k);
            ans[i] += ch;
            k -= ch;
            i--;
        }
        return ans;
    }
};