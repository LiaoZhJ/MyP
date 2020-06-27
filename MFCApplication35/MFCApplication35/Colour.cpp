// Colour.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication35.h"
#include "Colour.h"
#include "afxdialogex.h"


// Colour 对话框

IMPLEMENT_DYNAMIC(Colour, CDialogEx)

Colour::Colour(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, Green(0)
	, Red(0)
	, Blue(0)
{

}

Colour::~Colour()
{
}

void Colour::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Green);
	DDX_Text(pDX, IDC_EDIT2, Red);
	DDX_Text(pDX, IDC_EDIT3, Blue);
}


BEGIN_MESSAGE_MAP(Colour, CDialogEx)
END_MESSAGE_MAP()


// Colour 消息处理程序
