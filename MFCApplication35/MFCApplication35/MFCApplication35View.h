
// MFCApplication35View.h : CMFCApplication35View ��Ľӿ�
//

#pragma once


class CMFCApplication35View : public CView
{
protected: // �������л�����
	CMFCApplication35View();
	DECLARE_DYNCREATE(CMFCApplication35View)

// ����
public:
	CMFCApplication35Doc* GetDocument() const;

// ����
public:
	CRect rect;
	bool flag;
	bool tt;
	bool ff;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication35View();
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
	afx_msg void On32771();
	afx_msg void OnBnClickedButton2();
	afx_msg void On32772();
};

#ifndef _DEBUG  // MFCApplication35View.cpp �еĵ��԰汾
inline CMFCApplication35Doc* CMFCApplication35View::GetDocument() const
   { return reinterpret_cast<CMFCApplication35Doc*>(m_pDocument); }
#endif

