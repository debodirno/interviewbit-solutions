/**
 * Find the longest increasing subsequence of a given sequence / array.
 *
 * In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and in which the subsequence is as long as possible.
 * This subsequence is not necessarily contiguous, or unique.
 * In this case, we only care about the length of the longest increasing subsequence.
 *
 * Example :
 *
 * Input : [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
 * Output : 6
 * The sequence : [0, 2, 6, 9, 13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15]
 */

/**
 * This function calculates the LIS based on DP.
 * Complexity : T(n) = O(n^2), S(n) = O(n)
 * Recursive relation : LIS[i] = max(1 + LIS[j], LIS[i]) for j : [0.. i - 1] and A[i] > A[j]
 *
 * @param  const vector<int>    A   the sequence
 * @return int                      the length of the longest increasing subsequence
 */
int Solution::lis(const vector<int> &A) {
    int sz = A.size();
    if (sz <= 1) {
        return sz;
    }

    vector<int> LIS(sz, 1);
    int maxLIS = 1;

    for (int i = 1; i < sz; i ++) {
        for (int j = 0; j < i; j ++) {
            if (A[i] > A[j]) {
                LIS[i] = max(1 + LIS[j], LIS[i]);
            }
        }
        maxLIS = max(LIS[i], maxLIS);
    }

    return maxLIS;
}
