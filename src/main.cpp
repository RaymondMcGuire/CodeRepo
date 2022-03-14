/*
 * Author: Xu WANG
 * Created time: 2022-03-14 12:59:18
 * Last Modified by:
 * Last Modified time:
 */

/***
 * @Author: Xu.WANG
 * @Date: 2020-10-19 00:02:37
 * @LastEditTime: 2021-06-01 11:26:27
 * @LastEditors: Xu.WANG
 * @Description:
 * @FilePath: \src\main.cpp
 */

#include <kiri_timer.h>

#include <kiri_func.h>
#include <kiri_case.h>
#include <fbs/fbs_sample.h>

// KIRI_LOG_INFO("Initialized KiriLog System!");
//      KIRI_LOG_INFO("Bit Shift!");
//      int a = 15, a1 = -15;
//      KIRI_LOG_DEBUG("Value={0}, Right Shift {1}, Result={2}", a, 2, BIT_RS(a, 2));
//      KIRI_LOG_DEBUG("Value={0}, Right Shift {1}, Result={2}", a1, 2, BIT_RS(a1, 2));
//      KIRI_LOG_DEBUG("Value={0}, Left Shift {1}, Result={2}", a, 2, BIT_LS(a, 2));

//     KIRI_LOG_INFO("Bit Judge Odd/Even!");
//     KiriTimer timer("Odd/Even Print(Bit)");

//     for (int i = 0; i < 1000000; ++i)
//         if ((i & 1) == 0)
//         {
//             // KIRI_LOG_DEBUG("Even={0}", i);
//         }

//     timer.rlog();

//     for (int i = 0; i < 1000000; ++i)
//         if (i % 2 == 0)
//         {
//             //KIRI_LOG_DEBUG("Even={0}", i);
//         }

//     timer.rlog("Odd/Even Print(Normal)");

//     KIRI_LOG_INFO("Swap Func!");
//     a = 3, a1 = 13;
//     KIRI_LOG_DEBUG("Swap Func, Before Swap: a={0}, a1={1}", a, a1);
//     swap(a, a1);
//     KIRI_LOG_DEBUG("Swap Func, After Swap: a={0}, a1={1}", a, a1);

//     KIRI_LOG_DEBUG("Bit Swap Func, Before Swap: a={0}, a1={1}", a, a1);
//     swap_bit(a, a1);
//     KIRI_LOG_DEBUG("Bit Swap Func, After Swap: a={0}, a1={1}", a, a1);

//     KIRI_LOG_INFO("Sign Reverse Func!");
//     a = 12354, a1 = -12345;
//     int b = sign_reverse_bit(a);
//     KIRI_LOG_DEBUG("Sign Reverse Func, Before Reverse: a={0}; After Reverse: a={1}", a, b);
//     b = sign_reverse_bit(a1);
//     KIRI_LOG_DEBUG("Sign Reverse Func, Before Reverse: a={0}; After Reverse: a={1}", a1, b);

//     KIRI_LOG_INFO("Get Sign Func!");
//     b = get_sign_bit(a);
//     KIRI_LOG_DEBUG("Get Sign Func, Value ={0}; Sign ={1}", a, b);
//     b = get_sign_bit(a1);
//     KIRI_LOG_DEBUG("Get Sign Func, Value ={0}; Sign ={1}", a1, b);

//     KIRI_LOG_INFO("Abs Bit Func!");
//     b = abs_bit(a);
//     KIRI_LOG_DEBUG("Abs Bit Func, Value ={0}; Abs ={1}", a, b);
//     b = abs_bit(a1);
//     KIRI_LOG_DEBUG("Abs Bit Func, Value ={0}; Abs ={1}", a1, b);

//     int n = 5;
//     int aryA[5] = {1, 3, 5, 7, 9};
//     int aryB[5];
//     KIRI_LOG_INFO("Case1: a[N] known, b[i] = a[0]*...*a[N-1]/a[i], no temp variables");
//     PrintArray(aryA, 5);
//     case1(aryA, aryB, n);
//     PrintArray(aryB, 5);

//     KIRI_LOG_INFO("Find Prime Func!");
//     const int MAX_NUM = 100;
//     int primes[MAX_NUM / 3 + 1];
//     bool flags[MAX_NUM];

//     memset(flags, false, sizeof(flags));
//     int prime_num = find_prime_number(primes, flags, MAX_NUM);
//     PrintArray(primes, prime_num);

//     int bit_primes[MAX_NUM / 3 + 1];
//     int bit_flags[MAX_NUM / 32 + 1];
//     memset(bit_flags, 0, sizeof(bit_flags));
//     prime_num = find_prime_number_bit(bit_primes, bit_flags, MAX_NUM);
//     PrintArray(bit_primes, prime_num);

//     KIRI_LOG_INFO("Exchange High and Low Position Func!");
//     unsigned short us = 34520;
//     KIRI_LOG_DEBUG("Value={0}", us);
//     PrintBinary(us);
//     KIRI_LOG_DEBUG("After Exchanged");
//     us = (us >> 8) | (us << 8);
//     PrintBinary(us);

//     KIRI_LOG_INFO("Reverse Bit Func!");
//     KIRI_LOG_DEBUG("Before Reverse");
//     PrintBinary(us);
//     us = reverse_bit(us);
//     KIRI_LOG_DEBUG("After Reversed");
//     PrintBinary(us);

//     // KIRI_LOG_INFO("Test FlatBuffer Demo!");
//     // fbs_read_sample();

//     KIRI_LOG_INFO("Case2: find lost num in array(all of the data is pair)");
//     int case2_array[15] = {1, 347, 6, 9, 13, 65, 889, 712, 889, 347, 1, 9, 65, 13, 712};
//     int lost_num = case2(case2_array, 15);
//     KIRI_LOG_DEBUG("Lost Number is {0}", lost_num);

//     return 0;
// }

// using namespace std;

// vector<int> kmpTable(string needle)
// {
//     auto n = needle.size();
//     vector<int> lps(n, 0);
//     for (auto i = 1, len = 0; i < n;)
//     {
//         if (needle[i] == needle[len])
//         {
//             lps[i++] = ++len;
//         }
//         else if (len)
//         {
//             len = lps[len - 1];
//         }
//         else
//         {
//             lps[i++] = 0;
//         }
//     }
//     return lps;
// }

// int strStr(string haystack, string needle)
// {
//     int m = haystack.size(), n = needle.size();

//     if (!n)
//         return 0;

//     auto lps = kmpTable(needle);
//     for (auto i = 0, j = 0; i < m;)
//     {
//         if (haystack[i] == needle[j])
//         {
//             i++;
//             j++;
//         }

//         if (j == n)
//             return i - j;

//         if (i < m && haystack[i] != needle[j])
//         {
//             KIRI_LOG_DEBUG("j={0}", j);
//             if (j)
//                 j = lps[j - 1];
//             else
//                 i++;
//         }
//     }

//     return -1;
// }

// vector<int> kmpProcess(string needle)
// {
//     int n = needle.size();
//     vector<int> lps(n, 0);
//     for (int i = 1, len = 0; i < n;)
//     {
//         if (needle[i] == needle[len])
//         {
//             lps[i++] = ++len;
//         }
//         else if (len)
//         {
//             len = lps[len - 1];
//         }
//         else
//         {
//             lps[i++] = 0;
//         }
//     }
//     return lps;
// }

#include <vtk_writer.h>

int main(int argc, char **argv)
{
    KiriLog::Init();
    KIRI_LOG_INFO("Initialized KiriLog System!");

    // vector<int> test{{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}};

    // auto lps = kmpTable("ll");

    // for (size_t i = 0; i < lps.size(); i++)
    // {
    //     KIRI_LOG_DEBUG("data = {0}", lps[i]);
    // }

    // KIRI_LOG_DEBUG("res={0}", strStr("aabaaabaaac", "aabaaac"));
    std::vector<v3> pos;
    float radius = 0.5f;
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            for (size_t k = 0; k < 10; k++)
            {
                auto p = Vector3F(i, j, k) * 2.f * radius;
                v3 v;
                v.data[0] = p.x;
                v.data[1] = p.y;
                v.data[2] = p.z;
                pos.emplace_back(v);
            }
        }
    }

    auto writer = std::make_shared<VTKWriter>("C:/Users/t69985/project/lib/CodeRepo/export/");
    writer->writeParticles("test.vtk", pos);

    return 0;
}