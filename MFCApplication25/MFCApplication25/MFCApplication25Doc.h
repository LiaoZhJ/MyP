
// MFCApplication25Doc.h : CMFCApplication25Doc 类的接口
//


#pragma once
#include "MFCApplication25Set.h"


class CMFCApplication25Doc : public CDocument
{
protected: // 仅从序列化创建
	CMFCApplication25Doc();
	DECLARE_DYNCREATE(CMFCApplication25Doc)

// 特性
public:
	CMFCApplication25Set m_MFCApplication25Set;

// 操作
public:
	
// 重写
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFCApplication25Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
