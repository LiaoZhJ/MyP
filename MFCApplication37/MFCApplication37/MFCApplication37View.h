
// MFCApplication37View.h : CMFCApplication37View ��Ľӿ�
//

#pragma once


class CMFCApplication37View : public CView
{
protected: // �������л�����
	CMFCApplication37View();
	DECLARE_DYNCREATE(CMFCApplication37View)

// ����
public:
	CMFCApplication37Doc* GetDocument() const;
	bool flag;
	CRect rect;
	CPoint a;
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication37View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication37View.cpp �еĵ��԰汾
inline CMFCApplication37Doc* CMFCApplication37View::GetDocument() const
   { return reinterpret_cast<CMFCApplication37Doc*>(m_pDocument); }
#endif

