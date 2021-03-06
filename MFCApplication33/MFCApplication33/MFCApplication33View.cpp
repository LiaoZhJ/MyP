
// MFCApplication33View.cpp : CMFCApplication33View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication33.h"
#endif

#include "MFCApplication33Doc.h"
#include "MFCApplication33View.h"
#include"MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication33View

IMPLEMENT_DYNCREATE(CMFCApplication33View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication33View, CView)
END_MESSAGE_MAP()

// CMFCApplication33View 构造/析构

CMFCApplication33View::CMFCApplication33View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication33View::~CMFCApplication33View()
{
}

BOOL CMFCApplication33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication33View 绘制

void CMFCApplication33View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication33Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	MyDlg dlg;
	dlg.DoModal();
}


// CMFCApplication33View 诊断

#ifdef _DEBUG
void CMFCApplication33View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication33View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication33Doc* CMFCApplication33View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication33Doc)));
	return (CMFCApplication33Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication33View 消息处理程序
