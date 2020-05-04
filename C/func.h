#ifndef __FUNC_H_
#define __FUNC_H_

#define ZIPLIST_HEAD	0
#define ZIPLIST_TAIL	1

void sizeoutput();
unsigned char *ziplistNew(void);
unsigned char *ziplistPush(unsigned char *zl, unsigned char *s, unsigned int slen, int where);

#endif	//__FUNC_H_
