
// MFCApplication10View.cpp : CMFCApplication10View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication10.h"
#endif

#include "MFCApplication10Doc.h"
#include "MFCApplication10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication10View

IMPLEMENT_DYNCREATE(CMFCApplication10View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication10View, CView)
END_MESSAGE_MAP()

// CMFCApplication10View 构造/析构

CMFCApplication10View::CMFCApplication10View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

CMFCApplication10View::~CMFCApplication10View()
{
}

BOOL CMFCApplication10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication10View 绘制

void CMFCApplication10View::OnDraw(CDC* pDC)
{
	CMFCApplication10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0,0,	m_nWidth,m_nHeight,&MemDC,0,0,SRCCOPY);
}


// CMFCApplication10View 诊断

#ifdef _DEBUG
void CMFCApplication10View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication10Doc* CMFCApplication10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication10Doc)));
	return (CMFCApplication10Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication10View 消息处理程序
