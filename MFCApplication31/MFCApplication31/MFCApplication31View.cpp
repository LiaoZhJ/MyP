
// MFCApplication31View.cpp : CMFCApplication31View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication31.h"
#endif

#include "MFCApplication31Doc.h"
#include "MFCApplication31View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication31View

IMPLEMENT_DYNCREATE(CMFCApplication31View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication31View, CView)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFCApplication31View 构造/析构

CMFCApplication31View::CMFCApplication31View()
{
	// TODO: 在此处添加构造代码
	set = false;
	rect.top = 200;
	rect.bottom = 230;
	rect.left = 0;
	rect.right = 30;
	flag = true;
}

CMFCApplication31View::~CMFCApplication31View()
{
}

BOOL CMFCApplication31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication31View 绘制

void CMFCApplication31View::OnDraw(CDC* pDC)
{
	CMFCApplication31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (set)
	{
		SetTimer(1, 500, NULL);
	}
	CRect re;
	GetClientRect(&re);
	if (rect.right + 30 > re.right)
	{
		flag = false;
	}
	if (rect.left - 30 < re.left)
	{
		flag = true;
	}
	pDC->Ellipse(rect);
}


// CMFCApplication31View 诊断

#ifdef _DEBUG
void CMFCApplication31View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication31Doc* CMFCApplication31View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication31Doc)));
	return (CMFCApplication31Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication31View 消息处理程序


void CMFCApplication31View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag)
	{
		rect.left += 30;
		rect.right += 30;
	}
	else
	{
		rect.left -= 30;
		rect.right -= 30;
	}
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}


void CMFCApplication31View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = true;
	Invalidate(true);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication31View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	KillTimer(1);
	CView::OnLButtonDblClk(nFlags, point);
}
