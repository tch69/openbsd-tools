#	$OpenBSD: Makefile,v 1.2 2003/07/22 00:11:30 millert Exp $

PROG   = diff3prog
MAN    = diff3.1
BINDIR = ${LIBEXECDIR}

beforeinstall:
	install -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
	    ${.CURDIR}/diff3.ksh ${DESTDIR}/${PREFIX}/bin/diff3

.include <bsd.prog.mk>
