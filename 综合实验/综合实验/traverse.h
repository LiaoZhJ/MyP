#pragma once


// traverse 对话框

class traverse : public CDialogEx
{
	DECLARE_DYNAMIC(traverse)

public:
	traverse(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~traverse();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
