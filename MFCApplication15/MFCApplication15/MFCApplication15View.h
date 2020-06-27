
// MFCApplication15View.h : CMFCApplication15View 类的接口
//

#pragma once


class CMFCApplication15View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication15View();
	DECLARE_DYNCREATE(CMFCApplication15View)

// 特性
public:
	CMFCApplication15Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication15View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication15View.cpp 中的调试版本
inline CMFCApplication15Doc* CMFCApplication15View::GetDocument() const
   { return reinterpret_cast<CMFCApplication15Doc*>(m_pDocument); }
#endif

