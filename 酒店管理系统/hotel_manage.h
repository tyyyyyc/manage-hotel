#ifndef HOTEL_MANAGE_H
#define HOTEL_MANAGE_H

#include "hotel.h"

class HotelManage
{
	Hotel* hotel;

	void in(void);
	void out(void);
	void show(void);
	void query(void);

public:
	HotelManage(void);
	~HotelManage(void){}

	void run(void);
};

#endif//HOTEL_MANAGE_H
