#pragma once


// ALTER_DLG �Ի���

class ALTER_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(ALTER_DLG)

public:
	ALTER_DLG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ALTER_DLG();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long i;
	CString p;
};
