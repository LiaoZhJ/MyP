
// MFCApplication15View.cpp : CMFCApplication15View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication15.h"
#endif

#include "MFCApplication15Doc.h"
#include "MFCApplication15View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication15View

IMPLEMENT_DYNCREATE(CMFCApplication15View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication15View, CView)
	ON_WM_CHAR()
//	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication15View 构造/析构

CMFCApplication15View::CMFCApplication15View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication15View::~CMFCApplication15View()
{
}

BOOL CMFCApplication15View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication15View 绘制

void CMFCApplication15View::OnDraw(CDC* pDC)
{
	CMFCApplication15Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->rect);
	pDC->TextOutW(pDoc->rect.left + 1, pDoc->rect.top + 1, pDoc->str);
	/*CSize textsize;
	textsize = pDC->GetTextExtent((LPCTSTR)pDoc->str);
	CString s;
	s.Format(L"%d", textsize.cx);
	pDC->TextOutW(200,200,s);*/
}


// CMFCApplication15View 诊断

#ifdef _DEBUG
void CMFCApplication15View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication15View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication15Doc* CMFCApplication15View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication15Doc)));
	return (CMFCApplication15Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication15View 消息处理程序


void CMFCApplication15View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication15Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->flag)
	{
		CString s1 = pDoc->str.Left(pDoc->index);
		CString s2 = pDoc->str.Mid(pDoc->index);
		pDoc->str = s1 + char(nChar) + s2;
	}
	else 
		pDoc->str += char(nChar);
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}




void CMFCApplication15View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication15Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc); 
	pDoc->flag = true;
	pDoc->index = (point.x - 20) / 10;
	CView::OnLButtonDown(nFlags, point);
}
