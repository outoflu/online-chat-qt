#include "spdlog/spdlog.h"
#include "spdlog/sinks/daily_file_sink.h"


void use_spdlog_test() {
    // 创建一个每天早上6点轮换的日志文件
    auto daily_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>("logs/daily", 6, 0);
    // 设置日志记录器
    auto logger = std::make_shared<spdlog::logger>("daily_logger", daily_sink);
    spdlog::register_logger(logger);

    // 设置日志格式和级别
    logger->set_pattern("[%Y-%m-%d %H:%M:%S] [thread %t] %v");
    logger->set_level(spdlog::level::info);

    // 写入日志
    logger->info("Hello, spdlog!");
    logger->flush();
    return;
}

