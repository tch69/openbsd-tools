
.include "../mk.config"

.if ${PREFIX} == "/usr"
BINDIR = /bin
.endif

HEADERS = ../../include
LIBOPENBSD = ../../libopenbsd/libopenbsd.a
COPTS = -I${HEADERS}

