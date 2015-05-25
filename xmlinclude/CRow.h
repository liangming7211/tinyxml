#pragma once
#include <list>
#include <string>
using namespace std;
#include "Cell.h"


class CCRow
{
private:
	list<CCell*> listCell;
	void Free();
public:
	CCRow(void);
	~CCRow(void);

	list<CCell*> &GetCellList()
	{
		return listCell;
	}
	BOOL isExistKey(std::string sName);
	CCell &operator [](int iCol);
    CCell &operator [](const char* colName);//ȡ�����е�ֵ��ͨ������
	
};
