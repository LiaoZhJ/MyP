
// MFCApplication26View.cpp : CMFCApplication26View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication26.h"
#endif

#include "MFCApplication26Doc.h"
#include "MFCApplication26View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication26View

IMPLEMENT_DYNCREATE(CMFCApplication26View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication26View, CView)
//	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication26View ����/����

CMFCApplication26View::CMFCApplication26View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication26View::~CMFCApplication26View()
{
}

BOOL CMFCApplication26View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication26View ����

void CMFCApplication26View::OnDraw(CDC* pDC)
{
	CMFCApplication26Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->rect);
}


// CMFCApplication26View ���

#ifdef _DEBUG
void CMFCApplication26View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication26View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication26Doc* CMFCApplication26View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication26Doc)));
	return (CMFCApplication26Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication26View ��Ϣ�������


//void CMFCApplication26View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	
//	CView::OnChar(nChar, nRepCnt, nFlags);
//}


void CMFCApplication26View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication26Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	switch (nChar)
	{
	case VK_HOME:
		if (pDoc->rect.top > 50 && pDoc->rect.left > 50)
		{
			pDoc->rect.top -= 50;
			pDoc->rect.left -= 50;
		}
		break;
	case VK_END:
		if (pDoc->rect.bottom-pDoc->rect.top > 50 && pDoc->rect.right-pDoc->rect.left > 50)
		{
			pDoc->rect.top += 50;
			pDoc->rect.left += 50;
		}
		break;
	default:
		break;
	}(nChar);
	Invalidate(TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFCApplication26View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication26Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->rect = pDoc->orect;
	Invalidate(TRUE);
	CView::OnLButtonDown(nFlags, point);
}
