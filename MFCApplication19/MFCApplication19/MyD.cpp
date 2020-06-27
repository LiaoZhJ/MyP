// MyD.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication19.h"
#include "MyD.h"
#include "afxdialogex.h"


// MyD 对话框

IMPLEMENT_DYNAMIC(MyD, CDialogEx)

MyD::MyD(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, fname(_T(""))
{

}

MyD::~MyD()
{
}

void MyD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, fname);
}


BEGIN_MESSAGE_MAP(MyD, CDialogEx)
	ON_COMMAND(ID_32771, &MyD::On32771)
	ON_EN_CHANGE(IDC_EDIT1, &MyD::OnEnChangeEdit1)
END_MESSAGE_MAP()


// MyD 消息处理程序


void MyD::On32771()
{
	// TODO: 在此添加命令处理程序代码

}


void MyD::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码


}
