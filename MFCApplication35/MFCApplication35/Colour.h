#pragma once


// Colour 对话框

class Colour : public CDialogEx
{
	DECLARE_DYNAMIC(Colour)

public:
	Colour(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Colour();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int Green;
	int Red;
	int Blue;
};
