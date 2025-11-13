class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int count = 0, res = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '1'){
                count++;
            }else{
                while(i<n && s[i]!='1'){
                    i++;
                }
                res += count;
                count++;
            }
        }
        return res;
    }
};