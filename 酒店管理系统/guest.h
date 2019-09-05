#ifndef GUEST_H
#define GUEST_H

#include <iostream>
#include <stdint.h>
using namespace std;

class Guest
{
	char* name;
	uint32_t id;
public:
	Guest(void);
	Guest(char* name,uint32_t id):name(name),id(id) 
	{
		this->name = name;
		this->id = id;
//		cout << name << " " << id << endl;
	}
	char* get_name(void);
	uint32_t get_id(void);
};

#endif//GUEST_H
