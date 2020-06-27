
// MFCApplication11View.h : CMFCApplication11View 类的接口
//

#pragma once


class CMFCApplication11View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication11View();
	DECLARE_DYNCREATE(CMFCApplication11View)

// 特性
public:
	CMFCApplication11Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Ondrawline();
	afx_msg void Ondrawrect();
	afx_msg void Ondrawellipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication11View.cpp 中的调试版本
inline CMFCApplication11Doc* CMFCApplication11View::GetDocument() const
   { return reinterpret_cast<CMFCApplication11Doc*>(m_pDocument); }
#endif

