
// MFCApplication29View.h : CMFCApplication29View ��Ľӿ�
//

#pragma once


class CMFCApplication29View : public CView
{
protected: // �������л�����
	CMFCApplication29View();
	DECLARE_DYNCREATE(CMFCApplication29View)

// ����
public:
	CMFCApplication29Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication29View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
};

#ifndef _DEBUG  // MFCApplication29View.cpp �еĵ��԰汾
inline CMFCApplication29Doc* CMFCApplication29View::GetDocument() const
   { return reinterpret_cast<CMFCApplication29Doc*>(m_pDocument); }
#endif

