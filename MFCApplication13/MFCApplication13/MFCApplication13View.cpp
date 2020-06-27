
// MFCApplication13View.cpp : CMFCApplication13View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication13.h"
#endif

#include "MFCApplication13Doc.h"
#include "MFCApplication13View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication13View

IMPLEMENT_DYNCREATE(CMFCApplication13View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication13View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFCApplication13View::OnFileOpen)
END_MESSAGE_MAP()

// CMFCApplication13View 构造/析构

CMFCApplication13View::CMFCApplication13View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication13View::~CMFCApplication13View()
{
}

BOOL CMFCApplication13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication13View 绘制

void CMFCApplication13View::OnDraw(CDC* pDC)
{
	CMFCApplication13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (pDoc->r == IDOK)
	{
		pDoc->img.Draw(pDC->m_hDC, 0, 0, pDoc->img.GetWidth(), pDoc->img.GetHeight());
	}
}


// CMFCApplication13View 诊断

#ifdef _DEBUG
void CMFCApplication13View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication13Doc* CMFCApplication13View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication13Doc)));
	return (CMFCApplication13Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication13View 消息处理程序


void CMFCApplication13View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplication13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CDC* pDC;
	pDC = GetDC();
	CFileDialog cfd(true);
	pDoc->r = cfd.DoModal();
	if (pDoc->r == IDOK)
	{
		pDoc->filename = cfd.GetPathName();
		pDoc->img.Load(pDoc->filename);
		pDoc->img.Draw(pDC->m_hDC, 0, 0, pDoc->img.GetWidth(), pDoc->img.GetHeight());
	}
}
