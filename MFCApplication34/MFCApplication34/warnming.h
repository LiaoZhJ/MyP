#pragma once


// warnming �Ի���

class warnming : public CDialogEx
{
	DECLARE_DYNAMIC(warnming)

public:
	warnming(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~warnming();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
