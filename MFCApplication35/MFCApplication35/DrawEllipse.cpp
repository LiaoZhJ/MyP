// DrawEllipse.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication35.h"
#include "DrawEllipse.h"
#include "afxdialogex.h"


// DrawEllipse 对话框

IMPLEMENT_DYNAMIC(DrawEllipse, CDialogEx)

DrawEllipse::DrawEllipse(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, recttop(0)
	, rectleft(0)
	, rectbottom(0)
	, rectright(0)
{

}

DrawEllipse::~DrawEllipse()
{
}

void DrawEllipse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, recttop);
	DDX_Text(pDX, IDC_EDIT3, rectleft);
	DDX_Text(pDX, IDC_EDIT2, rectbottom);
	DDX_Text(pDX, IDC_EDIT4, rectright);
}


BEGIN_MESSAGE_MAP(DrawEllipse, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &DrawEllipse::OnBnClickedButton2)
END_MESSAGE_MAP()


// DrawEllipse 消息处理程序


void DrawEllipse::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	UpdateData(false);
	OnOK();
}
