#pragma once


// DrawEllipse �Ի���

class DrawEllipse : public CDialogEx
{
	DECLARE_DYNAMIC(DrawEllipse)

public:
	DrawEllipse(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DrawEllipse();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double recttop;
	double rectleft;
	int rectbottom;
	double rectright;
	afx_msg void OnBnClickedButton2();
};
