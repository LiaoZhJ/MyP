
// MFCApplication36.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCApplication36App: 
// �йش����ʵ�֣������ MFCApplication36.cpp
//

class CMFCApplication36App : public CWinApp
{
public:
	CMFCApplication36App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication36App theApp;