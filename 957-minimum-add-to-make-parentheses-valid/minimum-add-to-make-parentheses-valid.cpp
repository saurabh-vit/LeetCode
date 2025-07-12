class Solution {
public:
    int minAddToMakeValid(string s) {
        int c1 = 0;
        int c2 = 0;
        for(char c : s){
            if(c=='('){
                c1++;
            }else{
                if(c1>0){
                    c1--;
                }else{
                    c2++;
                }
            }
        }
        c2 += c1;
        return c2;
    }
};