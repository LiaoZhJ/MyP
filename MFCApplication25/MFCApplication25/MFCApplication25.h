
// MFCApplication25.h : MFCApplication25 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication25App:
// �йش����ʵ�֣������ MFCApplication25.cpp
//

class CMFCApplication25App : public CWinApp
{
public:
	CMFCApplication25App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication25App theApp;