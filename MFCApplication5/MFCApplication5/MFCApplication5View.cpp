
// MFCApplication5View.cpp : CMFCApplication5View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication5.h"
#endif

#include "MFCApplication5Doc.h"
#include "MFCApplication5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication5View

IMPLEMENT_DYNCREATE(CMFCApplication5View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication5View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication5View ����/����

CMFCApplication5View::CMFCApplication5View()
{
	// TODO: �ڴ˴����ӹ������

}

CMFCApplication5View::~CMFCApplication5View()
{
}

BOOL CMFCApplication5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication5View ����

void CMFCApplication5View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ�����������ӻ��ƴ���
}


// CMFCApplication5View ���

#ifdef _DEBUG
void CMFCApplication5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication5Doc* CMFCApplication5View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication5Doc)));
	return (CMFCApplication5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication5View ��Ϣ��������


void CMFCApplication5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ
	CMFCApplication5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CDC* pDC;
	pDC = GetDC();
	CString s;
	s.Format(_T("%d+%d=%d"), pDoc->A, pDoc->B, pDoc->A + pDoc->B);
	pDC->TextOutW(20, 20, s);
	CView::OnLButtonDown(nFlags, point);
}