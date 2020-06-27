#pragma once


// AD 对话框

class AD : public CDialogEx
{
	DECLARE_DYNAMIC(AD)

public:
	AD(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AD();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int x1;
	int x2;
	int sum;
	afx_msg void OnBnClickedButton1();
};
