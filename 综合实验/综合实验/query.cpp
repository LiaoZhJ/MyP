// query.cpp : 实现文件
//

#include "stdafx.h"
#include "综合实验.h"
#include "query.h"
#include "afxdialogex.h"


// query 对话框

IMPLEMENT_DYNAMIC(query, CDialogEx)

query::query(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, where(_T(""))
{

}

query::~query()
{
}

void query::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, where);
}


BEGIN_MESSAGE_MAP(query, CDialogEx)
END_MESSAGE_MAP()


// query 消息处理程序
