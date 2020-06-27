
// MFCApplication27View.cpp : CMFCApplication27View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFCApplication27View 构造/析构

CMFCApplication27View::CMFCApplication27View()
	: CRecordView(IDD_MFCAPPLICATION27_FORM)
	, id(0)
	, path(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFCApplication27View::~CMFCApplication27View()
{
}

void CMFCApplication27View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet ->m_2 );
}

BOOL CMFCApplication27View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication27View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication27Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication27View 诊断

#ifdef _DEBUG
void CMFCApplication27View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication27View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication27Doc* CMFCApplication27View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication27Doc)));
	return (CMFCApplication27Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication27View 数据库支持
CRecordset* CMFCApplication27View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication27View 消息处理程序


void CMFCApplication27View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}
