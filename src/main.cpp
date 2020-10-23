/*** 
 * @Author: Xu.WANG
 * @Date: 2020-10-19 00:02:37
 * @LastEditTime: 2020-10-20 13:10:10
 * @LastEditors: Xu.WANG
 * @Description: 
 * @FilePath: \CodeRepo\src\main.cpp
 */
#include <macro.h>
#include <kiri_log.h>
#include <kiri_timer.h>

int main(int argc, char **argv)
{
    KiriLog::Init();
    KIRI_LOG_INFO("Initialized KiriLog System!");

    int a = 15, a1 = -15;
    KIRI_LOG_DEBUG("Value={0:d}, Right Shift {1:d}, Result={2:d}", a, 2, BIT_RS(a, 2));
    KIRI_LOG_DEBUG("Value={0:d}, Right Shift {1:d}, Result={2:d}", a1, 2, BIT_RS(a1, 2));
    KIRI_LOG_DEBUG("Value={0:d}, Left Shift {1:d}, Result={2:d}", a, 2, BIT_LS(a, 2));

    KiriTimer timer("Odd/Event Print(Bit)");

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

    timer.rlog("Odd/Event Print(Normal)");
}