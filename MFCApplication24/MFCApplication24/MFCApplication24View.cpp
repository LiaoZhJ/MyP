
// MFCApplication24View.cpp : CMFCApplication24View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication24.h"
#endif

#include "MFCApplication24Set.h"
#include "MFCApplication24Doc.h"
#include "MFCApplication24View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication24View

IMPLEMENT_DYNCREATE(CMFCApplication24View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication24View, CRecordView)
//	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCApplication24View ����/����

CMFCApplication24View::CMFCApplication24View()
	: CRecordView(IDD_MFCAPPLICATION24_FORM)
	, id(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	
}

CMFCApplication24View::~CMFCApplication24View()
{
}

void CMFCApplication24View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	CString filepath, s;
	s = m_pSet->m_2;
	filepath = _T("E:\\") + s;
	draw_pic(filepath);
	
	
}

BOOL CMFCApplication24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication24View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication24Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication24View ���

#ifdef _DEBUG
void CMFCApplication24View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication24View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication24Doc* CMFCApplication24View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication24Doc)));
	return (CMFCApplication24Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication24View ���ݿ�֧��
CRecordset* CMFCApplication24View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication24View ��Ϣ�������


void CMFCApplication24View::draw_pic(CString filepath)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CImage img;
	img.Load(filepath);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

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

