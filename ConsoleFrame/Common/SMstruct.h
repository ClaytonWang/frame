#pragma once
#include <windows.h>
#include <vector>
#pragma pack(4)

#define  FILE_MAP_NAME	 "xxooyy"
#define  MORE_OPEN_NUMBER 20
//�����ڴ�
typedef struct _SM_SHARE_DATA
{
	DWORD ndPid; //����pid
	char userName[MAX_PATH]; //�û���
	char passWord[MAX_PATH]; //�û�����

}SM_SHARE_DATA;

struct _SM_ALL_SHARE_DATA
{
	std::vector< SM_SHARE_DATA> m_sm_data;
	_SM_ALL_SHARE_DATA();
	~_SM_ALL_SHARE_DATA();
};



#pragma  pack()