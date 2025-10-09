class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int a = 0, b = 0;
        for(int i = 0; i<m+n; i++){
            if(a<m && b<n){
                if(nums1[a]<=nums2[b]){
                    temp.push_back(nums1[a]);
                    a++;
                }else{
                    temp.push_back(nums2[b]);
                    b++;
                }
            }else if (a < m) {
                temp.push_back(nums1[a]);
                a++;
            }
            else {
                temp.push_back(nums2[b]);
                b++;
            }
        }
        
        for (int i = 0; i < m + n; i++) {
            nums1[i] = temp[i];
        }
    }
};