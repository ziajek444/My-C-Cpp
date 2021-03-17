#include <stdio.h>
#include "myutils.h"

int ERRNO_get(unsigned int err, char * dst_buffer, unsigned int dst_buffer_len)
{
    int ret = RET_OK;
    if ( dst_buffer_len < 0 ) {
        ret = RET_ILLEGAL_BUFFER_LEN;
        goto fin;
    }

	switch(err)
	{
		case 0:
            // int snprintf ( char * s, size_t n, const char * format, ... );
			snprintf(dst_buffer, dst_buffer_len, "No errors, errno 0");
            break;
		case EPERM:
            snprintf(dst_buffer, dst_buffer_len, "EPERM 1 Operation not permitted (POSIX.1-2001)");
            break;
		case ENOENT:
            snprintf(dst_buffer, dst_buffer_len, "ENOENT 2 No such file or directory (POSIX.1-2001).");
            break;
		case ESRCH:
            snprintf(dst_buffer, dst_buffer_len, "ESRCH 3 No such process (POSIX.1-2001).");
            break;
		case EINTR:
			snprintf(dst_buffer, dst_buffer_len, "EINTR 4 Interrupted function call (POSIX.1-2001); see signal(7).");
            break;
		case EIO:
			snprintf(dst_buffer, dst_buffer_len, "EIO 5 Input/output error (POSIX.1-2001).");
            break;
		case ENXIO:
			snprintf(dst_buffer, dst_buffer_len, "ENXIO 6 No such device or address (POSIX.1-2001).");
            break;
		case E2BIG:
			snprintf(dst_buffer, dst_buffer_len, "E2BIG 7 Argument list too long (POSIX.1-2001).");
            break;
		case ENOEXEC:
			snprintf(dst_buffer, dst_buffer_len, "ENOEXEC 8 Exec format error (POSIX.1-2001).");
            break;
		case EBADF:
			snprintf(dst_buffer, dst_buffer_len, "EBADF 9 Bad file descriptor (POSIX.1-2001).");
            break;
		case ECHILD:
			snprintf(dst_buffer, dst_buffer_len, "ECHILD 10 No child processes (POSIX.1-2001).");
            break;
		case EAGAIN:
			snprintf(dst_buffer, dst_buffer_len, "EAGAIN 11 Resource temporarily unavailable (may be the same value as\n"
			" EWOULDBLOCK) (POSIX.1-2001).");
            break;
		case ENOMEM:
			snprintf(dst_buffer, dst_buffer_len, "ENOMEM 12 Not enough space/cannot allocate memory (POSIX.1-2001).");
            break;
		case EACCES:
			snprintf(dst_buffer, dst_buffer_len, "EACCES 13 Permission denied (POSIX.1-2001).");
            break;
		case EFAULT:
			snprintf(dst_buffer, dst_buffer_len, "EFAULT 14 Bad address (POSIX.1-2001).");
            break;
		case ENOTBLK:
			snprintf(dst_buffer, dst_buffer_len, "ENOTBLK 15 Block device required.");
            break;
		case EBUSY:
			snprintf(dst_buffer, dst_buffer_len, "EBUSY 16 Device or resource busy (POSIX.1-2001).");
            break;
		case EEXIST:
			snprintf(dst_buffer, dst_buffer_len, "EEXIST 17 File exists (POSIX.1-2001).");
            break;
		case EXDEV:
			snprintf(dst_buffer, dst_buffer_len, "EXDEV 18 Improper link (POSIX.1-2001).");
            break;
		case ENODEV:
			snprintf(dst_buffer, dst_buffer_len, "ENODEV 19 No such device (POSIX.1-2001).");
            break;
		case ENOTDIR:
			snprintf(dst_buffer, dst_buffer_len, "ENOTDIR 20 Not a directory (POSIX.1-2001).");
            break;
		case EISDIR:
			snprintf(dst_buffer, dst_buffer_len, "EISDIR 21 Is a directory (POSIX.1-2001).");
            break;
		case EINVAL:
			snprintf(dst_buffer, dst_buffer_len, "EINVAL 22 Invalid argument (POSIX.1-2001).");
            break;
		case ENFILE:
			snprintf(dst_buffer, dst_buffer_len, "ENFILE 23 Too many open files in system (POSIX.1-2001).  On Linux,\n"
			"this is probably a result of encountering the\n"
			"/proc/sys/fs/file-max limit (see proc(5)).");
            break;
		case EMFILE:
			snprintf(dst_buffer, dst_buffer_len, "EMFILE 24 Too many open files (POSIX.1-2001).  Commonly caused by\n"
			"exceeding the RLIMIT_NOFILE resource limit described in\n"
			"getrlimit(2).  Can also be caused by exceeding the limit\n"
			"specified in /proc/sys/fs/nr_open.");
            break;
		case ENOTTY:
			snprintf(dst_buffer, dst_buffer_len, "ENOTTY 25 Inappropriate I/O control operation (POSIX.1-2001).");
            break;
		case ETXTBSY:
			snprintf(dst_buffer, dst_buffer_len, "ETXTBSY 26 Text file busy (POSIX.1-2001).");
            break;
		case EFBIG:
			snprintf(dst_buffer, dst_buffer_len, "EFBIG 27 File too large (POSIX.1-2001).");
            break;
		case ENOSPC:
			snprintf(dst_buffer, dst_buffer_len, "ENOSPC 28 No space left on device (POSIX.1-2001).");
            break;
		case ESPIPE:
			snprintf(dst_buffer, dst_buffer_len, "ESPIPE 29 Invalid seek (POSIX.1-2001).");
            break;
		case EROFS:
			snprintf(dst_buffer, dst_buffer_len, "EROFS 30 Read-only filesystem (POSIX.1-2001).");
            break;
		case EMLINK:
			snprintf(dst_buffer, dst_buffer_len, "EMLINK 31 Too many links (POSIX.1-2001).");
            break;
		case EPIPE:
			snprintf(dst_buffer, dst_buffer_len, "EPIPE 32 Broken pipe (POSIX.1-2001).");
            break;
		case EDOM:
			snprintf(dst_buffer, dst_buffer_len, "EDOM 33 Mathematics argument out of domain of function (POSIX.1,C99).");
            break;
		case ERANGE:
			snprintf(dst_buffer, dst_buffer_len, "ERANGE 34 Result too large (POSIX.1, C99).");
            break;
		default:
			snprintf(dst_buffer, dst_buffer_len, "Unspecified errno, errno: [%d] ", err);
            ret = RET_UNSPECIFIED;
	}

    fin:
        return ret;
}

int main(void) {
    printf("Test myutils \n");
    char buf[100];
    // test
    int err = 0;
    for ( ; err < 36; err++ ) {
        printf("%d ", ERRNO_get(err, buf, sizeof(buf)));
        printf("%s \n", buf);
    }

    return 0;
}