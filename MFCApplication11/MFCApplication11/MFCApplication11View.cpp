
// MFCApplication11View.cpp : CMFCApplication11View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication11.h"
#endif

#include "MFCApplication11Doc.h"
#include "MFCApplication11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication11View

IMPLEMENT_DYNCREATE(CMFCApplication11View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication11View, CView)
	ON_COMMAND(ID_drawLine, &CMFCApplication11View::Ondrawline)
	ON_COMMAND(ID_drawRect, &CMFCApplication11View::Ondrawrect)
	ON_COMMAND(ID_drawEllipse, &CMFCApplication11View::Ondrawellipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication11View 构造/析构

CMFCApplication11View::CMFCApplication11View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication11View::~CMFCApplication11View()
{
}

BOOL CMFCApplication11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication11View 绘制

void CMFCApplication11View::OnDraw(CDC* pDC)
{
	CMFCApplication11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	switch (pDoc->flag)
	{
	case 0:
		break;
	case 1:
		pDC->MoveTo(pDoc->rect.left, pDoc->rect.top);
		pDC->LineTo(pDoc->rect.right, pDoc->rect.bottom);
		break;
	case 2:
		pDC->Rectangle(pDoc->rect);
		break;
	case 3:
		pDC->Ellipse(pDoc->rect);
		break;
	default:
		break;
	}
}


// CMFCApplication11View 诊断

#ifdef _DEBUG
void CMFCApplication11View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication11Doc* CMFCApplication11View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication11Doc)));
	return (CMFCApplication11Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication11View 消息处理程序


void CMFCApplication11View::Ondrawline()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->flag = 1;

}


void CMFCApplication11View::Ondrawrect()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->flag = 2;
}


void CMFCApplication11View::Ondrawellipse()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->flag = 3;
}


void CMFCApplication11View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->rect.left = point.x;
	pDoc->rect.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication11View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc ->rect.right= point.x;
	pDoc->rect.bottom = point.y;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
