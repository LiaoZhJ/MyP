
// MFCApplication36Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMFCApplication36Dlg 对话框
class CMFCApplication36Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication36Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION36_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox Lbox;
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CString Select;
	afx_msg void OnLbnSelchangeList2();
	afx_msg void Alter();
//	virtual BOOL DestroyWindow();

//	afx_msg void OnClose();
//	afx_msg void OnBnClickedOk();
};
