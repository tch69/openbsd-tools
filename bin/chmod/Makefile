#	$OpenBSD: Makefile,v 1.9 2017/05/28 08:03:36 awolk Exp $

PROG=	chmod
MAN=	chmod.1 chgrp.1 chown.8
LINKS=	chmod ${BINDIR}/chgrp \
	chmod ${BINDIR}/chown

LDADD = ${LIBOPENBSD}

.include <bsd.prog.mk>
