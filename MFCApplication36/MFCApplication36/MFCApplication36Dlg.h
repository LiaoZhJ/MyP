
// MFCApplication36Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFCApplication36Dlg �Ի���
class CMFCApplication36Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication36Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION36_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
