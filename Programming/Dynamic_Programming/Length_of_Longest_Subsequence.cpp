/**
 * Length of Longest Subsequence
 * Problem Setter: mayank111
 * Problem Tester: glowing_glare
 * Given an array of integers, find the length of longest subsequence which is first increasing then decreasing.
 *
 * Example:
 *
 * For the given array [1 11 2 10 4 5 2 1]
 *
 * Longest subsequence is [1 2 10 4 2 1]
 *
 * Return value 6
 */

/**
 * The function calculates LIS and LDS and outputs max(LIS[i] + LDS[i] - 1)
 *
 * LIS[i] : longest increasing subsequence till i in the array A[0..i]
 * LDS[i] : longest decreasing subsequence from i till end of the array A[i..sz]
 *
 * @param  vector const vector<int> &A 		the input sequence
 *
 * @return int       						length of the longest subsequence
 */
int Solution::longestSubsequenceLength(const vector<int> &A) {
    int sz = A.size();

    if (sz <= 1) {
        return sz;
    }

    vector<int> LIS(sz, 1);
    vector<int> LDS(sz, 1);

    int j = 0, i = 1;

    while (i < sz) {
        j = 0;
        while (j < i) {
            if (A[i] > A[j]) {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
            j ++;
        }
        i ++;
    }

    i = sz - 2;

    while (i >= 0) {
        j = sz - 1;
        while (j > i) {
            if (A[i] > A[j]) {
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
            j --;
        }
        i --;
    }

    int ans = 0;

    for (i = 0; i < sz; i ++) {
        ans = max(ans, LIS[i] + LDS[i] - 1);
    }

    return ans;
}
