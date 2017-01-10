// hello_c_api.cpp : 定义控制台应用程序的入口点。
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
	luaL_openlibs(L);//打开Lua中的所有标准库

	//执行文件中的lua代码
	luaL_dofile(L,"hello.lua");

	//执行字符串中的lua代码
	const char *str = "print(\"joe\")";
	luaL_dostring(L, str);

	lua_close(L);//释放状态指针所引用的资源
	system("pause");
	return 0;
	*/

	////////////////////////////////////////////////////////////////////////////////////////////

	//2.virtual_stack_operate 虚拟栈操作
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	// 压入元素
	lua_pushnil(L);//nil值
	lua_pushboolean(L, 1);//布尔值
	lua_pushnumber(L, 10.45);//浮点数
	lua_pushinteger(L, 100);//整型

	const char * str2 = "lstring";
	lua_pushlstring(L, str2, 4);//指定长度字符串
	lua_pushlstring(L, str2, strlen(str2));//指定长度字符串,其总的字符串长度可由strlen得出

	const char* str3 = "string_string";
	lua_pushstring(L, str3);//以零结尾的字符串

	//lua_pushcclosure(L,)
	//lua_pushfstring()
	//lua_pushlightuserdata()
	//lua_pushthread()
	//lua_pushvalue()
	//lua_pushvfstring();

	StackDump(L);

	//



	lua_close(L);//释放
	system("pause");
	return 0;
}

//看一下栈中元素
void StackDump(lua_State* L)
{
	int top = lua_gettop(L);//返回栈中元素的个数
	cout << "count:" << top << endl;

	//lua中下标是从1开始的
	for (int i = 1; i <= top; i++) 
	{
		int t = lua_type(L, i);//获取类型，常量分别是：LUA_TNIL、LUA_TNUMBER、LUA_TBOOLEAN、LUA_TSTRING、LUA_TTABLE、LUA_TFUNCTION、LUA_TUSERDATA、LUA_TTHREAD和LUA_TLIGHTUSERDATA。
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