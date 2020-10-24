/*** 
 * @Author: Xu.WANG
 * @Date: 2020-10-23 11:54:18
 * @LastEditTime: 2020-10-24 12:53:19
 * @LastEditors: Xu.WANG
 * @Description: 
 * @FilePath: \CodeRepo\include\kiri_func.h
 */

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