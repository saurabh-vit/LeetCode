class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        vector<long long> lengths(n + 1, 1);
        
        for(int i = 0; i < n; i++){
            if(lengths[i] > k) lengths[i+1] = lengths[i];
            else{
                if(lengths[i] * 2 >= k) lengths[i+1] = k; 
                else lengths[i+1] = lengths[i] * 2;
            }
        }
        
        return helper(k, operations, lengths, n);
    }
    
    char helper(long long k, vector<int>& ops, vector<long long>& lengths, int index){
        if(index == 0){
            return 'a';
        }
        
        long long prev_len = lengths[index - 1];
        
        if(ops[index - 1] == 0){
            if(k <= prev_len){
                return helper(k, ops, lengths, index - 1);
            }else{
                return helper(k - prev_len, ops, lengths, index - 1);
            }
        }else{
            if(k <= prev_len){
                return helper(k, ops, lengths, index - 1);
            }else{
                char c = helper(k - prev_len, ops, lengths, index - 1);
                return (c == 'z') ? 'a' : c + 1;
            }
        }
    }
};