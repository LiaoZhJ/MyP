
// MFCApplication6View.cpp : CMFCApplication6View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication6.h"
#endif

#include "MFCApplication6Doc.h"
#include "MFCApplication6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication6View

IMPLEMENT_DYNCREATE(CMFCApplication6View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication6View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication6View 构造/析构

CMFCApplication6View::CMFCApplication6View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication6View::~CMFCApplication6View()
{
}

BOOL CMFCApplication6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication6View 绘制

void CMFCApplication6View::OnDraw(CDC* pDC)
{
	CMFCApplication6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->CRA);
	pDC->Rectangle(pDoc->CRB);
	pDC->Rectangle(pDoc->CRC);
}


// CMFCApplication6View 诊断

#ifdef _DEBUG
void CMFCApplication6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication6Doc* CMFCApplication6View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication6Doc)));
	return (CMFCApplication6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication6View 消息处理程序


void CMFCApplication6View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CDC* pDC;
	pDC = GetDC();
	CString s1;
	CString s2;
	CString s3;

	if (point.y >= pDoc->CRA.top&point.y <= pDoc->CRA.bottom&point.x >= pDoc->CRA.left&point.x <= pDoc->CRA.right) {
		pDoc->r1 = rand();
		s1.Format(L"%d", pDoc->r1 );
		pDC->TextOutW((pDoc->CRA.left + pDoc->CRA.right) / 2 - 20, (pDoc->CRA.top + pDoc->CRA.bottom) / 2 - 20, s1);
	}
		
	else if (point.y >= pDoc->CRB.top&point.y <= pDoc->CRB.bottom&point.x >= pDoc->CRB.left&point.x <= pDoc->CRB.right) {
		pDoc->r2 = rand(); 
		s2.Format(L"%d", pDoc->r2);
		pDC->TextOutW((pDoc->CRB.left + pDoc->CRB.right) / 2 - 20, (pDoc->CRB.top + pDoc->CRB.bottom) / 2 - 20, s2);
	}
		
	else if (point.y >= pDoc->CRC.top&point.y <= pDoc->CRC.bottom&point.x >= pDoc->CRC.left&point.x <= pDoc->CRC.right) {
		s3.Format(L"%d", pDoc->r1 + pDoc->r2);
		pDC->TextOutW((pDoc->CRC.left + pDoc->CRC.right) / 2 - 20, (pDoc->CRC.top + pDoc->CRC.bottom) / 2 - 20, s3);
	}
		
	CView::OnLButtonDown(nFlags, point);
}
