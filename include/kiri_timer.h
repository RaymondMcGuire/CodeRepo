/*** 
 * @Author: Xu.WANG
 * @Date: 2020-10-20 12:06:00
 * @LastEditTime: 2020-10-20 13:08:25
 * @LastEditors: Xu.WANG
 * @Description: 
 * @FilePath: \CodeRepo\include\kiri_timer.h
 */

#ifndef _KIRI_TIMER_H_
#define _KIRI_TIMER_H_

#include <iostream>
#include <string>
#include <chrono>

#include <kiri_log.h>

class KiriTimer
{
public:
    KiriTimer() : _name("Default")
    {
        restart();
    }

    explicit KiriTimer(const std::string &name) : _name(name)
    {
        restart();
    }

    inline void restart()
    {
        _start_time = std::chrono::steady_clock::now();
    }

    inline double elapsed(bool restart = false)
    {
        _end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff = _end_time - _start_time;
        if (restart)
            this->restart();
        return diff.count() * 1000;
    }

    void rlog(const std::string &tip = "", bool unit_ms = false)
    {
        log(true, tip, unit_ms, false);
    }

    /*** 
     * @description: 
     * @param {reset:reset timer or not; unit_ms: print ms / sec; tip: print extra info; kill: after print timer, kill thread or not}
     * @return {void}
     */
    void log(bool reset = false, const std::string &tip = "",
             bool unit_ms = true, bool kill = false)
    {
        if (unit_ms)
        {
            if (tip.length() > 0)
                KIRI_LOG_INFO("KiriTimer({0:s}) Time elapsed:{1:f} ms", tip, elapsed());
            else
                KIRI_LOG_INFO("KiriTimer({0:s}) Time elapsed:{1:f} ms", _name, elapsed());
        }
        else
        {
            if (tip.length() > 0)
                KIRI_LOG_INFO("KiriTimer({0:s}) Time elapsed:{1:f} s", tip, elapsed() / 1000.f);
            else
                KIRI_LOG_INFO("KiriTimer({0:s}) Time elapsed:{1:f} s", _name, elapsed() / 1000.f);
        }

        if (reset)
            this->restart();

        if (kill)
            exit(5);
    }

private:
    std::chrono::steady_clock::time_point _start_time;
    std::chrono::steady_clock::time_point _end_time;
    std::string _name;
};

#endif //_KIRI_TIMER_H_