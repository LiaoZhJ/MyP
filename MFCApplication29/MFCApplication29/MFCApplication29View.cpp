
// MFCApplication29View.cpp : CMFCApplication29View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication29.h"
#endif

#include "MFCApplication29Doc.h"
#include "MFCApplication29View.h"
#include"AD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication29View

IMPLEMENT_DYNCREATE(CMFCApplication29View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication29View, CView)
	ON_COMMAND(ID_32771, &CMFCApplication29View::On32771)
END_MESSAGE_MAP()

// CMFCApplication29View 构造/析构

CMFCApplication29View::CMFCApplication29View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication29View::~CMFCApplication29View()
{
}

BOOL CMFCApplication29View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication29View 绘制

void CMFCApplication29View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication29Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication29View 诊断

#ifdef _DEBUG
void CMFCApplication29View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication29View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication29Doc* CMFCApplication29View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication29Doc)));
	return (CMFCApplication29Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication29View 消息处理程序


void CMFCApplication29View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	AD dlg;
	dlg.DoModal();
}
