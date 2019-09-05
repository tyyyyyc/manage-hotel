#ifndef HOTEL_H
#define HOTEL_H

#include <stdint.h>
#include "room.h"

class Hotel
{
	int floor;
	int* room_cnt;  //每层的房间数量
	Room** rooms;      //
public:
	Hotel(void);
	~Hotel(void);
};

#endif//HOTEL_H
