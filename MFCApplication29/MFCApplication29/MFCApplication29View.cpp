
// MFCApplication29View.cpp : CMFCApplication29View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication29.h"
#endif

#include "MFCApplication29Doc.h"
#include "MFCApplication29View.h"
#include"AD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication29View

IMPLEMENT_DYNCREATE(CMFCApplication29View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication29View, CView)
	ON_COMMAND(ID_32771, &CMFCApplication29View::On32771)
END_MESSAGE_MAP()

// CMFCApplication29View ����/����

CMFCApplication29View::CMFCApplication29View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication29View::~CMFCApplication29View()
{
}

BOOL CMFCApplication29View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication29View ����

void CMFCApplication29View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication29Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCApplication29View ���

#ifdef _DEBUG
void CMFCApplication29View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication29View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication29Doc* CMFCApplication29View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication29Doc)));
	return (CMFCApplication29Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication29View ��Ϣ�������


void CMFCApplication29View::On32771()
{
	// TODO: �ڴ���������������
	AD dlg;
	dlg.DoModal();
}
