
// MFCApplication27.h : MFCApplication27 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication27App:
// �йش����ʵ�֣������ MFCApplication27.cpp
//

class CMFCApplication27App : public CWinApp
{
public:
	CMFCApplication27App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication27App theApp;
