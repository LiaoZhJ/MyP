
// MFCApplication35View.cpp : CMFCApplication35View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication35.h"
#endif

#include "MFCApplication35Doc.h"
#include "MFCApplication35View.h"
#include"DrawEllipse.h"
#include"Colour.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication35View

IMPLEMENT_DYNCREATE(CMFCApplication35View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication35View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32771, &CMFCApplication35View::On32771)
	
	ON_COMMAND(ID_32772, &CMFCApplication35View::On32772)
END_MESSAGE_MAP()

// CMFCApplication35View ����/����

CMFCApplication35View::CMFCApplication35View()
{
	// TODO: �ڴ˴���ӹ������
	flag = false;
	tt = false;
	ff = false;
}

CMFCApplication35View::~CMFCApplication35View()
{
}

BOOL CMFCApplication35View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication35View ����

void CMFCApplication35View::OnDraw(CDC* pDC)
{
	CMFCApplication35Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (flag||tt)
	{
		pDC->Ellipse(rect);
	}
	tt = false;
}


// CMFCApplication35View ���

#ifdef _DEBUG
void CMFCApplication35View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication35View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication35Doc* CMFCApplication35View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication35Doc)));
	return (CMFCApplication35Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication35View ��Ϣ�������


void CMFCApplication35View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//if (point.x > rect.left&&point.x<rect.right&&point.y>rect.top&&point.y < rect.bottom)
	ff = true;

	CDC * dc = GetDC();
	CPen pen(PS_DASH, 1, RGB(200, 100, 100));//����
	CPen * pOldPen = dc->SelectObject(&pen);
	dc->Rectangle(&rect);
	dc->SelectObject(pOldPen);
	dc->Ellipse(&rect);

	rect.left = point.x;
	rect.top = point.y;
	flag = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication35View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (ff)
	{
		rect.right = point.x;
		rect.bottom = point.y;
		if (flag)
			Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication35View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = false;
	ff = false;
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication35View::On32771()
{
	// TODO: �ڴ���������������
	
	DrawEllipse dlg;
	int r=dlg.DoModal();
	if (r = IDC_BUTTON2)
	{
		rect.top = dlg.recttop;
		rect.bottom = dlg.rectbottom;
		rect.left = dlg.rectleft;
		rect.right = dlg.rectright;
		tt = true;
	}
	Invalidate();
}





void CMFCApplication35View::On32772()
{
	// TODO: �ڴ���������������
	Colour dlg;
	int r=dlg.DoModal();
	if (r = IDOK)
	{
		CDC * dc = GetDC();
		CBrush brush(RGB(dlg.Red, dlg.Green, dlg.Blue));
		CBrush * pOldbrush = dc->SelectObject(&brush);
		dc->Ellipse(&rect);
		dc->SelectObject(pOldbrush);
	}
}
