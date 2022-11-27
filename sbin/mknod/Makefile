#	$OpenBSD: Makefile,v 1.5 2001/08/21 17:55:47 millert Exp $

PROG  = mknod
MAN   = mknod.8 mkfifo.1
LDADD = ${LIBOPENBSD}

.include "../../mk.config"

.if ${PREFIX} == /usr
LINKS = ${BINDIR}/mknod /usr/bin/mkfifo
.else
LINKS = ${BINDIR}/mknod ${PREFIX}/bin/mkfifo
.endif

.include <bsd.prog.mk>
