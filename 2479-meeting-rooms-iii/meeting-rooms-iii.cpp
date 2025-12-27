class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        sort(meet.begin(),meet.end());
        priority_queue<pair<long,long> , vector<pair<long,long>>, greater<pair<long,long>> > pq;
        vector<long> freq(n,0);

        for(int i = 0;i<n;i++) {
            pq.push(make_pair(0,i));
        }

        int i = 0;
        while(i<meet.size()) {
            long start = meet[i][0];
            long end = meet[i][1];
            long dur = end-start;

            pair<long,long> cur = pq.top();
            pq.pop();
            
            if(cur.first<start) {
                pq.push(make_pair(start, cur.second));
            } else {
                freq[cur.second]++;
                pq.push(make_pair(max(cur.first, start) + dur, cur.second));
                i++;
            }
        }

        int ans = 0, max = 0;

        for(int i = 0;i<n;i++) {
            if(freq[i]>max) {
                max = freq[i];
                ans = i;
            }
        }

        return ans;
    }
};