#ifndef ROOM_H
#define ROOM_H

#include "guest.h"
#include "tools.h"

class Room
{
	RoomType type;
	float price;
	uint16_t id;
public:
	int cnt;  //数量
	int flag;	
	Guest* guests;

	Room(void);
	Room(RoomType type,float price,uint16_t id):type(type),price(price),id(id)
	{ 
		this->type = type;
		this->price = price;
		this->id = id;
	}

	uint16_t get_id(void);
	float get_price(void);
	RoomType get_type(void);

	void set_id(uint16_t id);
	void set_price(float price);
	void set_type(RoomType type);
};

#endif//ROOM_H
