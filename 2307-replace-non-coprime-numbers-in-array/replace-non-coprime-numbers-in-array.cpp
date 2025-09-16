class Solution {
public:
    int lcm(int a, int b){
        return (1ll * a * b)/gcd(a, b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for(int num : nums){
            while(!st.empty() && gcd(st.back(), num)>1){
                num = lcm(st.back(), num);
                st.pop_back();
            }
            st.push_back(num);
        }
        return st;
    }
};