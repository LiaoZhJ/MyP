
// MFCApplication24.h : MFCApplication24 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication24App:
// �йش����ʵ�֣������ MFCApplication24.cpp
//

class CMFCApplication24App : public CWinApp
{
public:
	CMFCApplication24App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication24App theApp;
