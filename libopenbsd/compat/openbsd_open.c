#include <sys/file.h>

#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define __OpenBSD_open
#include <compat.h>

int
openbsd_open(const char *path, int flags, ...) 
{
	va_list ap;
	int fd, lock;

	lock = flags & (O_EXLOCK | O_SHLOCK);
	flags &= ~lock;

	va_start(ap, flags);
	if ((fd = open(path, flags, ap)) == -1) 
		return -1;
	va_end(ap);

	if (lock == 0)
		return fd;

	if (flock(fd, lock & O_EXLOCK ? LOCK_EX : LOCK_SH) == -1) {
		close(fd);
		return -1;
	}

	return fd;
}
