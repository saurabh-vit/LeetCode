class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0;
        vector<int> freq(101, 0);
        for(int num : nums){
            freq[num]++;
        }
        sort(freq.begin(), freq.end());
        int maxfreq = freq.back();
        for(int f : freq){
            if (f==maxfreq) ans += f;
        }
        return ans;
    }
};