#pragma once


// DrawEllipse 对话框

class DrawEllipse : public CDialogEx
{
	DECLARE_DYNAMIC(DrawEllipse)

public:
	DrawEllipse(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DrawEllipse();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double recttop;
	double rectleft;
	int rectbottom;
	double rectright;
	afx_msg void OnBnClickedButton2();
};
