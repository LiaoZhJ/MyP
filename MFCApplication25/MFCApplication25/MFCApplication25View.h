
// MFCApplication25View.h : CMFCApplication25View ��Ľӿ�
//

#pragma once

class CMFCApplication25Set;

class CMFCApplication25View : public CRecordView
{
protected: // �������л�����
	CMFCApplication25View();
	DECLARE_DYNCREATE(CMFCApplication25View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION25_FORM };
#endif
	CMFCApplication25Set* m_pSet;

// ����
public:
	CMFCApplication25Doc* GetDocument() const;
	CString filepath;
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
	virtual ~CMFCApplication25View();
	void draw_pic(CString filepath);
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
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // MFCApplication25View.cpp �еĵ��԰汾
inline CMFCApplication25Doc* CMFCApplication25View::GetDocument() const
   { return reinterpret_cast<CMFCApplication25Doc*>(m_pDocument); }
#endif

