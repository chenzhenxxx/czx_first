#ifndef _MSHELL_H_
#define _MSHELL_H_
void print_prompt();
void get_cmd(char *buf);
void explain_cmd(char *buf,int *cnt,char arglist[256][256]);
int find_cmd(char *command);
void do_cmd(int cnt,char (*arglist)[256]);
#endif