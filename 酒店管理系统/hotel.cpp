#include <fstream>
#include <stdlib.h>
#include "hotel.h"
#include "room.h"
#include "tools.h"

Hotel::Hotel(void)
{
	fstream fs("./config/hotel.conf",ios::in);
	if(fs.good())
	{
		return;
	}	
	else
	{
		fstream fs1("./config/hotel.conf",ios::out);
		cout << "请输入酒店的楼层数:";
		cin >> floor;
		//定义记录每层房间数量的数组
		room_cnt = new int[floor];
		rooms = new Room*[floor];

		for(int i=0;i<floor;i++)
		{
			cout << "请输入第" << i+1 << "层的房间数量:";
			cin >> room_cnt[i];

			rooms[i] = new Room[room_cnt[i]];
			for(int j=0;j<room_cnt[i];j++)
			{
				rooms[i][j].flag = 0;
				RoomType type = RoomType(i+1);
				rooms[i][j].set_id((i+1)*1000+j+1);
				rooms[i][j].set_type(type);
				if(type == Type1)
				{
					rooms[i][j].set_price(150.0);
					rooms[i][j].cnt = 2;
				}
				else if(type == Type2)
				{
					rooms[i][j].set_price(240.0);
					rooms[i][j].cnt = 2;
				}
				else if(type == Type3)
				{
					rooms[i][j].set_price(330.0);
					rooms[i][j].cnt = 3;
				}
				else if(type == Type4)
				{
					rooms[i][j].set_price(550.0);
					rooms[i][j].cnt = 4; 
				}
				char buf[4096] = {};
				sprintf(buf,"./config/%d.txt",rooms[i][j].get_id());
				fstream fs_room(buf,ios::out);
			
				fs_room << "type:" << rooms[i][j].get_type() << " ";
				fs_room << "flag:" << rooms[i][j].flag << " ";
				fs_room << "cnt:" << rooms[i][j].cnt << " ";
				fs_room << "price:" << rooms[i][j].get_price() << " ";
				fs_room << "id:" << rooms[i][j].get_id() << " ";
				fs_room.close();

				fs1 << rooms[i][j].get_type() << endl;
				fs1 << rooms[i][j].flag << endl;
				fs1 << rooms[i][j].cnt << endl;
				fs1 << rooms[i][j].get_price() << endl;
				fs1 << rooms[i][j].get_id() << endl;
			}
		}
	}
	fs.close();	
}

Hotel::~Hotel(void)
{

}


