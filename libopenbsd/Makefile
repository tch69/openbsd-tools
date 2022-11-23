
LIB = openbsd

COPTS += -I../include

VPATH = .:compat:crypt:gen:stdlib:string:util
# compat
SRCS = getfsstat.c openbsd_statfs.c
# crypt
SRCS += arc4random.c
# gen
SRCS += fts.c errc.c getbsize.c getmntinfo.c pwcache.c setmode.c \
	verrc.c vwarnc.c warnc.c
# stdlib
SRCS += recallocarray.c strtonum.c
# string
SRCS += strmode.c
# util
# Most programs that require libutil only use fmt_scaled().
SRCS += fmt_scaled.c

.include "../mk.config"
.include <bsd.lib.mk>
