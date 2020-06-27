
// MFCApplication26View.h : CMFCApplication26View 类的接口
//

#pragma once


class CMFCApplication26View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication26View();
	DECLARE_DYNCREATE(CMFCApplication26View)

// 特性
public:
	CMFCApplication26Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication26View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication26View.cpp 中的调试版本
inline CMFCApplication26Doc* CMFCApplication26View::GetDocument() const
   { return reinterpret_cast<CMFCApplication26Doc*>(m_pDocument); }
#endif

