/* __dead is defined in sys/cdefs.h, but we don't use it */
#ifndef __dead
#define __dead __attribute__((noreturn))
#endif

#ifndef __unused
#define __unused __attribute__((unused))
#endif

extern char *__progname;


#define MAKE_CLONE(x,y) typeof(x) x __attribute__((alias (#y)))

#ifdef _SYS_PARAM_H
#if defined(__aarch64__)
#define ALIGNBYTES	(sizeof(long) - 1)
#define MACHINE		"aarch64"
#define MACHINE_ARCH	"aarch64"
#elif defined(__arm__)
#define ALIGNBYTES      (sizeof(double) - 1)
#define MACHINE		"arm"
#define MACHINE_ARCH	"arm"
#elif defined(__i386__)
#define ALIGNBYTES      (sizeof(int) - 1)
#define MACHINE		"i386"
#define MACHINE_ARCH 	"i386"
#elif defined(__powerpc__) || defined(__ppc__)
#define ALIGNBYTES	(sizeof(double) - 1)
#define MACHINE 	"powerpc"
#define MACHINE_ARCH	"powerpc"
#elif defined(__x86_64__)
#define ALIGNBYTES 	(sizeof(long) - 1)
#define MACHINE 	"x86_64"
#define MACHINE_ARCH	"x86_64"
#else
#define ALIGNBYTES      (sizeof(int) - 1)
#define MACHINE		"unknown"
#define MACHINE_ARCH	"unknown"
#endif

#define ALIGN(p) (((unsigned long)(p) + ALIGNBYTES) & ~ALIGNBYTES)
#endif

#if defined(_SYS_MOUNT_H)
/*
 * Flags for various system call interfaces.
 *
 * waitfor flags to vfs_sync() and getfsstat()
 */
#define MNT_NOWAIT      1
#define MNT_WAIT        2
#define MNT_LAZY        3

/*
 * Flags set by internal operations.
 */
#define MNT_LOCAL       0x00001000      /* filesystem is stored locally */
#define MNT_QUOTA       0x00002000      /* quotas are enabled on filesystem */
#define MNT_ROOTFS      0x00004000      /* identifies the root filesystem */
#define MNT_RDONLY      0x00000001      /* read only filesystem */

/*
 * file system statistics
 */

#define MFSNAMELEN      16      /* length of fs type name, including nul */
#define MNAMELEN        90      /* length of buffer for returned name */

#ifdef _SYS_STATFS_H

struct openbsd_statfs {
        struct statfs buf;
        dev_t st_dev;
        char f_fstypename[MFSNAMELEN];  /* fs type name */
        char f_mntonname[MNAMELEN];     /* directory on which mounted */
        char f_mntfromname[MNAMELEN];   /* mounted file system */
        char f_mntfromspec[MNAMELEN];   /* special for mount request */
};

#if defined(__OpenBSD_statfs)
#define statfs          openbsd_statfs

#define f_blocks        buf.f_blocks
#define f_bsize         buf.f_bsize
#define f_bfree         buf.f_bfree
#define f_bavail        buf.f_bavail

#define f_files         buf.f_files
#define f_ffree         buf.f_ffree
#define f_flags         buf.f_flags
#endif  /* __OpenBSD_statfs */

int getmntinfo(struct openbsd_statfs **, int);
int getfsstat(struct openbsd_statfs *, size_t, int);
int openbsd_statfs(const char *, struct openbsd_statfs *);
#endif /* _SYS_STATFS_H */
#endif /* _SYS_MOUNT_H */


#ifdef _SYS_STAT_H
#define S_ISTXT 	S_ISVTX
#define S_BLKSIZE 512

#define ACCESSPERMS 	(S_IRWXU|S_IRWXG|S_IRWXO) /* 00777 */
#define DEFFILEMODE 	(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

#define st_atimespec 	st_atim
#define st_ctimespec	st_ctim
#define st_mtimespec	st_mtim

#define st_atimensec	st_atim.tv_nsec
#define st_ctimensec	st_ctim.tv_nsec
#define st_mtimensec	st_mtim.tv_nsec

#endif

#ifdef _SYS_TIME_H
#define timespecclear(tsp) (tsp)->tv_sec = (tsp)->tv_nsec = 0
#define timespecisset(tsp) ((tsp)->tv_sec || (tsp)->tv_nsec)

#define timespecsub(tsp, usp, vsp)					\
	do {								\
		(vsp)->tv_sec = (tsp)->tv_sec - (usp)->tv_sec;		\
		(vsp)->tv_nsec = (tsp)->tv_nsec - (usp)->tv_nsec;	\
		if ((vsp)->tv_nsec < 0) {				\
			(vsp)->tv_sec--;				\
			(vsp)->tv_nsec += 1000000000L;			\
		}							\
	} while (0)
#endif

#ifdef _SYS_TTYDEFAULTS_H
#define TTYDISC 0
#endif

#ifdef _ERR_H
__dead void	errc(int, int, const char *, ...)
			__attribute__((__format__ (printf, 3, 4)));
__dead void 	verrc(int, int, const char *, va_list)
			__attribute__((__format__ (printf, 3, 0)));
void		warnc(int, const char *, ...)
			__attribute__((__format__ (printf, 2, 3)));
void            vwarnc(int, const char *, va_list)
			__attribute__((__format__ (printf, 2, 0)));
void		warnx(const char *, ...)
			__attribute__((__format__ (printf, 1, 2)));
#endif

#ifdef _ERRNO_H
#define EFTYPE ENOTSUP
#endif

#ifdef _FCNTL_H
#ifdef __OpenBSD_open
#define open openbsd_open

#define O_EXLOCK 10000000
#define O_SHLOCK 20000000
#endif /* __OpenBSD_open */
#endif

#ifdef _GRP_H
#define GID_MAX UINT_MAX
int 		gid_from_group(const char *, gid_t *);
const char 	*group_from_gid(gid_t, int);
#endif

#ifdef _PATHS_H
#define _PATH_DEVDB "/var/run/dev.db"
#endif

#ifdef _PWD_H
#define UID_MAX UINT_MAX
int		uid_from_user(const char *, uid_t *);
const char	*user_from_uid(uid_t, int);
#endif

#ifdef _REGEX_H
#define REG_BASIC 	0000
#define REG_STARTEND 	00004
#endif

#ifdef _RESOLV_H
int b64_ntop(unsigned char const *, size_t, char *, size_t);
#endif

#ifdef _SIGNAL_H
#define SIGINFO SIGUSR1
extern const char *const sys_signame[_NSIG];
#endif

#ifdef _STDLIB_H
#ifdef _SYS_STAT_H
char 	*devname(dev_t, mode_t);
#endif
int		heapsort(void *, size_t, size_t, int (*)(const void *, const void *));
int		mergesort(void *, size_t, size_t, int (*)(const void *, const void *));
char 		*getbsize(int *, long *);
void 		*recallocarray(void *, size_t, size_t, size_t);
long long 	strtonum(const char *, long long, long long, const char **);

#ifdef _STDINT_H
uint32_t arc4random(void);
#endif /* _STDINT_H */
void arc4random_buf(void *, size_t);
#endif /* _STDLIB_H */

#ifdef _STRING_H
void 	strmode(int, char*);
#endif

#ifdef _UNISTD_H
#ifdef _SYS_STAT_H
mode_t 	getmode(const void *, mode_t);
void 	*setmode(const char *);
#endif
#endif

#ifdef _WCHAR_H
wchar_t *fgetwln(FILE * __restrict, size_t * __restrict);
#endif
