
class Solution {
    #define ll long long
    typedef struct 
    {
        long long time;
        int  w_time;
        int  mul;
    } pr;
    // #define pr pair<ll,int>


public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll ans = 0;
        auto cmp = [](pr &left, pr &right) { return (left.time) > (right.time); };
        priority_queue<pr, vector<pr>, decltype(cmp)> pq;
        for(auto t : workerTimes) pq.push({t,t,1});
        // long long time = 0;
        while(mountainHeight--)
        {
            pr x=pq.top();
            pq.pop();
            ans = x.time;
            x.mul++;
            x.time += (ll) x.w_time*x.mul;
            pq.push(x);
        }
        return ans;
    }
};