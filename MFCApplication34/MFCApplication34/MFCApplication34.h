
// MFCApplication34.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCApplication34App: 
// �йش����ʵ�֣������ MFCApplication34.cpp
//

class CMFCApplication34App : public CWinApp
{
public:
	CMFCApplication34App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication34App theApp;