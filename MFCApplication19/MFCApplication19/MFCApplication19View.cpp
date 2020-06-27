
// MFCApplication19View.cpp : CMFCApplication19View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication19.h"
#endif

#include "MFCApplication19Doc.h"
#include "MFCApplication19View.h"
#include"MyD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication19View

IMPLEMENT_DYNCREATE(CMFCApplication19View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication19View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_32772, &CMFCApplication19View::On32772)
	ON_COMMAND(ID_32773, &CMFCApplication19View::On32773)
END_MESSAGE_MAP()

// CMFCApplication19View 构造/析构

CMFCApplication19View::CMFCApplication19View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication19View::~CMFCApplication19View()
{
}

BOOL CMFCApplication19View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication19View 绘制

void CMFCApplication19View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication19Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication19View 诊断

#ifdef _DEBUG
void CMFCApplication19View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication19View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication19Doc* CMFCApplication19View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication19Doc)));
	return (CMFCApplication19Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication19View 消息处理程序


void CMFCApplication19View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication19Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CFileDialog dlgFile(TRUE);
	if (dlgFile.DoModal())
	{
		pDoc->filename=dlgFile.GetFileName();
		GetDC()->TextOutW(20,20, pDoc->filename);
	}
	
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFCApplication19View::On32772()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication19Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	MyD dialog;
	dialog.fname = pDoc->filename;
	dialog.DoModal();
	
}


void CMFCApplication19View::On32773()
{
	// TODO: 在此添加命令处理程序代码
}
