class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();
        int count = 0;
        int check = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='R'){
                check++;
            }else{
                check--;
            }
            if(check==0){
                count++;
            }
        }
        return count;
    }
};