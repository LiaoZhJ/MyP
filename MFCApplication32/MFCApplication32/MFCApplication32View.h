
// MFCApplication32View.h : CMFCApplication32View ��Ľӿ�
//

#pragma once


class CMFCApplication32View : public CView
{
protected: // �������л�����
	CMFCApplication32View();
	DECLARE_DYNCREATE(CMFCApplication32View)

// ����
public:
	CMFCApplication32Doc* GetDocument() const;

// ����
public:
	CString path;
	bool flag;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication32View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFCApplication32View.cpp �еĵ��԰汾
inline CMFCApplication32Doc* CMFCApplication32View::GetDocument() const
   { return reinterpret_cast<CMFCApplication32Doc*>(m_pDocument); }
#endif

