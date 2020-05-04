#ifndef _APUE_H_
#define _APUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void err_msg(const char *fmt, ...);
void err_quit(const char *fmt, ...) __attribute__ ((noreturn));
void err_sys(const char *fmt, ...) __attribute__ ((noreturn));
void err_ret(const char *fmt, ...);

#define MAXLINE 4096

#endif //_APUE_H_
