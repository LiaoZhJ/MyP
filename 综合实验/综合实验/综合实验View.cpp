
// 综合实验View.cpp : C综合实验View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验.h"
#endif

#include "综合实验Set.h"
#include "综合实验Doc.h"
#include "综合实验View.h"
#include"query.h"
#include"alter.h"
#include"pic.h"
#include"tra.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验View

IMPLEMENT_DYNCREATE(C综合实验View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验View, CRecordView)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &C综合实验View::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_FIRST, &C综合实验View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C综合实验View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C综合实验View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C综合实验View::OnRecordLast)
	ON_COMMAND(ID_32771, &C综合实验View::Query)
	ON_COMMAND(ID_32772, &C综合实验View::order)
	ON_COMMAND(ID_32773, &C综合实验View::Traverse)
	ON_BN_CLICKED(IDC_BUTTON2, &C综合实验View::Delete)
	ON_BN_CLICKED(IDC_BUTTON3, &C综合实验View::Add)
	ON_BN_CLICKED(IDC_BUTTON4, &C综合实验View::Update)
END_MESSAGE_MAP()

// C综合实验View 构造/析构

C综合实验View::C综合实验View()
	: CRecordView(IDD_MY_FORM)
	, c1(_T(""))
	, c2(_T(""))
	, c3(_T(""))
	, c4(_T(""))
	, c5(_T(""))
	, c6(_T(""))
	, c7(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

C综合实验View::~C综合实验View()
{
}

void C综合实验View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column7);
}

BOOL C综合实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验View 诊断

#ifdef _DEBUG
void C综合实验View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验Doc* C综合实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验Doc)));
	return (C综合实验Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验View 数据库支持
CRecordset* C综合实验View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验View 消息处理程序

void C综合实验View::draw_pic(CString path)
{
	// TODO: 在此添加控件通知处理程序代码

	CImage img;
	img.Load(path);
	CDC* pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&rect);

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

void C综合实验View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	CString s;
	s = m_pSet->column8;
	filepath = _T("E:\\") + s;
	draw_pic(filepath);
}


void C综合实验View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	pic dlg;
	
	CString s = m_pSet->column8;
	dlg.path =_T("E:\\") + s;
	dlg.DoModal();
}


void C综合实验View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	Invalidate(true);
	UpdateData(false);
}


void C综合实验View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	Invalidate(true);
	UpdateData(false);
}


void C综合实验View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	Invalidate(true);
	UpdateData(false);
}


void C综合实验View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	Invalidate(true);
	UpdateData(false);
}


void C综合实验View::Query()
{
	// TODO: 在此添加命令处理程序代码
	query dlg;
	int r = dlg.DoModal();
	if (r = IDOK)
	{
		m_pSet->m_strFilter = dlg.where;
		m_pSet->Requery();
		Invalidate(true);
		UpdateData(false);
	}
}


void C综合实验View::order()
{
	// TODO: 在此添加命令处理程序代码
	query dlg;
	int r = dlg.DoModal();
	if (r = IDOK)
	{
		m_pSet->m_strSort= dlg.where;
		m_pSet->Requery();
		Invalidate(true);
		UpdateData(false);
	}
}


void C综合实验View::Traverse()
{
	// TODO: 在此添加命令处理程序代码
	
	int n=m_pSet->GetODBCFieldCount();
	CString str=_T("");
	CString s = _T("");
	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())
	{
		for (int i = 0; i < n; i++)
		{
			m_pSet->GetFieldValue((short)i, s);
			str = str +s+ _T(" ");
		}
		str = str + _T("\r\n");
		m_pSet->MoveNext();
	}
	tra dlg;
	dlg.ss = str;
	dlg.DoModal();
}


void C综合实验View::Delete()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	Invalidate(true);
	UpdateData(false);
}


void C综合实验View::Add()
{
	// TODO: 在此添加控件通知处理程序代码
	alter dlg;
	int r = dlg.DoModal();
	if (r = IDOK)
	{
		m_pSet->AddNew();
		m_pSet->column1 = dlg.Sname;
		m_pSet->column2 = dlg.Sno;
		m_pSet->column3 = dlg.Smajor;
		m_pSet->column4 = dlg.Ssex;
		m_pSet->column5 = dlg.Sbirth;
		m_pSet->column6 = dlg.Sphone;
		m_pSet->column7 = dlg.Saddress;
		m_pSet->column8 = dlg.Spath;
		m_pSet->Update();
		UpdateData(false);
	}
}


void C综合实验View::Update()
{
	// TODO: 在此添加控件通知处理程序代码
	alter dlg;
	int r = dlg.DoModal();
	if (r = IDOK)
	{
		m_pSet->Edit();
		m_pSet->column1 = dlg.Sname;
		m_pSet->column2 = dlg.Sno;
		m_pSet->column3 = dlg.Smajor;
		m_pSet->column4 = dlg.Ssex;
		m_pSet->column5 = dlg.Sbirth;
		m_pSet->column6 = dlg.Sphone;
		m_pSet->column7 = dlg.Saddress;
		m_pSet->column8 = dlg.Spath;
		m_pSet->Update();
		UpdateData(false);
	}
}
