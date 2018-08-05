/**
 * Stairs
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 * Example :
 *
 * Input : 3
 * Return : 3
 *
 * Steps : [1 1 1], [1 2], [2 1]
 *
 */

/**
 * This function calculates the number of ways to take n steps to reach to the top.
 * DP is based on the simple recursive function : F(n) = F(n - 1) + F(n - 2) [Fibonacci Sequence]
 *
 * @param  int  A   number of stairs to reach to the top
 *
 * @return int      number of ways
 */
int Solution::climbStairs(int A) {
    if (A <= 2) {
        return A;
    }

    vector<int> stairs(A + 1, 0);

    stairs[0] = 0;
    stairs[1] = 1;
    stairs[2] = 2;

    for (int i = 3; i <= A; i ++) {
        stairs[i] = stairs[i - 1] + stairs[i - 2];
    }

    return stairs[A];
}
