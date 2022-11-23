/*	$OpenBSD: pwcache.c,v 1.15 2018/09/22 02:47:23 millert Exp $	*/

/*-
 * Copyright (c) 1992 Keith Muller.
 * Copyright (c) 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Keith Muller of the University of California, San Diego.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <grp.h>
#include <pwd.h>
#include <stddef.h>

#include <compat.h>

/*
 * user_from_uid() returns the username associated with uid.
 */
const char *
user_from_uid(uid_t uid, int noname)
{
	return (getpwuid(uid)->pw_name);
}

/*
 * group_from_gid() returns the group name associated with gid.
 */
const char *
group_from_gid(gid_t gid, int noname)
{
	return (getgrgid(gid)->gr_name);
}

/*
 * uid_from_user() returns 0 if the username associated with uid 
 * is found, or -1 otherwise.
 */
int
uid_from_user(const char *name, uid_t *uid)
{
	struct passwd *pw;
	
	if ((pw = getpwnam(name)) == NULL) {
		return (-1);
	} 
	else {
		*uid = pw->pw_uid;
		return 0;
	};
}

/*
 * gid_from_group()
 *	caches the gid for a given group name. We use a simple hash table.
 * Return:
 *	0 if the group name is found (filling in gid), -1 otherwise
 */
int
gid_from_group(const char *name, gid_t *gid)
{
	struct group *gr;

	if ((gr = getgrnam(name)) == NULL) {
		return (-1);
	}
	else {
		*gid = gr->gr_gid;
		return 0;
	}
}
