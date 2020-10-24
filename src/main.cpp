/*** 
 * @Author: Xu.WANG
 * @Date: 2020-10-19 00:02:37
 * @LastEditTime: 2020-10-23 12:11:10
 * @LastEditors: Xu.WANG
 * @Description: 
 * @FilePath: \CodeRepo\src\main.cpp
 */
#include <macro.h>
#include <kiri_log.h>
#include <kiri_timer.h>

#include <kiri_func.h>

int main(int argc, char **argv)
{
    KiriLog::Init();
    KIRI_LOG_INFO("Initialized KiriLog System!");

    KIRI_LOG_INFO("Bit Shift!");
    int a = 15, a1 = -15;
    KIRI_LOG_DEBUG("Value={0:d}, Right Shift {1:d}, Result={2:d}", a, 2, BIT_RS(a, 2));
    KIRI_LOG_DEBUG("Value={0:d}, Right Shift {1:d}, Result={2:d}", a1, 2, BIT_RS(a1, 2));
    KIRI_LOG_DEBUG("Value={0:d}, Left Shift {1:d}, Result={2:d}", a, 2, BIT_LS(a, 2));

    KIRI_LOG_INFO("Bit Judge Odd/Even!");
    KiriTimer timer("Odd/Even Print(Bit)");

    for (int i = 0; i < 1000000; ++i)
        if ((i & 1) == 0)
        {
            // KIRI_LOG_DEBUG("Even={0:d}", i);
        }

    timer.rlog();

    for (int i = 0; i < 1000000; ++i)
        if (i % 2 == 0)
        {
            //KIRI_LOG_DEBUG("Even={0:d}", i);
        }

    timer.rlog("Odd/Even Print(Normal)");

    KIRI_LOG_INFO("Swap Func!");
    a = 3, a1 = 13;
    KIRI_LOG_DEBUG("Swap Func, Before Swap: a={0:d}, a1={1:d}", a, a1);
    swap(a, a1);
    KIRI_LOG_DEBUG("Swap Func, After Swap: a={0:d}, a1={1:d}", a, a1);

    KIRI_LOG_DEBUG("Bit Swap Func, Before Swap: a={0:d}, a1={1:d}", a, a1);
    swap_bit(a, a1);
    KIRI_LOG_DEBUG("Bit Swap Func, After Swap: a={0:d}, a1={1:d}", a, a1);
}