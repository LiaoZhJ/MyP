
// MFCApplication30View.h : CMFCApplication30View ��Ľӿ�
//

#pragma once


class CMFCApplication30View : public CView
{
protected: // �������л�����
	CMFCApplication30View();
	DECLARE_DYNCREATE(CMFCApplication30View)

// ����
public:
	CMFCApplication30Doc* GetDocument() const;

// ����
public:
	CRect rect;
	bool set;
	bool flag;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication30View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCApplication30View.cpp �еĵ��԰汾
inline CMFCApplication30Doc* CMFCApplication30View::GetDocument() const
   { return reinterpret_cast<CMFCApplication30Doc*>(m_pDocument); }
#endif

