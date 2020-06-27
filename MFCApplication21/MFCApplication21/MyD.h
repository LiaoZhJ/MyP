#pragma once


// MyD 对话框

class MyD : public CDialogEx
{
	DECLARE_DYNAMIC(MyD)

public:
	MyD(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyD();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	
	
	void foo(CImage &img,int &sx, int &sy,int &w,int &h);
};
