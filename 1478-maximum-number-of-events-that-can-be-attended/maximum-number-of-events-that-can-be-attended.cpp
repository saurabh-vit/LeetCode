class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int day = 0, i = 0, n = events.size(), count = 0;
        while (!pq.empty() || i < n) {
            if (pq.empty()) {
                day = events[i][0];
            }
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                count++;
            }   
            day++;
        }      
        return count;
    }
};