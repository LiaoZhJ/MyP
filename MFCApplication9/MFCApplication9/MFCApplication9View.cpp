
// MFCApplication9View.cpp : CMFCApplication9View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication9.h"
#endif

#include "MFCApplication9Doc.h"
#include "MFCApplication9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication9View

IMPLEMENT_DYNCREATE(CMFCApplication9View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication9View, CView)
	ON_COMMAND(ID_NAME, &CMFCApplication9View::OnName)
END_MESSAGE_MAP()

// CMFCApplication9View 构造/析构

CMFCApplication9View::CMFCApplication9View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication9View::~CMFCApplication9View()
{
}

BOOL CMFCApplication9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication9View 绘制

void CMFCApplication9View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication9View 诊断

#ifdef _DEBUG
void CMFCApplication9View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication9Doc* CMFCApplication9View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication9Doc)));
	return (CMFCApplication9Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication9View 消息处理程序


void CMFCApplication9View::OnName()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC;
	pDC = GetDC();
	pDC->TextOutW(20,20,_T("廖治杰"));
}
