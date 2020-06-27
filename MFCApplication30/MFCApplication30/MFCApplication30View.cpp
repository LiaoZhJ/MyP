
// MFCApplication30View.cpp : CMFCApplication30View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication30.h"
#endif

#include "MFCApplication30Doc.h"
#include "MFCApplication30View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication30View

IMPLEMENT_DYNCREATE(CMFCApplication30View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication30View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication30View ����/����

CMFCApplication30View::CMFCApplication30View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;
	rect.top = 0;
	rect.left = 200;
	rect.bottom = 30;
	rect.right = 230;
	flag = true;
}

CMFCApplication30View::~CMFCApplication30View()
{
}

BOOL CMFCApplication30View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication30View ����

void CMFCApplication30View::OnDraw(CDC* pDC)
{
	CMFCApplication30Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (set)
	{
		SetTimer(1,500,NULL);
		set = false;
	}
	CRect cr;
	GetClientRect(&cr);
	if (rect.bottom +30>cr.bottom) 
	{
		flag = false;
	}
	if (rect.top -30<cr.top)
	{
		flag = true;
	}
	pDC->Ellipse(rect);
}


// CMFCApplication30View ���

#ifdef _DEBUG
void CMFCApplication30View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication30View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication30Doc* CMFCApplication30View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication30Doc)));
	return (CMFCApplication30Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication30View ��Ϣ�������


void CMFCApplication30View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag) 
	{
		rect.top += 20;
		rect.bottom += 20;
	}
	else
	{
		rect.top -= 20;
		rect.bottom -= 20;
	}
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}
