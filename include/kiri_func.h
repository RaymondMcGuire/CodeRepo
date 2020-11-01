/*** 
 * @Author: Xu.WANG
 * @Date: 2020-10-23 11:54:18
 * @LastEditTime: 2020-11-01 12:40:56
 * @LastEditors: Xu.WANG
 * @Description: 
 * @FilePath: \CodeRepo\include\kiri_func.h
 */
#include <macro.h>
#include <kiri_log.h>

void PrintArray(int a[], int n)
{
    std::string s = "";
    for (size_t i = 0; i < n; i++)
    {
        s += std::to_string(a[i]) + " ";
    }
    KIRI_LOG_DEBUG("Array=[ {0}]", s);
}

template <class T>
void PrintBinary(T a)
{
    std::string s = "";
    for (int i = sizeof(a) * 8 - 1; i >= 0; --i)
    {
        if ((a >> i) & 1)
            s += "1";
        else
            s += "0";
        if (i == 8)
            s += " ";
    }
    KIRI_LOG_DEBUG("Binary=[ {0}]", s);
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

/*** 
 * @description: find prime from 2 to n, not optimize.
 * @param {*}
 * @return prime number
 */
int find_prime_number(int primes[], bool flags[], int n)
{
    int cnt = 0;

    for (size_t i = 2; i < n; i++)
    {
        if (!flags[i])
        {
            primes[cnt++] = i;
            for (size_t j = i; j < n; j += i)
            {
                flags[j] = true;
            }
        }
    }

    return cnt;
}

int find_prime_number_bit(int primes[], int flags[], int n)
{
    int cnt = 0;

    for (size_t i = 2; i < n; i++)
    {
        if (!((flags[i / 32] >> (i % 32)) & 1))
        {
            primes[cnt++] = i;
            for (size_t j = i; j < n; j += i)
            {
                flags[j / 32] |= (1 << (j % 32));
            }
        }
    }

    return cnt;
}

template <class T>
T reverse_bit(T val)
{
    val = ((val & 0xAAAA) >> 1) | ((val & 0x5555) << 1);
    val = ((val & 0xCCCC) >> 2) | ((val & 0x3333) << 2);
    val = ((val & 0xF0F0) >> 4) | ((val & 0x0F0F) << 4);
    val = ((val & 0xFF00) >> 8) | ((val & 0x00FF) << 8);

    return val;
}