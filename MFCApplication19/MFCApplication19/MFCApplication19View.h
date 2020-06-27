
// MFCApplication19View.h : CMFCApplication19View 类的接口
//

#pragma once


class CMFCApplication19View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication19View();
	DECLARE_DYNCREATE(CMFCApplication19View)

// 特性
public:
	CMFCApplication19Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication19View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void On32772();
	afx_msg void On32773();
};

#ifndef _DEBUG  // MFCApplication19View.cpp 中的调试版本
inline CMFCApplication19Doc* CMFCApplication19View::GetDocument() const
   { return reinterpret_cast<CMFCApplication19Doc*>(m_pDocument); }
#endif

