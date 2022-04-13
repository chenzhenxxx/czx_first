#ifndef _MSHELL_H_
#define _MSHELL_H_
#include<stdio.h>
#include<errno.h>
#include<linux/limits.h>
#include<sys/stat.h>
#include<dirent.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
void print_prompt();
void get_cmd(char *buf,char *arglist[256]);
void explain_cmd(char *buf,int *cnt,char arglist[256][256]);
int find_cmd(char *command);
void do_cmd(int cnt);
int cmd_cdx(int left,int right);
int cmd_pipe(int left,int right);
void cmd_cd(char *arglist[256]);
#endif