
// MFCApplication30View.cpp : CMFCApplication30View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication30.h"
#endif

#include "MFCApplication30Doc.h"
#include "MFCApplication30View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication30View

IMPLEMENT_DYNCREATE(CMFCApplication30View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication30View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication30View 构造/析构

CMFCApplication30View::CMFCApplication30View()
{
	// TODO: 在此处添加构造代码
	set = true;
	rect.top = 0;
	rect.left = 200;
	rect.bottom = 30;
	rect.right = 230;
	flag = true;
}

CMFCApplication30View::~CMFCApplication30View()
{
}

BOOL CMFCApplication30View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication30View 绘制

void CMFCApplication30View::OnDraw(CDC* pDC)
{
	CMFCApplication30Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (set)
	{
		SetTimer(1,500,NULL);
		set = false;
	}
	CRect cr;
	GetClientRect(&cr);
	if (rect.bottom +30>cr.bottom) 
	{
		flag = false;
	}
	if (rect.top -30<cr.top)
	{
		flag = true;
	}
	pDC->Ellipse(rect);
}


// CMFCApplication30View 诊断

#ifdef _DEBUG
void CMFCApplication30View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication30View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication30Doc* CMFCApplication30View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication30Doc)));
	return (CMFCApplication30Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication30View 消息处理程序


void CMFCApplication30View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag) 
	{
		rect.top += 20;
		rect.bottom += 20;
	}
	else
	{
		rect.top -= 20;
		rect.bottom -= 20;
	}
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}
