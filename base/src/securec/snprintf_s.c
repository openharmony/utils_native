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

#include "securec.h"

/*******************************************************************************
 * <FUNCTION DESCRIPTION>
 *    The snprintf_s function is equivalent to the snprintf function
 *    except for the parameter destMax/count and the explicit runtime-constraints violation
 *    The snprintf_s function formats and stores count or fewer characters in
 *    strDest and appends a terminating null. Each argument (if any) is converted
 *    and output according to the corresponding format specification in format.
 *    The formatting is consistent with the printf family of functions; If copying
 *    occurs between strings that overlap, the behavior is undefined.
 *
 * <INPUT PARAMETERS>
 *    strDest                 Storage location for the output.
 *    destMax                 The size of the storage location for output. Size
 *                                 in bytes for snprintf_s or size in words for snwprintf_s.
 *    count                    Maximum number of character to store.
 *    format                  Format-control string.
 *    ...                        Optional arguments.
 *
 * <OUTPUT PARAMETERS>
 *    strDest                 is updated
 *
 * <RETURN VALUE>
 *    return  the number of characters written, not including the terminating null
 *    return -1 if an  error occurs.
 *    return -1 if count < destMax and the output string  has been truncated
 *
 * If there is a runtime-constraint violation, strDest[0] will be set to the '\0' when strDest and destMax valid
 *******************************************************************************
 */
int snprintf_s(char *strDest, size_t destMax, size_t count, const char *format, ...)
{
    int ret;                    /* If initialization causes  e838 */
    va_list arglist;

    va_start(arglist, format);
#ifndef __MINGW32__
    ret = vsnprintf_s(strDest, destMax, count, format, arglist);
#else
    ret = vsnprintf_truncated_s(strDest, destMax, format, arglist);
#endif
    va_end(arglist);
    (void)arglist;              /* to clear e438 last value assigned not used , the compiler will optimize this code */

    return ret;
}

#if SECUREC_SNPRINTF_TRUNCATED
int snprintf_truncated_s(char *strDest, size_t destMax, const char *format, ...)
{
    int ret;                    /* If initialization causes  e838 */
    va_list arglist;

    va_start(arglist, format);
    ret = vsnprintf_truncated_s(strDest, destMax, format, arglist);
    va_end(arglist);
    (void)arglist;              /* to clear e438 last value assigned not used , the compiler will optimize this code */

    return ret;
}
#endif


