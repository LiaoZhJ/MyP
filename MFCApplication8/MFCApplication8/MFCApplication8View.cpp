
// MFCApplication8View.cpp : CMFCApplication8View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication8.h"
#endif

#include "MFCApplication8Doc.h"
#include "MFCApplication8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication8View

IMPLEMENT_DYNCREATE(CMFCApplication8View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication8View, CView)
	ON_COMMAND(ID_drawcircle, &CMFCApplication8View::Ondrawcircle)
END_MESSAGE_MAP()

// CMFCApplication8View 构造/析构

CMFCApplication8View::CMFCApplication8View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication8View::~CMFCApplication8View()
{
}

BOOL CMFCApplication8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication8View 绘制

void CMFCApplication8View::OnDraw(CDC* pDC)
{
	CMFCApplication8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect Clientrect;
	// TODO: 在此处为本机数据添加绘制代码
	if (pDoc->flag) {
		GetClientRect(&Clientrect);
		pDoc->C.bottom = (Clientrect.bottom + Clientrect.top) / 2 + 50;
		pDoc->C.top = (Clientrect.bottom + Clientrect.top) / 2 - 50;
		pDoc->C.right = (Clientrect.right+ Clientrect.left) / 2 + 50;
		pDoc->C.left = (Clientrect.right + Clientrect.left) / 2 - 50;
		pDoc->flag = false;
	}
	else if ((pDoc->C.left > 20) &(pDoc->C.top > 20)) {
		pDoc->C.bottom = pDoc->C.bottom + 20;
		pDoc->C.top = pDoc->C.top - 20;
		pDoc->C.right = pDoc->C.right + 20;
		pDoc->C.left = pDoc->C.left - 20;
		CBrush brush, *oldbrush;
		pDoc->R=pDoc->R + 30;
		brush.CreateSolidBrush(RGB(pDoc->R, pDoc->R, pDoc->R));
		oldbrush = pDC->SelectObject(&brush);
		pDC->Ellipse(pDoc->C.left, pDoc->C.top, pDoc->C.right, pDoc->C.bottom);
		pDC->SelectObject(oldbrush);
	}
	else
		pDC->Ellipse(pDoc->C.left, pDoc->C.top, pDoc->C.right, pDoc->C.bottom);
}


// CMFCApplication8View 诊断

#ifdef _DEBUG
void CMFCApplication8View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication8Doc* CMFCApplication8View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication8Doc)));
	return (CMFCApplication8Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication8View 消息处理程序


void CMFCApplication8View::Ondrawcircle()
{
	// TODO: 在此添加命令处理程序代码
	Invalidate();
}
