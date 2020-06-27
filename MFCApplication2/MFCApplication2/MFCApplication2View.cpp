
// MFCApplication2View.cpp : CMFCApplication2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication2View 构造/析构

CMFCApplication2View::CMFCApplication2View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication2View::~CMFCApplication2View()
{
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication2View 绘制

void CMFCApplication2View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
}


// CMFCApplication2View 诊断

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View 消息处理程序


void CMFCApplication2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->flag) {
		pDoc->x2 = pDoc->x1;
		pDoc->y2 = pDoc->y1;
		pDoc->x1 = point.x;
		pDoc->y1 = point.y;
		pDoc->count++;
		pDoc->howmuch = (pDoc->x2 - pDoc->x1)+(pDoc->y2- pDoc->y1);
		if (pDoc->howmuch < 0)
			pDoc->howmuch = -pDoc->howmuch;
	}
		
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->flag = true;
	pDoc->x1 = point.x;
	pDoc->y1 = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CMFCApplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->flag = false;
	CDC* pDC = GetDC();
	CString s;
	s.Format(L"mousemove次数：%d，发生一次需%d像素", pDoc->count, pDoc->howmuch);
	pDC->TextOutW(20,20,s );
	CView::OnLButtonUp(nFlags, point);
}
