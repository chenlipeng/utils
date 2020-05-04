#include "func.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define intrev32ifbe(v)			(v)
#define ZIP_END 255
#define ZIPLIST_HEADER_SIZE		(sizeof(uint32_t)*2+sizeof(uint16_t))
#define ZIPLIST_BYTES(zl)		(*((uint32_t*)(zl)))
#define ZIPLIST_TAIL_OFFSET(zl)	(*((uint32_t*)((zl)+sizeof(uint32_t))))
#define ZIPLIST_LENGTH(zl)		(*((uint16_t*)((zl)+sizeof(uint32_t)*2)))

#define ZIPLIST_ENTRY_HEAD(zl)	((zl)+ZIPLIST_HEADER_SIZE)
#define ZIPLIST_ENTRY_TAIL(zl)	((zl)+intrev32ifbe(ZIPLIST_TAIL_OFFSET(zl)))
#define ZIPLIST_ENTRY_END(zl)	((zl)+intrev32ifbe(ZIPLIST_BYTES(zl))-1)

typedef struct zlentry {
	unsigned int prevrawlensize, prevrawlen;
	unsigned int lensize, len;
	unsigned int headersize;
	unsigned char encoding;
	unsigned char *p;
} zlentry;

void sizeoutput() {
	printf("size: %d\t%d\n", sizeof(zlentry), sizeof(void*));
}

unsigned char *ziplistNew(void) {
	unsigned int bytes = ZIPLIST_HEADER_SIZE + 1;
	unsigned char *zl = (unsigned char*)malloc(bytes);
	ZIPLIST_BYTES(zl) = intrev32ifbe(bytes);
	ZIPLIST_TAIL_OFFSET(zl)	= intrev32ifbe(ZIPLIST_HEADER_SIZE);
	ZIPLIST_LENGTH(zl) = 0;
	zl[bytes-1] = ZIP_END;
	return zl;
}

unsigned char *__ziplistInsert(unsigned char *zl, unsigned char *p, unsigned char *s, unsigned int slen) {
	size_t curlen = intrev32ifbe(ZIPLIST_BYTES(zl)), reqlen;
	unsigned int prevlensize, prevlen = 0;
	size_t offset;
	int nextdiff;
	unsigned char encoding = 0;
	long long value = 123456789;

	zlentry tail;
	return zl;
}

unsigned char *ziplistPush(unsigned char *zl, unsigned char *s, unsigned int slen, int where) {
	unsigned char *p;
	p = (where == ZIPLIST_HEAD) ? ZIPLIST_ENTRY_HEAD(zl) : ZIPLIST_ENTRY_END(zl);
	return __ziplistInsert(zl,p,s,slen);
}
