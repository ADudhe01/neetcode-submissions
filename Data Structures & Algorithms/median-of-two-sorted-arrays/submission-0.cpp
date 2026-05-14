class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> combine(m + n);

        int i = 0, j = 0, idx = 0;
        while (i != m && j != n) {
            if (nums1[i] > nums2[j]) {
                combine[idx++] = nums2[j++];
            } else combine[idx++] = nums1[i++];
        }

        while (i != m) {
            combine[idx++] = nums1[i++];
        }

        while (j != n) {
            combine[idx++] = nums2[j++];
        }

        int mid = 0;
        if ((m + n) % 2) return 1.0 * combine[(m + n) / 2];

        return (combine[(m + n) / 2] + combine[(m + n) / 2 - 1]) / 2.0;
    }
};
