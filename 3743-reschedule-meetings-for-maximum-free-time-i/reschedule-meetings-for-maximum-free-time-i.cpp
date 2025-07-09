class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps;
        for(int i = 1; i < n; i++){
            gaps.push_back(startTime[i] - endTime[i-1]);
        }
        gaps.insert(gaps.begin(), startTime[0] - 0);
        gaps.push_back(eventTime - endTime[n-1]);
        int maxFree = 0, windowSum = 0;
        for(int i = 0; i <= k && i < gaps.size(); i++){
            windowSum += gaps[i];
        }
        maxFree = windowSum;
        for(int i = k+1; i < gaps.size(); i++){
            windowSum += gaps[i] - gaps[i-k-1];
            maxFree = max(maxFree, windowSum);
        }
        return maxFree;
    }
};