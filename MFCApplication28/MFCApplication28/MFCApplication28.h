
// MFCApplication28.h : MFCApplication28 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication28App:
// �йش����ʵ�֣������ MFCApplication28.cpp
//

class CMFCApplication28App : public CWinApp
{
public:
	CMFCApplication28App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication28App theApp;
