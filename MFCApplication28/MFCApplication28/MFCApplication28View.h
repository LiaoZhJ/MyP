
// MFCApplication28View.h : CMFCApplication28View ��Ľӿ�
//

#pragma once


class CMFCApplication28View : public CView
{
protected: // �������л�����
	CMFCApplication28View();
	DECLARE_DYNCREATE(CMFCApplication28View)

// ����
public:
	CMFCApplication28Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication28View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication28View.cpp �еĵ��԰汾
inline CMFCApplication28Doc* CMFCApplication28View::GetDocument() const
   { return reinterpret_cast<CMFCApplication28Doc*>(m_pDocument); }
#endif

