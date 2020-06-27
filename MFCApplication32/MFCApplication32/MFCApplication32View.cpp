
// MFCApplication32View.cpp : CMFCApplication32View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication32.h"
#endif

#include "MFCApplication32Doc.h"
#include "MFCApplication32View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication32View

IMPLEMENT_DYNCREATE(CMFCApplication32View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication32View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFCApplication32View::OnFileOpen)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCApplication32View 构造/析构

CMFCApplication32View::CMFCApplication32View()
{
	// TODO: 在此处添加构造代码
	flag = false;

}

CMFCApplication32View::~CMFCApplication32View()
{
}

BOOL CMFCApplication32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication32View 绘制

void CMFCApplication32View::OnDraw(CDC* pDC)
{
	CMFCApplication32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	
}


// CMFCApplication32View 诊断

#ifdef _DEBUG
void CMFCApplication32View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication32Doc* CMFCApplication32View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication32Doc)));
	return (CMFCApplication32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication32View 消息处理程序

void CMFCApplication32View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	
	if (r = IDOK)
	{
		path=cfd.GetPathName();
		flag = true;
		Invalidate(true);
	}
	
}


void CMFCApplication32View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CView::OnPaint()
	if (flag) 
	{
		CDC* pDC;
		pDC = GetDC();
		CImage img;
		img.Load(path);
		int sx, sy, w, h;
		CRect rect;
		GetClientRect(&rect);

		float rect_ratio = 1.0*rect.Width() / rect.Height();
		float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

		if (rect_ratio > img_ratio)
		{
			h = rect.Height();
			w = img_ratio*h;
			sx = (rect.Width() - w) / 2;
			sy = 0;
		}
		else
		{
			w = rect.Width();
			h = w / img_ratio;
			sx = 0;
			sy = (rect.Height() - h) / 2;
		}
		pDC->SetStretchBltMode(HALFTONE);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
	}
	
