
// MFCApplication7View.h : CMFCApplication7View ��Ľӿ�
//

#pragma once


class CMFCApplication7View : public CView
{
protected: // �������л�����
	CMFCApplication7View();
	DECLARE_DYNCREATE(CMFCApplication7View)

// ����
public:
	CMFCApplication7Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication7View.cpp �еĵ��԰汾
inline CMFCApplication7Doc* CMFCApplication7View::GetDocument() const
   { return reinterpret_cast<CMFCApplication7Doc*>(m_pDocument); }
#endif
