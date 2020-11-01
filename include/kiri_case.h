/*** 
 * @Author: Xu.WANG
 * @Date: 2020-10-27 12:16:14
 * @LastEditTime: 2020-10-27 13:00:22
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