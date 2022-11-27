
LIB 	= openbsd
COPTS 	+= -Ihidden -Iinclude -I../include

.PATH: 	compat crypt db gen hash net stdio stdlib string util

# compat
SRCS 	+= getfsstat.c openbsd_open.c openbsd_statfs.c
# crypt
SRCS 	+= arc4random.c
# db
SRCS 	+= bt_open.c db.c hash.c mpool.c rec_open.c
# gen
SRCS 	+= devname.c errc.c fts.c getbsize.c getmntinfo.c pwcache.c \
	   setmode.c signame.c verrc.c vwarnc.c warnc.c
# hash
HELPER 	=  md5hl.c rmd160hl.c sha1hl.c \
	   sha224hl.c sha256hl.c sha384hl.c sha512hl.c sha512_256hl.c
SRCS 	+= md5.c rmd160.c sha1.c sha2.c ${HELPER}
# net
SRCS 	+= base64.c
# stdio
SRCS 	+= fgetwln.c
# stdlib
SRCS 	+= heapsort.c merge.c recallocarray.c strtonum.c
# string
SRCS 	+= strmode.c
# util
SRCS 	+= fmt_scaled.c ohash.c

CLEANFILES += ${HELPER}

beforedepend: md5hl.c rmd160hl.c sha1hl.c sha256hl.c sha384hl.c \
	sha512hl.c sha512_256hl.c

md5hl.c: 	helper.c
	sed -e 's/hashinc/md5.h/g' -e 's/HASH/MD5/g' $> > $@

rmd160hl.c:	helper.c
	sed -e 's/hashinc/rmd160.h/g' -e 's/HASH/RMD160/g' $> > $@

sha1hl.c:	helper.c
	sed -e 's/hashinc/sha1.h/g' -e 's/HASH/SHA1/g' $> > $@

sha224hl.c:	helper.c
	sed -e 's/hashinc/sha2.h/g' \
	    -e 's/HASH/SHA224/g' \
	    -e 's/SHA[0-9][0-9][0-9]_CTX/SHA2_CTX/g' $> > $@

sha256hl.c:	helper.c
	sed -e 's/hashinc/sha2.h/g' \
	    -e 's/HASH/SHA256/g' \
	    -e 's/SHA[0-9][0-9][0-9]_CTX/SHA2_CTX/g' $> > $@

sha384hl.c:	helper.c
	sed -e 's/hashinc/sha2.h/g' \
	    -e 's/HASH/SHA384/g' \
	    -e 's/SHA[0-9][0-9][0-9]_CTX/SHA2_CTX/g' $> > $@

sha512hl.c:	helper.c
	sed -e 's/hashinc/sha2.h/g' \
	    -e 's/HASH/SHA512/g' \
	    -e 's/SHA[0-9][0-9][0-9]_CTX/SHA2_CTX/g' $> > $@

sha512_256hl.c:	helper.c
	sed -e 's/hashinc/sha2.h/g' \
	    -e 's/HASH/SHA512_256/g' \
	    -e 's/SHA512_256_CTX/SHA2_CTX/g' $> > $@

install:

.include "../mk.config"
.include <bsd.lib.mk>

