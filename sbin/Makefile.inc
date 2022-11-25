
.include "../mk.config"

.if ${PREFIX} == "/usr"
BINDIR = /sbin
.else
BINDIR = ${PREFIX}/sbin
.endif

HEADERS = ../../include
LIBOPENBSD = ../../libopenbsd/libopenbsd.a
COPTS = -I${HEADERS}

