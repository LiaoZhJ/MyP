
// MFCApplication23View.h : CMFCApplication23View ��Ľӿ�
//

#pragma once

class CMFCApplication23Set;

class CMFCApplication23View : public CRecordView
{
protected: // �������л�����
	CMFCApplication23View();
	DECLARE_DYNCREATE(CMFCApplication23View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION23_FORM };
#endif
	CMFCApplication23Set* m_pSet;

// ����
public:
	CMFCApplication23Doc* GetDocument() const;
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
	virtual ~CMFCApplication23View();
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
	afx_msg void OnBnClickedButton1();

};

#ifndef _DEBUG  // MFCApplication23View.cpp �еĵ��԰汾
inline CMFCApplication23Doc* CMFCApplication23View::GetDocument() const
   { return reinterpret_cast<CMFCApplication23Doc*>(m_pDocument); }
#endif

