class Fancy {
public:
    vector<int> fancy;
    int M = 1e9+7;
    Fancy() {
        fancy = {};
    }
    
    void append(int val) {
        fancy.emplace_back(val);
    }
    
    void addAll(int inc) {
        for_each(fancy.begin(), fancy.end(), [inc](int &ele){ ele+=inc;});
    }
    
    void multAll(int m) {
        for_each(fancy.begin(), fancy.end(), [m,this](int &ele){ 
            ele = (1LL * ele * m) % M;
        });
    }
    
    int getIndex(int idx) {
        if(idx+1 > fancy.size()) return -1;
        return fancy[idx] % M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */