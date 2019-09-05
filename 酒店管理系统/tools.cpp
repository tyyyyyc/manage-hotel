#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include "tools.h"

void clear_stdin(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
}

void clear_src(void)
{
	system("clear");
}

// 任意键继续
void anykey_continue(void)
{
    pf("按任意键继续...");
    getch();
    pf("\n");
}

char get_cmd(char start,char end){
	clear_stdin();
	pf("请输入指令：");
	while(true){
		char val = getch();	
		if(val >= start && val <= end){
			pf("%c\n",val);
			return val;
		}
	}
}
