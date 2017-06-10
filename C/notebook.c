#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <memory.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//--------------------------------------------------------------------------------------------------------------------------------------------------

size_t zmalloc_get_memory_size(void) {
#if defined(__unix__) || defined(__unix) || defined(unix) || \
    (defined(__APPLE__) && defined(__MACH__))
#if defined(CTL_HW) && (defined(HW_MEMSIZE) || defined(HW_PHYSMEM64))
    int mib[2];
    mib[0] = CTL_HW;
#if defined(HW_MEMSIZE)
    mib[1] = HW_MEMSIZE;            /* OSX. --------------------- */
#elif defined(HW_PHYSMEM64)
    mib[1] = HW_PHYSMEM64;          /* NetBSD, OpenBSD. --------- */
#endif
    int64_t size = 0;               /* 64-bit */
    size_t len = sizeof(size);
    if (sysctl( mib, 2, &size, &len, NULL, 0) == 0)
        return (size_t)size;
    return 0L;          /* Failed? */

#elif defined(_SC_PHYS_PAGES) && defined(_SC_PAGESIZE)
    /* FreeBSD, Linux, OpenBSD, and Solaris. -------------------- */
    return (size_t)sysconf(_SC_PHYS_PAGES) * (size_t)sysconf(_SC_PAGESIZE);

#elif defined(CTL_HW) && (defined(HW_PHYSMEM) || defined(HW_REALMEM))
    /* DragonFly BSD, FreeBSD, NetBSD, OpenBSD, and OSX. -------- */
    int mib[2];
    mib[0] = CTL_HW;
#if defined(HW_REALMEM)
    mib[1] = HW_REALMEM;        /* FreeBSD. ----------------- */
#elif defined(HW_PYSMEM)
    mib[1] = HW_PHYSMEM;        /* Others. ------------------ */
#endif
    unsigned int size = 0;      /* 32-bit */
    size_t len = sizeof(size);
    if (sysctl(mib, 2, &size, &len, NULL, 0) == 0)
        return (size_t)size;
    return 0L;          /* Failed? */
#endif /* sysctl and sysconf variants */

#else
    return 0L;          /* Unknown OS. */
#endif
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
void get_sys_info() {
	int page = sysconf(_SC_PAGESIZE);
	size_t rss;
	char filename[256];
	char buf[4096];
	int fd, count;
	char *p, *x;

    snprintf(filename,256,"/proc/%d/stat",getpid());

    if ((fd = open(filename,O_RDONLY)) == -1) return;
	if (read(fd, buf, 4096) <= 0) {
		close(fd);
		return;
	}
	close(fd);
printf("%s: %s\n", filename, buf);

	p = buf;
    count = 23; /* RSS is the 24th field in /proc/<pid>/stat */
	while (p && count--) {
		p = strchr(p, ' ');
		//printf("%s\n", p);
		if (p) ++p;
	}

	printf("%s\n", p);
	if (!p) return;
	x = strchr(p, ' ');
	if (!x) return;
	*x = '\0';
	printf("%s\n", p);

    rss = strtoll(p,NULL,10);

	printf("pagesize: %d\nfilename: %s\nfilecontent: %s\nrss: %d\n", page, filename, buf, rss * page);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
#define WITH_THREAD_MUTEX

#if defined(WITH_THREAD_MUTEX)
#define atomicIncr(var, count, mutex) do {	\
	pthread_mutex_lock(&mutex);	\
	var += (count);	\
	pthread_mutex_unlock(&mutex);	\
} while (0)
#else
#define atomicIncr(var, count, mutex) do {	\
	var += (count);	\
} while (0)

#endif

static size_t threadVal = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void valAdd() {
	int i;
	for (i=0; i<300000000; ++i) {
		atomicIncr(threadVal, 1, mutex);
		//printf("--------\n");
	}
}

void threadTest() {
	pthread_t id;
	int i, ret;
	ret = pthread_create(&id, NULL, (void *) valAdd, NULL);

	for (i=0; i<300000000; ++i) {
		atomicIncr(threadVal, 1, mutex);
		//printf("======\n");
	}
	pthread_join(id, NULL);
	printf("threadVal: %d\n", threadVal);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

void logInfo(char *fmt, ...) {
	char staticbuf[1024];

	va_list vlist;
	va_start(vlist, fmt);
	vsnprintf(staticbuf, sizeof(staticbuf), fmt, vlist);
	va_end(vlist);

	printf("LOG: %s", staticbuf);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
