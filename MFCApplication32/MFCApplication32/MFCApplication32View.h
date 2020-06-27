
// MFCApplication32View.h : CMFCApplication32View 类的接口
//

#pragma once


class CMFCApplication32View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication32View();
	DECLARE_DYNCREATE(CMFCApplication32View)

// 特性
public:
	CMFCApplication32Doc* GetDocument() const;

// 操作
public:
	CString path;
	bool flag;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication32View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFCApplication32View.cpp 中的调试版本
inline CMFCApplication32Doc* CMFCApplication32View::GetDocument() const
   { return reinterpret_cast<CMFCApplication32Doc*>(m_pDocument); }
#endif

