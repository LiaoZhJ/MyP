
// MFCApplication30.h : MFCApplication30 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication30App:
// �йش����ʵ�֣������ MFCApplication30.cpp
//

class CMFCApplication30App : public CWinAppEx
{
public:
	CMFCApplication30App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication30App theApp;
