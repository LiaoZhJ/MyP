
// MFCApplication22View.cpp : CMFCApplication22View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication22.h"
#endif

#include "MFCApplication22Set.h"
#include "MFCApplication22Doc.h"
#include "MFCApplication22View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication22View

IMPLEMENT_DYNCREATE(CMFCApplication22View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication22View, CRecordView)
END_MESSAGE_MAP()

// CMFCApplication22View ����/����

CMFCApplication22View::CMFCApplication22View()
	: CRecordView(IDD_MFCAPPLICATION22_FORM)
	, ID(0)
	, name(_T(""))
	, age(0)
	, number(0)
	, phonenum(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication22View::~CMFCApplication22View()
{
}

void CMFCApplication22View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_5);
}

BOOL CMFCApplication22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication22View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication22Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication22View ���

#ifdef _DEBUG
void CMFCApplication22View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication22View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication22Doc* CMFCApplication22View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication22Doc)));
	return (CMFCApplication22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication22View ���ݿ�֧��
CRecordset* CMFCApplication22View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication22View ��Ϣ�������
