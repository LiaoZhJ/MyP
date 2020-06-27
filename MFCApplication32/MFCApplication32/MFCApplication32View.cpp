
// MFCApplication32View.cpp : CMFCApplication32View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication32.h"
#endif

#include "MFCApplication32Doc.h"
#include "MFCApplication32View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication32View

IMPLEMENT_DYNCREATE(CMFCApplication32View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication32View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFCApplication32View::OnFileOpen)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCApplication32View ����/����

CMFCApplication32View::CMFCApplication32View()
{
	// TODO: �ڴ˴���ӹ������
	flag = false;

}

CMFCApplication32View::~CMFCApplication32View()
{
}

BOOL CMFCApplication32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication32View ����

void CMFCApplication32View::OnDraw(CDC* pDC)
{
	CMFCApplication32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	
}


// CMFCApplication32View ���

#ifdef _DEBUG
void CMFCApplication32View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication32Doc* CMFCApplication32View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication32Doc)));
	return (CMFCApplication32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication32View ��Ϣ�������

void CMFCApplication32View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	
	if (r = IDOK)
	{
		path=cfd.GetPathName();
		flag = true;
		Invalidate(true);
	}
	
}


void CMFCApplication32View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CView::OnPaint()
	if (flag) 
	{
		CDC* pDC;
		pDC = GetDC();
		CImage img;
		img.Load(path);
		int sx, sy, w, h;
		CRect rect;
		GetClientRect(&rect);

		float rect_ratio = 1.0*rect.Width() / rect.Height();
		float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

		if (rect_ratio > img_ratio)
		{
			h = rect.Height();
			w = img_ratio*h;
			sx = (rect.Width() - w) / 2;
			sy = 0;
		}
		else
		{
			w = rect.Width();
			h = w / img_ratio;
			sx = 0;
			sy = (rect.Height() - h) / 2;
		}
		pDC->SetStretchBltMode(HALFTONE);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
	}
	
