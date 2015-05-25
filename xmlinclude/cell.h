#pragma once
#include "assert.h"
#include <list>
#include <string>
#include <comutil.h>
using namespace std;

#pragma comment(lib, "comsuppw.lib") 

string ws2s(const wstring& ws);
wstring s2ws(const string& s);


class CCRow;
class CCTable;


class CCell
{
protected:
	string name;
	string data;

	CCTable *pSubTable;
public:
	CCell();
	~CCell();
	
	void SetTable(CCTable *pSub)
	{
		assert(pSub != NULL);
		pSubTable = pSub;
	}
	CCTable *GetTable()
	{
		
		return pSubTable;
	}
public:
    //取值
	operator wstring()
	{
		return s2ws(data);
	}
	operator string ()
	{
		return data;
	}
    
	operator int ()
	{
		return atoi(data.c_str());
	}

    operator float()
	{
       return atof(data.c_str());
	}
    void operator =(string sval)
	{
        data=sval;
	}

	void operator =(int ival) //重载=运算符，右边是符点数
	{
		char aa[100];
		sprintf_s(aa,"%d",ival);
		data = aa;
	}

	void operator =(float fval) //重载=运算符，右边是符点数
	{
		char aa[100];
		sprintf_s(aa,"%g",fval);
		data = aa;
	}
	friend class CCRow;
	friend class CCTable;
};
