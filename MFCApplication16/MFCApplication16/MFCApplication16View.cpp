
// MFCApplication16View.cpp : CMFCApplication16View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication16.h"
#endif

#include "MFCApplication16Doc.h"
#include "MFCApplication16View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication16View

IMPLEMENT_DYNCREATE(CMFCApplication16View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication16View, CView)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFCApplication16View 构造/析构

CMFCApplication16View::CMFCApplication16View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication16View::~CMFCApplication16View()
{
}

BOOL CMFCApplication16View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication16View 绘制

void CMFCApplication16View::OnDraw(CDC* pDC)
{
	CMFCApplication16Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int i=0;
	CString s = pDoc->str;
	CSize textsize;
	textsize = pDC->GetTextExtent((LPCTSTR)pDoc->str);
	if (textsize.cx < pDoc->rect.right) {
		pDC->Rectangle(pDoc->rect);
		pDC->TextOutW(pDoc->rect.left + 1, pDoc->wordline, pDoc->str);
	}
	else
	{
		pDC->Rectangle(pDoc->rect);
		while (1) {
			int index;
			CSize textsize2;
			textsize2 = pDC->GetTextExtent((LPCTSTR)s);
			if(textsize2.cx>textsize.cx)
				index = textsize.cx / 10;
			else 
				index = textsize2.cx / 10;
			pDC->TextOutW(pDoc->rect.left + 1, pDoc->wordline, s.Left(index));
			s = s.Mid(index);
			index -= (pDoc->rect.right - pDoc->rect.left) / 10;
			pDoc->wordline += 20;
			i++;
			if (index<=0) 
				break;
		}
	}
	pDoc->wordline -= i*20;
}


// CMFCApplication16View 诊断

#ifdef _DEBUG
void CMFCApplication16View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication16View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication16Doc* CMFCApplication16View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication16Doc)));
	return (CMFCApplication16Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication16View 消息处理程序


void CMFCApplication16View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication16Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CDC* pDC;
	pDC = GetDC();
	pDoc->str += char(nChar);
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}
