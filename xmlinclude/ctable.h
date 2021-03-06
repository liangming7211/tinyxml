#pragma once
#include <list>
#include <string>
#include "CRow.h"
#include "Cell.h"
#include "TinyXML.h"

using namespace std;

bool MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize);
bool WCharToMByte(LPCWSTR lpcwszStr , LPSTR lpszStr , DWORD dwSize);	


class CCTable
{
private://变量
	string sTablename;
	list<CCRow*> m_listData;//总链表	

public:	
	typedef list<CCRow*>::iterator iterator;

	CCTable(void);
	~CCTable(void); 
//XML操作
	void Free(void);
	virtual bool open(const char *sName);
	virtual bool open(const wchar_t* sFileName);
	        bool save(wchar_t* sFileName);
	virtual bool write(const wchar_t* sFileName);
            bool havexml(const wchar_t* sFileName); 
	
			bool LoadFromString(const char *sBuffer,int iLength);

	int AllRowNum(void);//返回所有行的数量

	bool FetchData(TiXmlElement *);
	CCRow *GetRow(int row);//返回指定的行
	iterator begin()
	{
		return m_listData.begin();
	}
	iterator end()
	{
		return m_listData.end();
	}
};
    //字符转换函数

