
// MFCApplication26.h : MFCApplication26 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication26App:
// �йش����ʵ�֣������ MFCApplication26.cpp
//

class CMFCApplication26App : public CWinApp
{
public:
	CMFCApplication26App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication26App theApp;
