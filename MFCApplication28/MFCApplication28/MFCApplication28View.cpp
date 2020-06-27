
// MFCApplication28View.cpp : CMFCApplication28View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication28.h"
#endif

#include "MFCApplication28Doc.h"
#include "MFCApplication28View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication28View

IMPLEMENT_DYNCREATE(CMFCApplication28View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication28View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication28View 构造/析构

CMFCApplication28View::CMFCApplication28View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication28View::~CMFCApplication28View()
{
}

BOOL CMFCApplication28View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication28View 绘制

void CMFCApplication28View::OnDraw(CDC* pDC)
{
	CMFCApplication28Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->rect);
}


// CMFCApplication28View 诊断

#ifdef _DEBUG
void CMFCApplication28View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication28View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication28Doc* CMFCApplication28View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication28Doc)));
	return (CMFCApplication28Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication28View 消息处理程序


void CMFCApplication28View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication28Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->x1 = point.x;
	pDoc->y1 = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication28View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication28Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->x2 = point.x;
	pDoc->y2 = point.y;
	pDoc->rect.top += pDoc->y2 - pDoc->y1;
	pDoc->rect.left += pDoc->x2 - pDoc->x1;
	pDoc->rect.bottom+= pDoc->y2 - pDoc->y1;
	pDoc->rect.right += pDoc->x2 - pDoc->x1;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
