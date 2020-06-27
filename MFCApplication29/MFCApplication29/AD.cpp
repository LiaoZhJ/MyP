// AD.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication29.h"
#include "AD.h"
#include "afxdialogex.h"


// AD 对话框

IMPLEMENT_DYNAMIC(AD, CDialogEx)

AD::AD(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x1(0)
	, x2(0)
	, sum(0)
{

}

AD::~AD()
{
}

void AD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x1);
	DDX_Text(pDX, IDC_EDIT2, x2);
	DDX_Text(pDX, IDC_EDIT3, sum);
}


BEGIN_MESSAGE_MAP(AD, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &AD::OnBnClickedButton1)
END_MESSAGE_MAP()


// AD 消息处理程序


void AD::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	sum = x1 + x2;
	UpdateData(false);
}
