#ifndef _MSHELL_H_
#define _MSHELL_H_
void print_prompt();
void get_cmd(char *buf,char *arglist[256]);
void explain_cmd(char *buf,int *cnt,char arglist[256][256]);
int find_cmd(char *command);
void do_cmd(int cnt);
int cmd_cdx(int left,int right);
int cmd_pipe(int left,int right);
void cmd_cd(char *arglist[256]);
#endif