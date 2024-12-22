class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.length();
        int st = 0, end = n-1;
        while(st<end && s.find(part)<n){
            s.erase(s.find(part), part.length());
        } 
        return s;       
    }
};