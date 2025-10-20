class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int y = 0;
        for(auto &i : operations){
            if(i == "++X" || i == "X++"){
                y++;
            }else{
                y--;
            }
        }
        return y;
    }
};