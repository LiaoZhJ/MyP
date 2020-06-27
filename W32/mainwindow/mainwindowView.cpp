
// mainwindowView.cpp : CmainwindowView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "mainwindow.h"
#endif

#include "mainwindowDoc.h"
#include "mainwindowView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "lib0.h"
#include"W32D.h"


// CmainwindowView

IMPLEMENT_DYNCREATE(CmainwindowView, CView)

BEGIN_MESSAGE_MAP(CmainwindowView, CView)
END_MESSAGE_MAP()

// CmainwindowView 构造/析构

CmainwindowView::CmainwindowView()
{
	// TODO: 在此处添加构造代码

}

CmainwindowView::~CmainwindowView()
{
}

BOOL CmainwindowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CmainwindowView 绘制

void CmainwindowView::OnDraw(CDC* pDC)
{
	CmainwindowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	s = pchar();
	pDC->TextOutW(20,20,s);

	CString ss;
	ss.Format(_T("%d,动态库返回值"), Getint());
	pDC->TextOutW(20, 70, ss);
}


// CmainwindowView 诊断

#ifdef _DEBUG
void CmainwindowView::AssertValid() const
{
	CView::AssertValid();
}

void CmainwindowView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmainwindowDoc* CmainwindowView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmainwindowDoc)));
	return (CmainwindowDoc*)m_pDocument;
}
#endif //_DEBUG


// CmainwindowView 消息处理程序
