
// MFCApplication29.h : MFCApplication29 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication29App:
// �йش����ʵ�֣������ MFCApplication29.cpp
//

class CMFCApplication29App : public CWinApp
{
public:
	CMFCApplication29App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication29App theApp;
