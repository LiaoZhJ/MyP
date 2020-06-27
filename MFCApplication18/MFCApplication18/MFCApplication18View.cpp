
// MFCApplication18View.cpp : CMFCApplication18View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication18.h"
#endif

#include "MFCApplication18Doc.h"
#include "MFCApplication18View.h"
#include"Edit0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication18View

IMPLEMENT_DYNCREATE(CMFCApplication18View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication18View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication18View 构造/析构

CMFCApplication18View::CMFCApplication18View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication18View::~CMFCApplication18View()
{
}

BOOL CMFCApplication18View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication18View 绘制

void CMFCApplication18View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication18Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication18View 诊断

#ifdef _DEBUG
void CMFCApplication18View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication18View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication18Doc* CMFCApplication18View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication18Doc)));
	return (CMFCApplication18Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication18View 消息处理程序


void CMFCApplication18View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Edit0 dlg;
	dlg.DoModal();
	
	CView::OnLButtonDown(nFlags, point);
}
