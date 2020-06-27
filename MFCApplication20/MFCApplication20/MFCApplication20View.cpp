
// MFCApplication20View.cpp : CMFCApplication20View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication20.h"
#endif

#include "MFCApplication20Doc.h"
#include "MFCApplication20View.h"
#include"fstream"
#include"iostream"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication20View

IMPLEMENT_DYNCREATE(CMFCApplication20View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication20View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFCApplication20View::OnFileOpen)
END_MESSAGE_MAP()

// CMFCApplication20View 构造/析构

CMFCApplication20View::CMFCApplication20View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication20View::~CMFCApplication20View()
{
}

BOOL CMFCApplication20View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication20View 绘制

void CMFCApplication20View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication20Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication20View 诊断

#ifdef _DEBUG
void CMFCApplication20View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication20View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication20Doc* CMFCApplication20View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication20Doc)));
	return (CMFCApplication20Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication20View 消息处理程序


void CMFCApplication20View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		ofstream ofs(_T("D:\\abc.txt"));
		ofs << CT2A(filename.GetString());
		
	}

}
