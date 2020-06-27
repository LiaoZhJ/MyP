
// MainmfcView.cpp : CMainmfcView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Mainmfc.h"
#endif

#include "MainmfcDoc.h"
#include "MainmfcView.h"
#include"f1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainmfcView

IMPLEMENT_DYNCREATE(CMainmfcView, CView)

BEGIN_MESSAGE_MAP(CMainmfcView, CView)
END_MESSAGE_MAP()

// CMainmfcView 构造/析构

CMainmfcView::CMainmfcView()
{
	// TODO: 在此处添加构造代码

}

CMainmfcView::~CMainmfcView()
{
}

BOOL CMainmfcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMainmfcView 绘制

void CMainmfcView::OnDraw(CDC* pDC)
{
	CMainmfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString str;
	str.Format(_T("5的阶乘为%d"), factorial(5));
	pDC->TextOutW(20, 20, str);
	FAC f;
	str.Format(_T("30°的弧度值为%f"), f.convert(30.0));
	pDC->TextOutW(20, 50, str);
}


// CMainmfcView 诊断

#ifdef _DEBUG
void CMainmfcView::AssertValid() const
{
	CView::AssertValid();
}

void CMainmfcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMainmfcDoc* CMainmfcView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMainmfcDoc)));
	return (CMainmfcDoc*)m_pDocument;
}
#endif //_DEBUG


// CMainmfcView 消息处理程序
