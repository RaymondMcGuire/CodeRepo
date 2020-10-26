/*** 
 * @Author: Xu.WANG
 * @Date: 2020-10-19 00:02:37
 * @LastEditTime: 2020-10-26 13:11:18
 * @LastEditors: Xu.WANG
 * @Description: 
 * @FilePath: \CodeRepo\src\main.cpp
 */
#include <kiri_log.h>
#include <kiri_timer.h>

#include <kiri_func.h>

int main(int argc, char **argv)
{
    KiriLog::Init();
    KIRI_LOG_INFO("Initialized KiriLog System!");

    KIRI_LOG_INFO("Bit Shift!");
    int a = 15, a1 = -15;
    KIRI_LOG_DEBUG("Value={0}, Right Shift {1}, Result={2}", a, 2, BIT_RS(a, 2));
    KIRI_LOG_DEBUG("Value={0}, Right Shift {1}, Result={2}", a1, 2, BIT_RS(a1, 2));
    KIRI_LOG_DEBUG("Value={0}, Left Shift {1}, Result={2}", a, 2, BIT_LS(a, 2));

    KIRI_LOG_INFO("Bit Judge Odd/Even!");
    KiriTimer timer("Odd/Even Print(Bit)");

    for (int i = 0; i < 1000000; ++i)
        if ((i & 1) == 0)
        {
            // KIRI_LOG_DEBUG("Even={0}", i);
        }

    timer.rlog();

    for (int i = 0; i < 1000000; ++i)
        if (i % 2 == 0)
        {
            //KIRI_LOG_DEBUG("Even={0}", i);
        }

    timer.rlog("Odd/Even Print(Normal)");

    KIRI_LOG_INFO("Swap Func!");
    a = 3, a1 = 13;
    KIRI_LOG_DEBUG("Swap Func, Before Swap: a={0}, a1={1}", a, a1);
    swap(a, a1);
    KIRI_LOG_DEBUG("Swap Func, After Swap: a={0}, a1={1}", a, a1);

    KIRI_LOG_DEBUG("Bit Swap Func, Before Swap: a={0}, a1={1}", a, a1);
    swap_bit(a, a1);
    KIRI_LOG_DEBUG("Bit Swap Func, After Swap: a={0}, a1={1}", a, a1);

    KIRI_LOG_INFO("Sign Reverse Func!");
    a = 12354, a1 = -12345;
    int b = sign_reverse_bit(a);
    KIRI_LOG_DEBUG("Sign Reverse Func, Before Reverse: a={0}; After Reverse: a={1}", a, b);
    b = sign_reverse_bit(a1);
    KIRI_LOG_DEBUG("Sign Reverse Func, Before Reverse: a={0}; After Reverse: a={1}", a1, b);

    KIRI_LOG_INFO("Get Sign Func!");
    b = get_sign_bit(a);
    KIRI_LOG_DEBUG("Get Sign Func, Value ={0}; Sign ={1}", a, b);
    b = get_sign_bit(a1);
    KIRI_LOG_DEBUG("Get Sign Func, Value ={0}; Sign ={1}", a1, b);

    KIRI_LOG_INFO("Abs Bit Func!");
    b = abs_bit(a);
    KIRI_LOG_DEBUG("Abs Bit Func, Value ={0}; Abs ={1}", a, b);
    b = abs_bit(a1);
    KIRI_LOG_DEBUG("Abs Bit Func, Value ={0}; Abs ={1}", a1, b);
}