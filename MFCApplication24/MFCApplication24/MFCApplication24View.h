
// MFCApplication24View.h : CMFCApplication24View ��Ľӿ�
//

#pragma once

class CMFCApplication24Set;

class CMFCApplication24View : public CRecordView
{
protected: // �������л�����
	CMFCApplication24View();
	DECLARE_DYNCREATE(CMFCApplication24View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION24_FORM };
#endif
	CMFCApplication24Set* m_pSet;

// ����
public:
	CMFCApplication24Doc* GetDocument() const;
	void draw_pic(CString filepath);

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
	virtual ~CMFCApplication24View();
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
//	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFCApplication24View.cpp �еĵ��԰汾
inline CMFCApplication24Doc* CMFCApplication24View::GetDocument() const
   { return reinterpret_cast<CMFCApplication24Doc*>(m_pDocument); }
#endif

