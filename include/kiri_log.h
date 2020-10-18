/*** 
 * @Author: Jayden Zhang
 * @Date: 2020-09-27 02:54:00
 * @LastEditTime: 2020-10-19 00:42:00
 * @LastEditors: Xu.WANG
 * @Description: 
 * @FilePath: \CodeRepo\include\kiri_log.h
 */

#ifndef _KIRI_LOG_H_
#define _KIRI_LOG_H_

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

class KiriLog
{
public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger> &GetLogger() { return _logger; };

private:
    static std::shared_ptr<spdlog::logger> _logger;
};

#define KIRI_LOG_TRACE(...) ::KiriLog::GetLogger()->trace(__VA_ARGS__)
#define KIRI_LOG_INFO(...) ::KiriLog::GetLogger()->info(__VA_ARGS__)
#define KIRI_LOG_DEBUG(...) ::KiriLog::GetLogger()->debug(__VA_ARGS__)
#define KIRI_LOG_WARN(...) ::KiriLog::GetLogger()->warn(__VA_ARGS__)
#define KIRI_LOG_ERROR(...) ::KiriLog::GetLogger()->error(__VA_ARGS__)
#define KIRI_LOG_FATAL(...) ::KiriLog::GetLogger()->fatal(__VA_ARGS__)

#endif