
// MFCApplication37View.h : CMFCApplication37View 类的接口
//

#pragma once


class CMFCApplication37View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication37View();
	DECLARE_DYNCREATE(CMFCApplication37View)

// 特性
public:
	CMFCApplication37Doc* GetDocument() const;
	bool flag;
	CRect rect;
	CPoint a;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication37View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication37View.cpp 中的调试版本
inline CMFCApplication37Doc* CMFCApplication37View::GetDocument() const
   { return reinterpret_cast<CMFCApplication37Doc*>(m_pDocument); }
#endif

