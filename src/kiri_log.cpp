/*** 
 * @Author: Jayden Zhang
 * @Date: 2020-09-27 03:01:47
 * @LastEditTime: 2020-10-27 12:36:21
 * @LastEditors: Xu.WANG
 * @Description: 
 * @FilePath: \CodeRepo\src\kiri_log.cpp
 */

#include <kiri_log.h>
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/bin_to_hex.h"
std::shared_ptr<spdlog::logger> KiriLog::_logger;

void KiriLog::Init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");

    _logger = spdlog::stdout_color_mt("KIRI_LOG");
    _logger->set_level(spdlog::level::trace);
}