
// MFCApplication32.h : MFCApplication32 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication32App:
// �йش����ʵ�֣������ MFCApplication32.cpp
//

class CMFCApplication32App : public CWinAppEx
{
public:
	CMFCApplication32App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication32App theApp;
