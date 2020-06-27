
// MFCApplication23View.cpp : CMFCApplication23View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication23.h"
#endif

#include "MFCApplication23Set.h"
#include "MFCApplication23Doc.h"
#include "MFCApplication23View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication23View

IMPLEMENT_DYNCREATE(CMFCApplication23View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication23View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication23View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMFCApplication23View ����/����

CMFCApplication23View::CMFCApplication23View()
	: CRecordView(IDD_MFCAPPLICATION23_FORM)
	, id(0)
	
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication23View::~CMFCApplication23View()
{
}

void CMFCApplication23View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);


}

BOOL CMFCApplication23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication23View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication23Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication23View ���

#ifdef _DEBUG
void CMFCApplication23View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication23View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication23Doc* CMFCApplication23View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication23Doc)));
	return (CMFCApplication23Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication23View ���ݿ�֧��
CRecordset* CMFCApplication23View::OnGetRecordset()
{

	return m_pSet;
}



// CMFCApplication23View ��Ϣ�������


void CMFCApplication23View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString filepath,s;
	m_pSet->GetFieldValue(short(1), s);//�Ӽ�¼����ǰ��¼����ȡ��2���ֶ�ֵ������s�� 
	filepath = _T("E:\\" ) + s;
	CMFCApplication23View::draw_pic(filepath);
}

void CMFCApplication23View::draw_pic(CString filepath)
{

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
	img.Draw(pDC->m_hDC,sx,sy,w,h);
	ReleaseDC(pDC);
}
