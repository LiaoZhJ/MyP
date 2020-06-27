#pragma once


// ALTER_DLG 对话框

class ALTER_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(ALTER_DLG)

public:
	ALTER_DLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ALTER_DLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long i;
	CString p;
};
