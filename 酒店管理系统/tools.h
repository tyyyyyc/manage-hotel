#ifndef TOOLS_H
#define TOOLS_H

enum RoomType
{
	Type1 = 1,
	Type2 = 2,
	Type3 = 3,
	Type4 = 4,
};

#define pf printf
#define sf scanf

void clear_stdin(void);
void clear_src(void);
void anykey_continue(void);
char get_cmd(char start,char end);

#endif//TOOLS_H
