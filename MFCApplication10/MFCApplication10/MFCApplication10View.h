
// MFCApplication10View.h : CMFCApplication10View 类的接口
//

#pragma once


class CMFCApplication10View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication10View();
	DECLARE_DYNCREATE(CMFCApplication10View)

// 特性
public:
	CMFCApplication10Doc* GetDocument() const;
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication10View.cpp 中的调试版本
inline CMFCApplication10Doc* CMFCApplication10View::GetDocument() const
   { return reinterpret_cast<CMFCApplication10Doc*>(m_pDocument); }
#endif

