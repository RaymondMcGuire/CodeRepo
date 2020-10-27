/*** 
 * @Author: Xu.WANG
 * @Date: 2020-10-23 11:54:18
 * @LastEditTime: 2020-10-27 12:53:45
 * @LastEditors: Xu.WANG
 * @Description: 
 * @FilePath: \CodeRepo\include\kiri_func.h
 */
#include <macro.h>
#include <kiri_log.h>

void printArray(int a[], int n)
{
    printf("Array=[");
    for (size_t i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("]\n");
}

void swap(int &a, int &b)
{
    if (a != b)
    {
        int c = a;
        a = b;
        b = c;
    }
}

/*** 
 * @description: a^=b === a = (a^b); b^=a === b = (b^a); (b^(a^b)) = ((b^b)^a) = 0^a = a
 * @param {*}
 * @return {*}
 */
void swap_bit(int &a, int &b)
{
    if (a != b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
}

int sign_reverse_bit(int a)
{
    return ~a + 1;
}

/*** 
 * @description: 0:+ -1:- 
 * @param {*}
 * @return {*}
 */
int get_sign_bit(int a)
{
    return BIT_RS(a, 31);
}

/*** 
 * @description: x^0=x, x^-1 = ~x
 * @param {*}
 * @return {*}
 */
int abs_bit(int a)
{
    int b = get_sign_bit(a);
    return ((a ^ b) - b);
}