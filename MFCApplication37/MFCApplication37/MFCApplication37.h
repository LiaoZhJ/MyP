
// MFCApplication37.h : MFCApplication37 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication37App:
// �йش����ʵ�֣������ MFCApplication37.cpp
//

class CMFCApplication37App : public CWinAppEx
{
public:
	CMFCApplication37App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication37App theApp;
