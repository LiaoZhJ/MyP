
// MFCApplication35View.cpp : CMFCApplication35View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication35.h"
#endif

#include "MFCApplication35Doc.h"
#include "MFCApplication35View.h"
#include"DrawEllipse.h"
#include"Colour.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication35View

IMPLEMENT_DYNCREATE(CMFCApplication35View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication35View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32771, &CMFCApplication35View::On32771)
	
	ON_COMMAND(ID_32772, &CMFCApplication35View::On32772)
END_MESSAGE_MAP()

// CMFCApplication35View 构造/析构

CMFCApplication35View::CMFCApplication35View()
{
	// TODO: 在此处添加构造代码
	flag = false;
	tt = false;
	ff = false;
}

CMFCApplication35View::~CMFCApplication35View()
{
}

BOOL CMFCApplication35View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication35View 绘制

void CMFCApplication35View::OnDraw(CDC* pDC)
{
	CMFCApplication35Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (flag||tt)
	{
		pDC->Ellipse(rect);
	}
	tt = false;
}


// CMFCApplication35View 诊断

#ifdef _DEBUG
void CMFCApplication35View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication35View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication35Doc* CMFCApplication35View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication35Doc)));
	return (CMFCApplication35Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication35View 消息处理程序


void CMFCApplication35View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//if (point.x > rect.left&&point.x<rect.right&&point.y>rect.top&&point.y < rect.bottom)
	ff = true;

	CDC * dc = GetDC();
	CPen pen(PS_DASH, 1, RGB(200, 100, 100));//虚线
	CPen * pOldPen = dc->SelectObject(&pen);
	dc->Rectangle(&rect);
	dc->SelectObject(pOldPen);
	dc->Ellipse(&rect);

	rect.left = point.x;
	rect.top = point.y;
	flag = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication35View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (ff)
	{
		rect.right = point.x;
		rect.bottom = point.y;
		if (flag)
			Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication35View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = false;
	ff = false;
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication35View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	
	DrawEllipse dlg;
	int r=dlg.DoModal();
	if (r = IDC_BUTTON2)
	{
		rect.top = dlg.recttop;
		rect.bottom = dlg.rectbottom;
		rect.left = dlg.rectleft;
		rect.right = dlg.rectright;
		tt = true;
	}
	Invalidate();
}





void CMFCApplication35View::On32772()
{
	// TODO: 在此添加命令处理程序代码
	Colour dlg;
	int r=dlg.DoModal();
	if (r = IDOK)
	{
		CDC * dc = GetDC();
		CBrush brush(RGB(dlg.Red, dlg.Green, dlg.Blue));
		CBrush * pOldbrush = dc->SelectObject(&brush);
		dc->Ellipse(&rect);
		dc->SelectObject(pOldbrush);
	}
}
