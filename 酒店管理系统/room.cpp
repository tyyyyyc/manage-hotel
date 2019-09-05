#include <iostream>
#include "room.h"

void Room::set_id(uint16_t id)
{
	this->id = id;
}
void Room::set_price(float price)
{
	this->price = price;
}
void Room::set_type(RoomType type)
{
	this->type = type;
}

uint16_t Room::get_id(void)
{
	return this->id;
}

float Room::get_price(void)
{
	return this->price;
}

RoomType Room::get_type(void)
{
	return this->type;
}

Room::Room(void)
{
	guests = new Guest;
}
