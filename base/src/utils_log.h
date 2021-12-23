/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef UTILS_BASE_LOG_H
#define UTILS_BASE_LOG_H

#ifdef CONFIG_HILOG
#include "hilog_base/log_base.h"
namespace UtilsLog {
constexpr LogType TYPE = LOG_CORE;
constexpr unsigned int DOMAIN = 0xD003D00;
constexpr const char *TAG = "utils_base";
} // namespace UtilsLog
#define UTILS_LOGF(...) (void)HiLogBasePrint(UtilsLog::TYPE, LOG_FATAL, UtilsLog::DOMAIN, UtilsLog::TAG, __VA_ARGS__)
#define UTILS_LOGE(...) (void)HiLogBasePrint(UtilsLog::TYPE, LOG_ERROR, UtilsLog::DOMAIN, UtilsLog::TAG, __VA_ARGS__)
#define UTILS_LOGW(...) (void)HiLogBasePrint(UtilsLog::TYPE, LOG_WARN, UtilsLog::DOMAIN, UtilsLog::TAG, __VA_ARGS__)
#define UTILS_LOGI(...) (void)HiLogBasePrint(UtilsLog::TYPE, LOG_INFO, UtilsLog::DOMAIN, UtilsLog::TAG, __VA_ARGS__)
#define UTILS_LOGD(...) (void)HiLogBasePrint(UtilsLog::TYPE, LOG_DEBUG, UtilsLog::DOMAIN, UtilsLog::TAG, __VA_ARGS__)
#else
#define UTILS_LOGF(...)
#define UTILS_LOGE(...)
#define UTILS_LOGW(...)
#define UTILS_LOGI(...)
#define UTILS_LOGD(...)
#endif  // CONFIG_HILOG

#if (defined CONFIG_HILOG) && (defined CONFIG_PARCEL_DEBUG)
namespace ParcelLog {
constexpr LogType TYPE = LOG_CORE;
constexpr unsigned int DOMAIN = 0xD003D01;
constexpr const char *TAG = "parcel";
} // namespace ParcelLog
#define PARCEL_LOGF(...) \
    (void)HiLogBasePrint(ParcelLog::TYPE, LOG_FATAL, ParcelLog::DOMAIN, ParcelLog::TAG, __VA_ARGS__)
#define PARCEL_LOGE(...) \
    (void)HiLogBasePrint(ParcelLog::TYPE, LOG_ERROR, ParcelLog::DOMAIN, ParcelLog::TAG, __VA_ARGS__)
#define PARCEL_LOGW(...) \
    (void)HiLogBasePrint(ParcelLog::TYPE, LOG_WARN, ParcelLog::DOMAIN, ParcelLog::TAG, __VA_ARGS__)
#define PARCEL_LOGI(...) \
    (void)HiLogBasePrint(ParcelLog::TYPE, LOG_INFO, ParcelLog::DOMAIN, ParcelLog::TAG, __VA_ARGS__)
#define PARCEL_LOGD(...) \
    (void)HiLogBasePrint(ParcelLog::TYPE, LOG_DEBUG, ParcelLog::DOMAIN, ParcelLog::TAG, __VA_ARGS__)
#else
#define PARCEL_LOGF(...)
#define PARCEL_LOGE(...)
#define PARCEL_LOGW(...)
#define PARCEL_LOGI(...)
#define PARCEL_LOGD(...)
#endif  // (defined CONFIG_HILOG) && (defined CONFIG_PARCEL_DEBUG)

#endif  // UTILS_BASE_LOG_H
