/*  DO NOT EDIT THIS FILE.

    It has been auto-edited by fixincludes from:

	"/data/jenkins/workspace/GNU-toolchain/arm-11/build-arm-none-linux-gnueabihf/install/arm-none-linux-gnueabihf/libc/usr/include/bits/unistd_ext.h"

    This had to be done to correct non-standard usages in the
    original, manufacturer supplied header file.  */

/* System-specific extensions of <unistd.h>, Linux version.
   Copyright (C) 2019-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _UNISTD_H
# error "Never include <bits/unistd_ext.h> directly; use <unistd.h> instead."
#endif

#ifdef __USE_GNU

/* Return the kernel thread ID (TID) of the current thread.  The
   returned value is not subject to caching.  Most Linux system calls
   accept a TID in place of a PID.  Using the TID to change properties
   of a thread that has been created using pthread_create can lead to
   undefined behavior (comparable to manipulating file descriptors
   directly that have not been created explicitly).  Note that a TID
   uniquely identifies a thread only while this thread is running; a
   TID can be reused once a thread has exited, even if the thread is
   not detached and has not been joined.  */
extern __pid_t gettid (void) __THROW;

#ifdef __has_include
# if __has_include ("__linux__/close_range.h")
#  include "linux/close_range.h"
# endif
#endif
/* Unshare the file descriptor table before closing file descriptors.  */
#ifndef CLOSE_RANGE_UNSHARE
# define CLOSE_RANGE_UNSHARE (1U << 1)
#endif
/* Set the FD_CLOEXEC bit instead of closing the file descriptor.  */
#ifndef CLOSE_RANGE_CLOEXEC
# define CLOSE_RANGE_CLOEXEC (1U << 2)
#endif

/* Close all file descriptors in the range FD up to MAX_FD.  The flag FLAGS
   are define by the CLOSE_RANGE prefix.  This function behaves like close
   on the range, but in a fail-safe where it will either fail and not close
   any file descriptor or close all of them.  Gaps where the file descriptor
   is invalid are ignored.   Returns 0 on successor or -1 for failure (and
   sets errno accordingly).  */
extern int close_range (unsigned int __fd, unsigned int __max_fd,
			int __flags) __THROW;

#endif /* __USE_GNU  */
