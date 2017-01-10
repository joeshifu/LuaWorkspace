// hello_c_api.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"

#include<iostream>
using namespace std;
#include<lua.hpp>


void StackDump(lua_State* L);

int main()
{
	/*
	//1.
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);//��Lua�е����б�׼��

	//ִ���ļ��е�lua����
	luaL_dofile(L,"hello.lua");

	//ִ���ַ����е�lua����
	const char *str = "print(\"joe\")";
	luaL_dostring(L, str);

	lua_close(L);//�ͷ�״ָ̬�������õ���Դ
	system("pause");
	return 0;
	*/

	////////////////////////////////////////////////////////////////////////////////////////////

	//2.virtual_stack_operate ����ջ����
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	// ѹ��Ԫ��
	lua_pushnil(L);//nilֵ
	lua_pushboolean(L, 1);//����ֵ
	lua_pushnumber(L, 10.45);//������
	lua_pushinteger(L, 100);//����

	const char * str2 = "lstring";
	lua_pushlstring(L, str2, 4);//ָ�������ַ���
	lua_pushlstring(L, str2, strlen(str2));//ָ�������ַ���,���ܵ��ַ������ȿ���strlen�ó�

	const char* str3 = "string_string";
	lua_pushstring(L, str3);//�����β���ַ���

	//lua_pushcclosure(L,)
	//lua_pushfstring()
	//lua_pushlightuserdata()
	//lua_pushthread()
	//lua_pushvalue()
	//lua_pushvfstring();

	StackDump(L);

	//



	lua_close(L);//�ͷ�
	system("pause");
	return 0;
}

//��һ��ջ��Ԫ��
void StackDump(lua_State* L)
{
	int top = lua_gettop(L);//����ջ��Ԫ�صĸ���
	cout << "count:" << top << endl;

	//lua���±��Ǵ�1��ʼ��
	for (int i = 1; i <= top; i++) 
	{
		int t = lua_type(L, i);//��ȡ���ͣ������ֱ��ǣ�LUA_TNIL��LUA_TNUMBER��LUA_TBOOLEAN��LUA_TSTRING��LUA_TTABLE��LUA_TFUNCTION��LUA_TUSERDATA��LUA_TTHREAD��LUA_TLIGHTUSERDATA��
		switch (t) 
		{
		case LUA_TNUMBER:
			printf("%g ", lua_tonumber(L, i));
			break;
		case LUA_TBOOLEAN:
			printf("%s ", lua_toboolean(L, i) ? "true" : "false");
			break;
		case LUA_TSTRING:
			printf("%s ", lua_tostring(L, i));
			break;
		//case LUA_TNIL:
		//	break;
		//case LUA_TTABLE:
		//	break;
		//case LUA_TFUNCTION:
		//	break;
		//case LUA_TUSERDATA:
		//	break;
		//case LUA_TTHREAD:
		//	break;
		//case LUA_TLIGHTUSERDATA:
		//	break;
		default:
			printf("%s ", lua_typename(L, t));
			break;
		}
		printf("");
	}
	printf("\n");
}