#	$OpenBSD: Makefile,v 1.4 2000/07/19 19:30:10 mickey Exp $

PROG=	find
SRCS=	find.c function.c ls.c main.c misc.c operator.c option.c

CPPFLAGS += -D__OpenBSD_statfs
LDADD = ${LIBOPENBSD}

.include <bsd.prog.mk>
