
// MFCApplication27View.h : CMFCApplication27View ��Ľӿ�
//

#pragma once

class CMFCApplication27Set;

class CMFCApplication27View : public CRecordView
{
protected: // �������л�����
	CMFCApplication27View();
	DECLARE_DYNCREATE(CMFCApplication27View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION27_FORM };
#endif
	CMFCApplication27Set* m_pSet;

// ����
public:
	CMFCApplication27Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFCApplication27View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long id;
	CString path;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#ifndef _DEBUG  // MFCApplication27View.cpp �еĵ��԰汾
inline CMFCApplication27Doc* CMFCApplication27View::GetDocument() const
   { return reinterpret_cast<CMFCApplication27Doc*>(m_pDocument); }
#endif

