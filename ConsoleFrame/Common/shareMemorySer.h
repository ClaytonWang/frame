#pragma once
#include "SMstruct.h"
#include <memory>
#include <vector>
/*
�����ڴ����ˣ����ڿ���̨��
*/
class shareMemorySer
{
public:
	shareMemorySer(int num);
	~shareMemorySer();

	bool createShareMemory();
	void destoryShareMemory();

private:
	_SM_ALL_SHARE_DATA *m_pSMAllData;
};

