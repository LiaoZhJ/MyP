
// MFCApplication22View.h : CMFCApplication22View ��Ľӿ�
//

#pragma once

class CMFCApplication22Set;

class CMFCApplication22View : public CRecordView
{
protected: // �������л�����
	CMFCApplication22View();
	DECLARE_DYNCREATE(CMFCApplication22View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION22_FORM };
#endif
	CMFCApplication22Set* m_pSet;

// ����
public:
	CMFCApplication22Doc* GetDocument() const;

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
	virtual ~CMFCApplication22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	long age;
	long number;
	long phonenum;
};

#ifndef _DEBUG  // MFCApplication22View.cpp �еĵ��԰汾
inline CMFCApplication22Doc* CMFCApplication22View::GetDocument() const
   { return reinterpret_cast<CMFCApplication22Doc*>(m_pDocument); }
#endif

