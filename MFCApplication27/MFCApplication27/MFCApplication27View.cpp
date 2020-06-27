
// MFCApplication27View.cpp : CMFCApplication27View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication27.h"
#endif

#include "MFCApplication27Set.h"
#include "MFCApplication27Doc.h"
#include "MFCApplication27View.h"
#include"ADD_DLG.h"
#include"ALTER_DLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication27View

IMPLEMENT_DYNCREATE(CMFCApplication27View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication27View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication27View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication27View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication27View::OnBnClickedButton3)
END_MESSAGE_MAP()

// CMFCApplication27View ����/����

CMFCApplication27View::CMFCApplication27View()
	: CRecordView(IDD_MFCAPPLICATION27_FORM)
	, id(0)
	, path(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication27View::~CMFCApplication27View()
{
}

void CMFCApplication27View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet ->m_2 );
}

BOOL CMFCApplication27View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication27View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication27Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication27View ���

#ifdef _DEBUG
void CMFCApplication27View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication27View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication27Doc* CMFCApplication27View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication27Doc)));
	return (CMFCApplication27Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication27View ���ݿ�֧��
CRecordset* CMFCApplication27View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication27View ��Ϣ�������


void CMFCApplication27View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ADD_DLG dlg;
	int r = dlg.DoModal();
	if(r==IDOK){
		m_pSet->AddNew();
		m_pSet->m_1 = dlg.i;
		m_pSet->m_2 = dlg.p;
		m_pSet->Update();
		UpdateData(false);
	}
	
}


void CMFCApplication27View::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ALTER_DLG dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {
		m_pSet->Edit();
		m_pSet->m_1 = dlg.i;
		m_pSet->m_2 = dlg.p;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CMFCApplication27View::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}
