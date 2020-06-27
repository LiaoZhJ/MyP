
// MFCApplication22View.cpp : CMFCApplication22View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFCApplication22View 构造/析构

CMFCApplication22View::CMFCApplication22View()
	: CRecordView(IDD_MFCAPPLICATION22_FORM)
	, ID(0)
	, name(_T(""))
	, age(0)
	, number(0)
	, phonenum(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFCApplication22View::~CMFCApplication22View()
{
}

void CMFCApplication22View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_5);
}

BOOL CMFCApplication22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication22View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication22Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication22View 诊断

#ifdef _DEBUG
void CMFCApplication22View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication22View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication22Doc* CMFCApplication22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication22Doc)));
	return (CMFCApplication22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication22View 数据库支持
CRecordset* CMFCApplication22View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication22View 消息处理程序
