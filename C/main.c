#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "notebook.h"
#include "skiplist.h"
#include "func.h"

int main(int argc, char **argv) {

	sizeoutput();
return 0;

	char buf[32];
	sprintf(buf, "100");
	printf("%s\n", buf);

return 0;
	printf("%d\t%d\n", rand(), rand());

return 0;

	unsigned char *zl = ziplistNew();
	printf("%d\t%d\t%d\t%x\n", *(uint32_t*)(zl), *(uint32_t*)(zl+sizeof(uint32_t)), *(uint16_t*)(zl+sizeof(uint32_t) * 2), *((uint8_t*)(zl + *(uint32_t*)(zl+sizeof(uint32_t)))));
	free(zl);
return 0;
	printf("%d %d %d\n", sizeof(zskiplist), sizeof(zskiplistNode), sizeof(unsigned long));

return;
	printf("%d\n", sizeof(void *));

return 0;
	long endian = 0x123456789abcdefe;
	int endianIndex = 0;
	char *endianPtr = (char*)&endian;
	for (; endianIndex<8; ++endianIndex) {
		printf("%2x\n", *endianPtr++);
	}
	printf("\n%d\n", sizeof(long));

return 0;

return 0;
#if defined(__unix)
printf("__unix__\n");
#endif


return 0;
	printf("size: %ld\n", zmalloc_get_memory_size());

return 0;
	get_sys_info();

#ifdef __linux__
	char *str = "abcdefghijklmnopqrstuvwxyz";
	char *strptr = strdup(str);
	printf("%s\n", strptr);
	free(strptr);
#endif

return 0;

#if defined(PRINT_INFO)
	printf("xxxxxxxxxxxxx\n");
#else
	printf("yyyyyyyyyyyyyyyyy\n");
#endif


return 0;
	int _n = atoi(argv[1]);
	if (_n&(sizeof(long)-1)) _n += sizeof(long)-(_n&(sizeof(long)-1));
	printf("%d\n", _n);
return 0;
	threadTest();
}
