class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        s=s+s;
        int d1=0,d2=0;
        int ans=INT_MAX;
        int l=0;
        for(int r=0;r<2*n;r++)
        {
            char p1=(r%2)?'0':'1';
            char p2=(r%2)?'1':'0';
            if(s[r]!=p1) d1++;
            if(s[r]!=p2) d2++;

            if(r-l+1>n)
            {
                char p11=(l%2)?'0':'1';
                char p22=(l%2)?'1':'0';
                if(s[l]!=p11) d1--;
                if(s[l]!=p22) d2--;
                l++;
            }
            if(r-l+1==n)
            {
                ans=min(ans,min(d1,d2));
            }

        }
        return ans;
    }
};