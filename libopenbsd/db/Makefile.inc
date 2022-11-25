#	$OpenBSD: Makefile.inc,v 1.8 2016/05/07 23:35:44 naddy Exp $
#
.PATH: db/btree db/db db/hash db/mpool db/recno

SRCS += bt_open.c

.PATH: db/db

SRCS+=	db.c

.PATH: db/hash

SRCS+= hash.c

.PATH: db/mpool

SRCS+=	mpool.c

.PATH: db/recno

SRCS+= rec_open.c
