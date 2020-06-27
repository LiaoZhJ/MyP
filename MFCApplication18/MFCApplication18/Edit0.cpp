// Edit0.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication18.h"
#include "Edit0.h"
#include "afxdialogex.h"


// Edit0 对话框

IMPLEMENT_DYNAMIC(Edit0, CDialogEx)

Edit0::Edit0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, str(_T(""))
	, str2(_T(""))
{

}

Edit0::~Edit0()
{
}

void Edit0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, str);
	DDX_Text(pDX, IDC_EDIT2, str2);
}


BEGIN_MESSAGE_MAP(Edit0, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &Edit0::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &Edit0::OnBnClickedButton1)
END_MESSAGE_MAP()


// Edit0 消息处理程序


void Edit0::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Edit0::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	CString s;
	s = str;
	str = str2;
	str2 = s;
	this->UpdateData(false);
}
