// ALTER_DLG.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication27.h"
#include "ALTER_DLG.h"
#include "afxdialogex.h"


// ALTER_DLG 对话框

IMPLEMENT_DYNAMIC(ALTER_DLG, CDialogEx)

ALTER_DLG::ALTER_DLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, i(0)
	, p(_T(""))
{

}

ALTER_DLG::~ALTER_DLG()
{
}

void ALTER_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, i);
	DDX_Text(pDX, IDC_EDIT2, p);
}


BEGIN_MESSAGE_MAP(ALTER_DLG, CDialogEx)
END_MESSAGE_MAP()


// ALTER_DLG 消息处理程序
