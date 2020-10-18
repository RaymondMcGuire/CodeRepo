/*** 
 * @Author: Xu.WANG
 * @Date: 2020-10-19 00:02:37
 * @LastEditTime: 2020-10-19 00:53:16
 * @LastEditors: Xu.WANG
 * @Description: 
 * @FilePath: \CodeRepo\src\main.cpp
 */
#include <macro.h>
#include <kiri_log.h>

int main(int argc, char **argv)
{
    KiriLog::Init();
    KIRI_LOG_INFO("Initialized KiriLog System!");

    int a = 15, a1 = -15;
    KIRI_LOG_DEBUG("Value={0:d}, Right Shift {1:d}, Result={2:d}", a, 2, BIT_RS(a, 2));
    KIRI_LOG_DEBUG("Value={0:d}, Right Shift {1:d}, Result={2:d}", a1, 2, BIT_RS(a1, 2));
    KIRI_LOG_DEBUG("Value={0:d}, Left Shift {1:d}, Result={2:d}", a, 2, BIT_LS(a, 2));
}