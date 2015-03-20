/*
 * Copyright (c) 2016, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Google Inc. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Google Inc. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <stdlib.h>
#include <string.h>

#include <grpc/grpc.h>
#include <grpc/support/time.h>

void hs_gpr_now(gpr_timespec *result) {
    gpr_timespec t = gpr_now(GPR_CLOCK_REALTIME);
    memcpy(result, &t, sizeof(gpr_timespec));
}

void hs_gpr_timespec_free(gpr_timespec *timespec) {
	free(timespec);
}

gpr_timespec *hs_gpr_time_from_seconds(long x, gpr_timespec *result) {
    gpr_timespec t = gpr_time_from_seconds(x, GPR_TIMESPAN);
    memcpy(result, &t, sizeof(gpr_timespec));
    return result;
}

gpr_timespec *hs_gpr_time_add(gpr_timespec *a, gpr_timespec *b, gpr_timespec *result) {
    gpr_timespec t = gpr_time_add(*a, *b);
    memcpy(result, &t, sizeof(gpr_timespec));
    return result;
}

void hs_gpr_inf_future(gpr_timespec *result) {
    gpr_timespec t = gpr_inf_future(GPR_CLOCK_REALTIME);
    memcpy(result, &t, sizeof(gpr_timespec));
}
