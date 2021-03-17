#include "errno-base.h"

#define RET_OK 0
#define RET_UNSPECIFIED 1
#define RET_ILLEGAL_BUFFER_LEN -1

int ERRNO_get(unsigned int err, char * dst_buffer, unsigned int dst_buffer_len);