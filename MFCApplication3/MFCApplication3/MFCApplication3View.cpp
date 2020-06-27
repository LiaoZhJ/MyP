
// MFCApplication3View.cpp : CMFCApplication3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication3.h"
#endif

#include "MFCApplication3Doc.h"
#include "MFCApplication3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3View

IMPLEMENT_DYNCREATE(CMFCApplication3View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication3View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication3View 构造/析构

CMFCApplication3View::CMFCApplication3View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication3View::~CMFCApplication3View()
{
}

BOOL CMFCApplication3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication3View 绘制

void CMFCApplication3View::OnDraw(CDC* pDC)
{
	CMFCApplication3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_tagRec);
}


// CMFCApplication3View 诊断

#ifdef _DEBUG
void CMFCApplication3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication3Doc* CMFCApplication3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication3Doc)));
	return (CMFCApplication3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication3View 消息处理程序


void CMFCApplication3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect clientRect;
	GetClientRect(&clientRect);
	CMFCApplication3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->m_tagRec.left > 0) {
			pDoc->m_tagRec.left -= 5;
			pDoc->m_tagRec.right -= 5;
			pDoc->origin.left = pDoc->m_tagRec.left;
			pDoc->origin.right = pDoc->m_tagRec.right;
		}
		break;
	case VK_RIGHT:
		if (pDoc->m_tagRec.right < clientRect.right) {
			pDoc->m_tagRec.left += 5;
			pDoc->m_tagRec.right += 5;
			pDoc->origin.left = pDoc->m_tagRec.left;
			pDoc->origin.right = pDoc->m_tagRec.right;
		}
		break;
	case VK_DOWN:
		if (pDoc->m_tagRec.bottom < clientRect.bottom) {
			pDoc->m_tagRec.top += 5;
			pDoc->m_tagRec.bottom += 5;
			pDoc->origin.top = pDoc->m_tagRec.top;
			pDoc->origin.bottom = pDoc->m_tagRec.bottom;
		}
		break;
	case VK_UP:
		if (pDoc->m_tagRec.top > 0) {
			pDoc->m_tagRec.top -= 5;
			pDoc->m_tagRec.bottom -= 5;
			pDoc->origin.top = pDoc->m_tagRec.top;
			pDoc->origin.bottom = pDoc->m_tagRec.bottom;
		}
		break;
	case VK_HOME:
		if ((pDoc->m_tagRec.top > 0) & (pDoc->m_tagRec.left > 0)) {
			pDoc->m_tagRec.top -= 5;
			pDoc->m_tagRec.left -= 5;
		}
		break;
	case VK_END:
		if ((pDoc->m_tagRec.bottom < clientRect.bottom)&(pDoc->m_tagRec.right < clientRect.right)) {
			pDoc->m_tagRec.top += 5;
			pDoc->m_tagRec.left += 5;
		}
		break;
	default:
		break;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFCApplication3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->m_tagRec.top = pDoc->origin.top;
	pDoc->m_tagRec.left = pDoc->origin.left;
	pDoc->m_tagRec.right = pDoc->origin.right;
	pDoc->m_tagRec.bottom = pDoc->origin.bottom;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
