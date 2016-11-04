// TestDll.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "TestDll.h"
#include "TestDlg.h"
#include <thread>
#include <memory>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ��  ����ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CTestDllApp

BEGIN_MESSAGE_MAP(CTestDllApp, CWinApp)
END_MESSAGE_MAP()


// CTestDllApp ����

CTestDllApp::CTestDllApp()
{
	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CTestDllApp ����

CTestDllApp theApp;


// CTestDllApp ��ʼ��

BOOL CTestDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return init();
}

bool CTestDllApp::init()
{
	//�Զ����ʼ������
	//����ע�뷽ʽ���̻߳�����this dllж���˳��̣߳�
	std::thread th(&threadFunc);
	th.detach();
	CloseHandle(::CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(threadFunc), NULL, NULL, NULL));
	return true;
}

//�̺߳���������������������
void threadFunc()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HINSTANCE hOldRes = AfxGetResourceHandle();
	AfxSetResourceHandle(theApp.m_hInstance);
	std::shared_ptr<CTestDlg> pDlg(new CTestDlg); 
	pDlg->DoModal();
	FreeLibraryAndExitThread(theApp.m_hInstance, 1);
	AfxSetResourceHandle(hOldRes);
	return;
}
