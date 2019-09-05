#include "guest.h"


Guest::Guest(void)
{
	
}

char* Guest::get_name(void)
{
	return this->name;
}
uint32_t Guest::get_id(void)
{
	return this->id;
}
