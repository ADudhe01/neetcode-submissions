class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i = 0, count = 0;
        while (i < 32) {
            count += (n >> i) & 1;
            i++;
        }
        return count;
    }
};
