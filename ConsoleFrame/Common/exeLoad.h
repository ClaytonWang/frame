#pragma once
#include<windows.h>  
#include "atlstr.h"  
#include <string>
//#include "string"  
#pragma comment(lib, "Kernel32.lib")  

class exeLoad
{
public:
	exeLoad(std::string filename);
	~exeLoad();

	STARTUPINFO si; //һЩ�ر���������  
	PROCESS_INFORMATION pi; //�ر��������ý���  
	std::string filename;
};

