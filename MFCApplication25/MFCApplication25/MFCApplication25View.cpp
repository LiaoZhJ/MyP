
// MFCApplication25View.cpp : CMFCApplication25View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFCApplication25View 构造/析构

CMFCApplication25View::CMFCApplication25View()
	: CRecordView(IDD_MFCAPPLICATION25_FORM)
	, id(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	

}

CMFCApplication25View::~CMFCApplication25View()
{
}

void CMFCApplication25View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFCApplication25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication25View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication25Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication25View 诊断

#ifdef _DEBUG
void CMFCApplication25View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication25View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication25Doc* CMFCApplication25View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication25Doc)));
	return (CMFCApplication25Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication25View 数据库支持
CRecordset* CMFCApplication25View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication25View 消息处理程序

void CMFCApplication25View::draw_pic(CString path)
{
	// TODO: 在此添加控件通知处理程序代码

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
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	Invalidate(true);
	UpdateData(false);
}


void CMFCApplication25View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if(m_pSet->IsBOF())
		m_pSet->MoveFirst();
	Invalidate(true);
	UpdateData(false);
}


void CMFCApplication25View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	Invalidate(true);
	UpdateData(false);
}


void CMFCApplication25View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	Invalidate(true);
	UpdateData(false);
}


void CMFCApplication25View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	CString s;
	s = m_pSet->m_2;
	filepath = _T("E:\\") + s;
	//dc.TextOutW(1000, 100, filepath);
	draw_pic(filepath);
}


void CMFCApplication25View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString  s;
	s = m_pSet->m_2;
	filepath = _T("E:\\") + s;
	

	MyDialog dlg;
	dlg.path = filepath;
	dlg.DoModal();
	
}
