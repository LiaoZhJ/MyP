
// MFCApplication31View.cpp : CMFCApplication31View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication31.h"
#endif

#include "MFCApplication31Doc.h"
#include "MFCApplication31View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication31View

IMPLEMENT_DYNCREATE(CMFCApplication31View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication31View, CView)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFCApplication31View ����/����

CMFCApplication31View::CMFCApplication31View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
	rect.top = 200;
	rect.bottom = 230;
	rect.left = 0;
	rect.right = 30;
	flag = true;
}

CMFCApplication31View::~CMFCApplication31View()
{
}

BOOL CMFCApplication31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication31View ����

void CMFCApplication31View::OnDraw(CDC* pDC)
{
	CMFCApplication31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (set)
	{
		SetTimer(1, 500, NULL);
	}
	CRect re;
	GetClientRect(&re);
	if (rect.right + 30 > re.right)
	{
		flag = false;
	}
	if (rect.left - 30 < re.left)
	{
		flag = true;
	}
	pDC->Ellipse(rect);
}


// CMFCApplication31View ���

#ifdef _DEBUG
void CMFCApplication31View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication31Doc* CMFCApplication31View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication31Doc)));
	return (CMFCApplication31Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication31View ��Ϣ�������


void CMFCApplication31View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag)
	{
		rect.left += 30;
		rect.right += 30;
	}
	else
	{
		rect.left -= 30;
		rect.right -= 30;
	}
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}


void CMFCApplication31View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = true;
	Invalidate(true);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication31View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	KillTimer(1);
	CView::OnLButtonDblClk(nFlags, point);
}
