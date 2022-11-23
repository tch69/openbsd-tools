#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/statfs.h>
#include <string.h>

#include <compat.h>

int
openbsd_statfs(const char *path, struct openbsd_statfs *buf)
{
	struct statfs sfb;
        struct stat sb;
        struct openbsd_statfs *mntbuf;
        int num, i;

        if (stat(path, &sb) == -1)
                return -1;

        if (!(num = getmntinfo(&mntbuf, MNT_WAIT)))
                return -1;

        for (i = 0; i < num; i++)
                if (mntbuf[i].st_dev == sb.st_dev) {
                        if (statfs(path, &sfb) == -1)
                                return -1;
                        memcpy(&mntbuf[i].buf, &sfb, sizeof sfb);
                        memcpy(buf, &mntbuf[i], sizeof (struct openbsd_statfs));
                        break;
                }

        return 0;
}
