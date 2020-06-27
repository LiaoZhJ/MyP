
// MFCApplication25View.cpp : CMFCApplication25View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication25.h"
#endif

#include "MFCApplication25Set.h"
#include "MFCApplication25Doc.h"
#include "MFCApplication25View.h"
#include"MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication25View

IMPLEMENT_DYNCREATE(CMFCApplication25View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication25View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFCApplication25View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCApplication25View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCApplication25View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCApplication25View::OnRecordLast)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication25View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMFCApplication25View ����/����

CMFCApplication25View::CMFCApplication25View()
	: CRecordView(IDD_MFCAPPLICATION25_FORM)
	, id(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	

}

CMFCApplication25View::~CMFCApplication25View()
{
}

void CMFCApplication25View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFCApplication25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication25View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication25Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication25View ���

#ifdef _DEBUG
void CMFCApplication25View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication25View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication25Doc* CMFCApplication25View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication25Doc)));
	return (CMFCApplication25Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication25View ���ݿ�֧��
CRecordset* CMFCApplication25View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication25View ��Ϣ�������

void CMFCApplication25View::draw_pic(CString path)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CImage img;
	img.Load(path);
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

void CMFCApplication25View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	Invalidate(true);
	UpdateData(false);
}


void CMFCApplication25View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if(m_pSet->IsBOF())
		m_pSet->MoveFirst();
	Invalidate(true);
	UpdateData(false);
}


void CMFCApplication25View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	Invalidate(true);
	UpdateData(false);
}


void CMFCApplication25View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	Invalidate(true);
	UpdateData(false);
}


void CMFCApplication25View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	CString s;
	s = m_pSet->m_2;
	filepath = _T("E:\\") + s;
	//dc.TextOutW(1000, 100, filepath);
	draw_pic(filepath);
}


void CMFCApplication25View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString  s;
	s = m_pSet->m_2;
	filepath = _T("E:\\") + s;
	

	MyDialog dlg;
	dlg.path = filepath;
	dlg.DoModal();
	
}
