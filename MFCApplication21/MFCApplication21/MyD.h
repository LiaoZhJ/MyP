#pragma once


// MyD �Ի���

class MyD : public CDialogEx
{
	DECLARE_DYNAMIC(MyD)

public:
	MyD(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyD();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	
	
	void foo(CImage &img,int &sx, int &sy,int &w,int &h);
};