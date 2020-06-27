
// MFCApplication28View.cpp : CMFCApplication28View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication28.h"
#endif

#include "MFCApplication28Doc.h"
#include "MFCApplication28View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication28View

IMPLEMENT_DYNCREATE(CMFCApplication28View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication28View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication28View ����/����

CMFCApplication28View::CMFCApplication28View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication28View::~CMFCApplication28View()
{
}

BOOL CMFCApplication28View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication28View ����

void CMFCApplication28View::OnDraw(CDC* pDC)
{
	CMFCApplication28Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->rect);
}


// CMFCApplication28View ���

#ifdef _DEBUG
void CMFCApplication28View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication28View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication28Doc* CMFCApplication28View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication28Doc)));
	return (CMFCApplication28Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication28View ��Ϣ�������


void CMFCApplication28View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication28Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->x1 = point.x;
	pDoc->y1 = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication28View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication28Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->x2 = point.x;
	pDoc->y2 = point.y;
	pDoc->rect.top += pDoc->y2 - pDoc->y1;
	pDoc->rect.left += pDoc->x2 - pDoc->x1;
	pDoc->rect.bottom+= pDoc->y2 - pDoc->y1;
	pDoc->rect.right += pDoc->x2 - pDoc->x1;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
