#	$OpenBSD: Makefile,v 1.15 2016/03/30 06:38:40 jmc Exp $

PROG=	md5sum
SRCS=	crc.c md5.c
MAN=	cksum.1 md5sum.1
LINKS=	${BINDIR}/md5sum ${BINDIR}/sha1sum \
	${BINDIR}/md5sum ${BINDIR}/sha256sum \
	${BINDIR}/md5sum ${BINDIR}/sha512sum \
	${BINDIR}/md5sum ${BINDIR}/cksum \

CPPFLAGS+= -I${.CURDIR}
COPTS+=	-Wall -Wconversion -Wmissing-prototypes
LDADD=${LIBOPENBSD}

.include <bsd.prog.mk>
