class Solution {
public:
    char findKthBit(int n, int k) {
        string s="011";
        if(k<=3)
        return s[k-1];
        for(int i=3;i<=n;i++){
            string res=s;
            s.push_back('1');
            // reverse(res.begin(),res.end());
            for(int j=0;j<res.size();j++){
                if(res[j]=='0')
                res[j]='1';
                else
                res[j]='0';
            }
            reverse(res.begin(),res.end());
            s+=res;
        }
        cout<<s<<endl;
        return s[k-1];
    }
};