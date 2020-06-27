
// MFCApplication30View.h : CMFCApplication30View 类的接口
//

#pragma once


class CMFCApplication30View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication30View();
	DECLARE_DYNCREATE(CMFCApplication30View)

// 特性
public:
	CMFCApplication30Doc* GetDocument() const;

// 操作
public:
	CRect rect;
	bool set;
	bool flag;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication30View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCApplication30View.cpp 中的调试版本
inline CMFCApplication30Doc* CMFCApplication30View::GetDocument() const
   { return reinterpret_cast<CMFCApplication30Doc*>(m_pDocument); }
#endif

