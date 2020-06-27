
// MFCApplication24View.cpp : CMFCApplication24View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFCApplication24View 构造/析构

CMFCApplication24View::CMFCApplication24View()
	: CRecordView(IDD_MFCAPPLICATION24_FORM)
	, id(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	
}

CMFCApplication24View::~CMFCApplication24View()
{
}

void CMFCApplication24View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	CString filepath, s;
	s = m_pSet->m_2;
	filepath = _T("E:\\") + s;
	draw_pic(filepath);
	
	
}

BOOL CMFCApplication24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication24View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication24Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication24View 诊断

#ifdef _DEBUG
void CMFCApplication24View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication24View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication24Doc* CMFCApplication24View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication24Doc)));
	return (CMFCApplication24Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication24View 数据库支持
CRecordset* CMFCApplication24View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication24View 消息处理程序


void CMFCApplication24View::draw_pic(CString filepath)
{
	// TODO: 在此添加控件通知处理程序代码
	
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

