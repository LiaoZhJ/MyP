
// MFCApplication12View.cpp : CMFCApplication12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication12.h"
#endif

#include "MFCApplication12Doc.h"
#include "MFCApplication12View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication12View

IMPLEMENT_DYNCREATE(CMFCApplication12View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication12View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFCApplication12View::OnFileOpen)
END_MESSAGE_MAP()

// CMFCApplication12View 构造/析构

CMFCApplication12View::CMFCApplication12View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication12View::~CMFCApplication12View()
{
}

BOOL CMFCApplication12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication12View 绘制

void CMFCApplication12View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication12View 诊断

#ifdef _DEBUG
void CMFCApplication12View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication12Doc* CMFCApplication12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication12Doc)));
	return (CMFCApplication12Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication12View 消息处理程序


void CMFCApplication12View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		CImage img;
		img.Load(filename);
		img.Draw(dc.m_hDC,0,0,img.GetWidth(),img.GetHeight());
	}
}
