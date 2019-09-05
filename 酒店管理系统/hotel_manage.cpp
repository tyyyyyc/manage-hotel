#include <iostream>
#include <fstream>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "hotel_manage.h"
#include "tools.h"
#include "guest.h"

HotelManage::HotelManage(void)
{
	hotel = new Hotel;
}

char buf7[1024] = {}; 


void menu(void)
{
	cout << "************************" << endl;
	cout << "欢迎来到XX酒店" << endl;
	cout << "1、开房..." << endl;
	cout << "2、退房..." << endl;
	cout << "3、查询..." << endl;
	cout << "4、显示房间信息..." << endl;
	cout << "5、退出系统..." << endl;
	cout << "************************" << endl;
}

void type_menu(void)
{
	cout << "************************" << endl;
	cout << "请选择要开的房间类型" << endl;
	cout << "1、标间..." << endl;
	cout << "2、大床房..." << endl;
	cout << "3、家庭房..." << endl;
	cout << "4、总统套房..." << endl;
	cout << "5、返回..." << endl;
	cout << "************************" << endl;
}

void standard_room(void)
{
	char buf[1024] = {};
	char buf1[1024] = {};
	char buf2[1024] = {};
	char buf3[1024] = {};
	cout << "标间" << endl;
	DIR* tt = opendir("./config/");
	if(NULL == tt)
	{
		perror("opendir");
		return;
	}
	chdir("./config/");
	for(struct dirent* de = readdir(tt);NULL != de;
				de = readdir(tt))
	{	
		if(!strcmp(de->d_name,".") || !strcmp(de->d_name,"..")) continue;
		sprintf(buf,"%s",de->d_name);
		if(buf[0] == '1')
		{
			fstream fs(buf,ios::in|ios::out|ios::binary);
			if(fs.good())
			{
				fs.read(buf1,sizeof(buf1));
				sprintf(buf2,"%s",strstr(buf1,"flag:"));
				sprintf(buf3,"%s",strstr(buf1,"id:"));
				buf3[7] = '\0';
				if('0' == buf2[5])
				{
					buf1[12] = '1';
					cout << "开房成功,房间号是:" << buf3+3 << endl;
					sprintf(buf1+38,"%s",buf7);
					cout << buf1 << endl;
					fstream fs1(buf,ios::out|ios::binary);
					fs1 << buf1;
					fs.close();
					fs1.close();
					chdir("..");
					return;
				}
			}
		}
	}
	cout << "标间已满..." << endl;
	chdir("..");
	return;
}

void bigbed_room(void)
{
	char buf[1024] = {};
	char buf1[1024] = {};
	char buf2[1024] = {};
	char buf3[1024] = {};
	cout << "大床房" << endl;
	DIR* tt = opendir("./config/");
	if(NULL == tt)
	{
		perror("opendir");
		return;
	}
	chdir("./config/");
	for(struct dirent* de = readdir(tt);NULL != de;
				de = readdir(tt))
	{	
		if(!strcmp(de->d_name,".") || !strcmp(de->d_name,"..")) continue;
		sprintf(buf,"%s",de->d_name);
		if(buf[0] == '2')
		{
			fstream fs(buf,ios::in|ios::out|ios::binary);
			if(fs.good())
			{
				fs.read(buf1,sizeof(buf1));
				sprintf(buf2,"%s",strstr(buf1,"flag:"));
				sprintf(buf3,"%s",strstr(buf1,"id:"));
				buf3[7] = '\0';
				if('0' == buf2[5])
				{
					buf1[12] = '1';
					cout << "开房成功,房间号是:" << buf3+3 << endl;
					sprintf(buf1+38,"%s",buf7);
					fstream fs1(buf,ios::out|ios::binary);
					fs1 << buf1;
					fs.close();
					fs1.close();
					chdir("..");
					return;
				}
			}
		}
	}
	cout << "大床房已满..." << endl;
	chdir("..");
	return;
}

void family_room(void)
{
	char buf[1024] = {};
	char buf1[1024] = {};
	char buf2[1024] = {};
	char buf3[1024] = {};
	cout << "家庭房" << endl;
	DIR* tt = opendir("./config/");
	if(NULL == tt)
	{
		perror("opendir");
		return;
	}
	chdir("./config/");
	for(struct dirent* de = readdir(tt);NULL != de;
				de = readdir(tt))
	{	
		if(!strcmp(de->d_name,".") || !strcmp(de->d_name,"..")) continue;
		sprintf(buf,"%s",de->d_name);
		if(buf[0] == '3')
		{
			fstream fs(buf,ios::in|ios::out|ios::binary);
			if(fs.good())
			{
				fs.read(buf1,sizeof(buf1));
				sprintf(buf2,"%s",strstr(buf1,"flag:"));
				sprintf(buf3,"%s",strstr(buf1,"id:"));
				buf3[7] = '\0';
				if('0' == buf2[5])
				{
					buf1[12] = '1';
					cout << "开房成功,房间号是:" << buf3+3 << endl;
					sprintf(buf1+38,"%s",buf7);
					fstream fs1(buf,ios::out|ios::binary);
					fs1 << buf1;
					fs.close();
					fs1.close();
					chdir("..");
					return;
				}
			}
		}
	}
	cout << "家庭房已满..." << endl;
	chdir("..");
	return;
}

void vip_room(void)
{
	char buf[1024] = {};
	char buf1[1024] = {};
	char buf2[1024] = {};
	char buf3[1024] = {};
	cout << "总统套房" << endl;
	DIR* tt = opendir("./config/");
	if(NULL == tt)
	{
		perror("opendir");
		return;
	}
	chdir("./config/");
	for(struct dirent* de = readdir(tt);NULL != de;
				de = readdir(tt))
	{	
		if(!strcmp(de->d_name,".") || !strcmp(de->d_name,"..")) continue;
		sprintf(buf,"%s",de->d_name);
		if(buf[0] == '4')
		{
			fstream fs(buf,ios::in|ios::out|ios::binary);
			if(fs.good())
			{
				fs.read(buf1,sizeof(buf1));
				sprintf(buf2,"%s",strstr(buf1,"flag:"));
				sprintf(buf3,"%s",strstr(buf1,"id:"));
				buf3[7] = '\0';
				if('0' == buf2[5])
				{
					buf1[12] = '1';
					cout << "开房成功,房间号是:" << buf3+3 << endl;
					sprintf(buf1+38,"%s",buf7);
					fstream fs1(buf,ios::out|ios::binary);
					fs1 << buf1;
					fs.close();
					fs1.close();
					chdir("..");
					return;
				}
			}
		}
	}
	cout << "总统套房已满..." << endl;
	chdir("..");
	return;
}

void HotelManage::in(void)
{
	char name[20];
	char buf[1024] = {};
	int id;
	cout << "请输入要住房的人的姓名:";
	cin >> name;
	cout << "请输入其身份证号:";
	cin >> id;
	Guest guest(name,id);
	clear_src();	
	sprintf(buf,"name:%s id:%u",guest.get_name(),guest.get_id());
	cout << buf << endl;
	strcpy(buf7,buf);
	cout << buf7 << endl;
	while(1)
	{
		type_menu();
		switch(get_cmd('1','5'))
		{
			case '1': standard_room(); break;
			case '2': bigbed_room(); break;
			case '3': family_room(); break;
			case '4': vip_room(); break;
			case '5': return;
		}
 	}
}

void HotelManage::out(void)
{
	char name[20];
	cout << "请输入退房人姓名:";
	cin >> name;
	DIR* tt = opendir("./config/");
	if(NULL == tt)
	{
		perror("opendir");
		return;
	}
	chdir("./config/");
	for(struct dirent* de = readdir(tt);NULL != de;
				de = readdir(tt))
	{	
		if(!strcmp(de->d_name,".") || !strcmp(de->d_name,"..")) continue;
		fstream fs(de->d_name,ios::in|ios::binary);
		cout << de->d_name << endl;
		if(!fs.good())
		{
			cout << "读取失败..." << endl;
			return;
		}
		else
		{
			cout << "读取成功..." << endl;
		}

		char buf[1024] = {};
		char buf1[1024] = {};
		fs.read(buf,sizeof(buf)); 
		if(strstr(buf,"name:"))
		{
			sprintf(buf1,"%s",strstr(buf,"name:"));
			if(strstr(buf1,name))
			{
				buf[12] = '0';
				buf[38] = '\0';
				fstream fs1(de->d_name,ios::out|ios::binary);
				fs1 << buf;
				if(fs1.good())
				{
					cout << "退房成功" << endl;
				}
				else 
				{
					cout << "失败" << endl;
				}	
				fs.close();
				fs1.close();
				chdir("..");
				return;
			}
		}
	}
	cout << "查无此人..." << endl;
	chdir("..");
	return;
}
void HotelManage::show(void)
{
	DIR* tt = opendir("./config/");
	if(NULL == tt)
	{
		perror("opendir");
		return;
	}
	chdir("./config/");
	for(struct dirent* de = readdir(tt);NULL != de;
				de = readdir(tt))
	{	
		if(!strcmp(de->d_name,".") || !strcmp(de->d_name,"..") || !strcmp(de->d_name,"hotel.conf")) continue;
		fstream fs(de->d_name,ios::in|ios::binary);

		if(!fs.good())
		{
			cout << "读取失败..." << endl;
			return;
		}
		else
		{
			cout << "读取成功..." << endl;
		}

		char buf[1024] = {};
		char buf1[1024] = {};
		char buf2[1024] = {};
		fs.read(buf,sizeof(buf)); 
		if(!strstr(buf,"name:"))
		{
			sprintf(buf1,"%s",strstr(buf,"id:"));
			cout << "空余的房间号是:" << buf1+3 << endl;
		}
		else
		{
			sprintf(buf1,"%s",strstr(buf,"id:"));
			buf1[7] = '\0';
			sprintf(buf2,"%s",strstr(buf,"name:"));
			cout << "有人住的房间号:" << buf1+3 << endl;
			cout << "住房人信息 " << buf2 << endl;
		}	
	
	}
	chdir("..");
}
void HotelManage::query(void)
{
	char buf[1024] = {};
	char buf1[1024] = {};
	char buf2[1024] = {};
	char buf3[1024] = {};

	int id;
	cout << "请输入要查询的房间号信息:";
	cin >> id;
	sprintf(buf1,"%u",id);

	DIR* tt = opendir("./config/");
	if(NULL == tt)
	{
		perror("opendir");
		return;
	}
	chdir("./config/");
	for(struct dirent* de = readdir(tt);NULL != de;
				de = readdir(tt))
	{	
		if(!strcmp(de->d_name,".") || !strcmp(de->d_name,"..")) continue;
		sprintf(buf,"%s",de->d_name);
		if(strstr(buf,buf1))
		{
			fstream fs(de->d_name,ios::in|ios::binary);
			cout << de->d_name << endl;
			if(!fs.good())
			{
				cout << "读取失败..." << endl;
				return;
			}
			else
			{
				cout << "读取成功..." << endl;
			}
			fs.read(buf2,sizeof(buf2));
			
			if(strstr(buf2,"name:"))
			{
				sprintf(buf3,"%s",strstr(buf2,"name:"));
				cout << "此房有人住,住房人信息是 " << buf3 << endl;
				return;
			}	
			else
			{
				cout << "此房间目前是空房..." << endl;
				return;
			}
		}
		cout << "查无此房..." << endl;
	}
}

void HotelManage::run(void)
{
	while(1)
	{
		clear_src();
		menu();
		switch(get_cmd('1','5'))
		{
			case '1': HotelManage::in(); break;
			case '2': HotelManage::out(); break;
			case '3': HotelManage::query(); break;
			case '4': HotelManage::show(); break;
			case '5': return;
		}
 	}
}

