
// MFCApplication26View.h : CMFCApplication26View ��Ľӿ�
//

#pragma once


class CMFCApplication26View : public CView
{
protected: // �������л�����
	CMFCApplication26View();
	DECLARE_DYNCREATE(CMFCApplication26View)

// ����
public:
	CMFCApplication26Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication26View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication26View.cpp �еĵ��԰汾
inline CMFCApplication26Doc* CMFCApplication26View::GetDocument() const
   { return reinterpret_cast<CMFCApplication26Doc*>(m_pDocument); }
#endif

