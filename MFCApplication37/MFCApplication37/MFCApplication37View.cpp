
// MFCApplication37View.cpp : CMFCApplication37View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication37.h"
#endif

#include "MFCApplication37Doc.h"
#include "MFCApplication37View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication37View

IMPLEMENT_DYNCREATE(CMFCApplication37View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication37View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication37View ����/����

CMFCApplication37View::CMFCApplication37View()
{
	// TODO: �ڴ˴���ӹ������
	flag = false;
}

CMFCApplication37View::~CMFCApplication37View()
{
}

BOOL CMFCApplication37View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication37View ����

void CMFCApplication37View::OnDraw(CDC* pDC)
{
	CMFCApplication37Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < pDoc->ca.GetSize(); i++)
	{
		pDC->Ellipse(pDoc->ca.GetAt(i));
	}
	pDC->Ellipse(rect);
}


// CMFCApplication37View ���

#ifdef _DEBUG
void CMFCApplication37View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication37View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication37Doc* CMFCApplication37View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication37Doc)));
	return (CMFCApplication37Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication37View ��Ϣ�������


void CMFCApplication37View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	rect.top = point.y;
	rect.left = point.x;
	
	flag = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication37View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	rect.bottom = point.y;
	rect.right = point.x;
	if (flag)
		InvalidateRect(&rect);
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication37View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication37Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	rect.bottom = point.y;
	rect.right = point.x;
	flag = false;
	pDoc->ca.Add(rect);
	CView::OnLButtonUp(nFlags, point);
}
