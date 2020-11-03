/*** 
 * @Author: Xu.WANG
 * @Date: 2020-10-27 12:16:14
 * @LastEditTime: 2020-11-03 18:24:50
 * @LastEditors: Xu.WANG
 * @Description: 
 * @FilePath: \CodeRepo\include\kiri_case.h
 */
#pragma once
/*** 
 * @description: a[N] known，b[i] = a[0]*...*a[N-1]/a[i], no temp variables
 * @param {*}
 * @return {*}
 */
void case1(int a[], int b[], int n)
{
    b[0] = 1;
    for (size_t i = 1; i < n; i++)
    {
        b[i] = b[i - 1] * a[i - 1];
    }

    for (size_t i = n - 1; i >= 1; i--)
    {
        b[i] *= b[0];
        b[0] *= a[i];
    }
}

/*** 
 * @description: find lost num in array 
 * @param {*}
 * @return lost num
 */
int case2(int a[], int n)
{
    int lost_num = 0;
    for (size_t i = 0; i < n; i++)
    {
        lost_num ^= a[i];
    }
    return lost_num;
}