
// MFCApplication35.h : MFCApplication35 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication35App:
// �йش����ʵ�֣������ MFCApplication35.cpp
//

class CMFCApplication35App : public CWinApp
{
public:
	CMFCApplication35App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication35App theApp;
