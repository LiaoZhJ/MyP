
// MFCApplication26View.cpp : CMFCApplication26View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication26.h"
#endif

#include "MFCApplication26Doc.h"
#include "MFCApplication26View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication26View

IMPLEMENT_DYNCREATE(CMFCApplication26View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication26View, CView)
//	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication26View 构造/析构

CMFCApplication26View::CMFCApplication26View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication26View::~CMFCApplication26View()
{
}

BOOL CMFCApplication26View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication26View 绘制

void CMFCApplication26View::OnDraw(CDC* pDC)
{
	CMFCApplication26Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->rect);
}


// CMFCApplication26View 诊断

#ifdef _DEBUG
void CMFCApplication26View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication26View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication26Doc* CMFCApplication26View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication26Doc)));
	return (CMFCApplication26Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication26View 消息处理程序


//void CMFCApplication26View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	
//	CView::OnChar(nChar, nRepCnt, nFlags);
//}


void CMFCApplication26View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication26Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	switch (nChar)
	{
	case VK_HOME:
		if (pDoc->rect.top > 50 && pDoc->rect.left > 50)
		{
			pDoc->rect.top -= 50;
			pDoc->rect.left -= 50;
		}
		break;
	case VK_END:
		if (pDoc->rect.bottom-pDoc->rect.top > 50 && pDoc->rect.right-pDoc->rect.left > 50)
		{
			pDoc->rect.top += 50;
			pDoc->rect.left += 50;
		}
		break;
	default:
		break;
	}(nChar);
	Invalidate(TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFCApplication26View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication26Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->rect = pDoc->orect;
	Invalidate(TRUE);
	CView::OnLButtonDown(nFlags, point);
}
