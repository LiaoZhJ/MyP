#pragma once


// AD �Ի���

class AD : public CDialogEx
{
	DECLARE_DYNAMIC(AD)

public:
	AD(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AD();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int x1;
	int x2;
	int sum;
	afx_msg void OnBnClickedButton1();
};
