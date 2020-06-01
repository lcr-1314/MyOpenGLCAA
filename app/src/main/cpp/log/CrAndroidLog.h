//
// Created by lenovo on 2020/6/1.
//

#ifndef MYOPENGLCAA_CRANDROIDLOG_H
#define MYOPENGLCAA_CRANDROIDLOG_H

#include "android/log.h"

#define LOGD(FORMAT,...) __android_log_print(ANDROID_LOG_DEBUG,"lcr",FORMAT,##__VA_ARGS__);
#define LOGE(FORMAT,...) __android_log_print(ANDROID_LOG_ERROR,"lcr",FORMAT,##__VA_ARGS__);
#define LOGW(FORMAT,...) __android_log_print(ANDROID_LOG_WARN,"lcr",FORMAT,##__VA_ARGS__);

#endif //MYOPENGLCAA_CRANDROIDLOG_H