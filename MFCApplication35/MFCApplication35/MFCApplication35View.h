
// MFCApplication35View.h : CMFCApplication35View 类的接口
//

#pragma once


class CMFCApplication35View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication35View();
	DECLARE_DYNCREATE(CMFCApplication35View)

// 特性
public:
	CMFCApplication35Doc* GetDocument() const;

// 操作
public:
	CRect rect;
	bool flag;
	bool tt;
	bool ff;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication35View();
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
	afx_msg void On32771();
	afx_msg void OnBnClickedButton2();
	afx_msg void On32772();
};

#ifndef _DEBUG  // MFCApplication35View.cpp 中的调试版本
inline CMFCApplication35Doc* CMFCApplication35View::GetDocument() const
   { return reinterpret_cast<CMFCApplication35Doc*>(m_pDocument); }
#endif

