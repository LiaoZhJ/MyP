
// MFCApplication23.h : MFCApplication23 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication23App:
// �йش����ʵ�֣������ MFCApplication23.cpp
//

class CMFCApplication23App : public CWinApp
{
public:
	CMFCApplication23App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication23App theApp;
