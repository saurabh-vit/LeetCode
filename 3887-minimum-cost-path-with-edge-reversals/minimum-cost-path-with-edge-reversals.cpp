class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges){
        unordered_map<int,list<pair<int,int>>>Adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            Adj[u].push_back(make_pair(v,w));
            Adj[v].push_back(make_pair(u,2*w));
        }
        vector<int> dist(n,INT_MAX);
        set<pair<int,int>> st;
        st.insert(make_pair(0,0));
        dist[0] = 0;
        while(!st.empty()){
            auto top = *(st.begin());
            int distance = top.first;
            int node = top.second;
            if(node == n-1){
                return distance;
            }
            st.erase(st.begin());

            for(auto neighbour:Adj[node]){
                if(distance + neighbour.second < dist[neighbour.first]){
                    auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
                    if(record != st.end()){
                        st.erase(record);
                    }
                    dist[neighbour.first] = distance + neighbour.second;
                    st.insert(make_pair(distance + neighbour.second,neighbour.first));
                }
            }
        }
        return -1;
    }
};