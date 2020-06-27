
// MFCApplication33View.h : CMFCApplication33View 类的接口
//

#pragma once


class CMFCApplication33View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication33View();
	DECLARE_DYNCREATE(CMFCApplication33View)

// 特性
public:
	CMFCApplication33Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication33View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication33View.cpp 中的调试版本
inline CMFCApplication33Doc* CMFCApplication33View::GetDocument() const
   { return reinterpret_cast<CMFCApplication33Doc*>(m_pDocument); }
#endif

