#ifndef _LS_H_
#define _LS_H_

#include <dirent.h>

void readdir_recursive(const char *dirname, int depth);
void prefix_output(int depth);

#endif //_LS_H_
