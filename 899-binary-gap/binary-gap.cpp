class Solution {
public:
    int binaryGap(int n) {
      bitset<32> binary(n);
      int i = 0, j = 0;
      int count = 0;
      for(i = 0; i < 32; ++i){
        if(binary[i] == 1){
          if(binary[j] == 1){
            count = max(count, i - j);
          }
          j = i;
        }
      }
      return count;
    }
};