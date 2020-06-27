
// MFCApplication23View.cpp : CMFCApplication23View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFCApplication23View 构造/析构

CMFCApplication23View::CMFCApplication23View()
	: CRecordView(IDD_MFCAPPLICATION23_FORM)
	, id(0)
	
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFCApplication23View::~CMFCApplication23View()
{
}

void CMFCApplication23View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);


}

BOOL CMFCApplication23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication23View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication23Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication23View 诊断

#ifdef _DEBUG
void CMFCApplication23View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication23View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication23Doc* CMFCApplication23View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication23Doc)));
	return (CMFCApplication23Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication23View 数据库支持
CRecordset* CMFCApplication23View::OnGetRecordset()
{

	return m_pSet;
}



// CMFCApplication23View 消息处理程序


void CMFCApplication23View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString filepath,s;
	m_pSet->GetFieldValue(short(1), s);//从记录集当前记录，读取第2个字段值，放入s中 
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
