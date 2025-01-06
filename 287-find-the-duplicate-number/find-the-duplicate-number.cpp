class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // unordered_set<int> s;
        // int n = nums.size();
        // for (int i = 0; i < n; i++)
        // {
        //     if(s.find(nums[i])!=s.end()){
        //         return nums[i];
        //     }
        //     s.insert(nums[i]);
        // }
        // return -1;

        //another approach
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i<n; i++){
        //     if(nums[i]==nums[i+1]){
        //         return nums[i];
        //     }
        // }
        // return -1;

        //linked list ans slow fast approach
        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];  //+1
            fast = nums[nums[fast]]; //+2
        }while(slow!=fast);

        slow = nums[0];
        while(slow!=fast){
            slow = nums[slow];  //+1
            fast = nums[fast];  //+1
        }
        return slow;
    }
};