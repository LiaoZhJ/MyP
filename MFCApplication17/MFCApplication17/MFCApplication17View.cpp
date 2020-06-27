
// MFCApplication17View.cpp : CMFCApplication17View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication17.h"
#endif

#include "MFCApplication17Doc.h"
#include "MFCApplication17View.h"
#include"Myd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication17View

IMPLEMENT_DYNCREATE(CMFCApplication17View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication17View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication17View 构造/析构

CMFCApplication17View::CMFCApplication17View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication17View::~CMFCApplication17View()
{
}

BOOL CMFCApplication17View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication17View 绘制

void CMFCApplication17View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication17Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication17View 诊断

#ifdef _DEBUG
void CMFCApplication17View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication17View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication17Doc* CMFCApplication17View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication17Doc)));
	return (CMFCApplication17Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication17View 消息处理程序


void CMFCApplication17View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Myd dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {
		GetDC()->TextOutW(20,20,L"你已退出对话框");
	}
	CView::OnLButtonDown(nFlags, point);
}
