#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebook.h"

int main(int argc, char **argv) {

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


return;
	int _n = atoi(argv[1]);
	if (_n&(sizeof(long)-1)) _n += sizeof(long)-(_n&(sizeof(long)-1));
	printf("%d\n", _n);
return ;
	threadTest();
}
