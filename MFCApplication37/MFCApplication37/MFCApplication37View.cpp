
// MFCApplication37View.cpp : CMFCApplication37View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication37.h"
#endif

#include "MFCApplication37Doc.h"
#include "MFCApplication37View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication37View

IMPLEMENT_DYNCREATE(CMFCApplication37View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication37View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication37View 构造/析构

CMFCApplication37View::CMFCApplication37View()
{
	// TODO: 在此处添加构造代码
	flag = false;
}

CMFCApplication37View::~CMFCApplication37View()
{
}

BOOL CMFCApplication37View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication37View 绘制

void CMFCApplication37View::OnDraw(CDC* pDC)
{
	CMFCApplication37Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < pDoc->ca.GetSize(); i++)
	{
		pDC->Ellipse(pDoc->ca.GetAt(i));
	}
	pDC->Ellipse(rect);
}


// CMFCApplication37View 诊断

#ifdef _DEBUG
void CMFCApplication37View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication37View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication37Doc* CMFCApplication37View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication37Doc)));
	return (CMFCApplication37Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication37View 消息处理程序


void CMFCApplication37View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	rect.top = point.y;
	rect.left = point.x;
	
	flag = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication37View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	rect.bottom = point.y;
	rect.right = point.x;
	if (flag)
		InvalidateRect(&rect);
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication37View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication37Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	rect.bottom = point.y;
	rect.right = point.x;
	flag = false;
	pDoc->ca.Add(rect);
	CView::OnLButtonUp(nFlags, point);
}
