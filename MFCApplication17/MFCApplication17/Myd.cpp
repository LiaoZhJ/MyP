// Myd.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication17.h"
#include "Myd.h"
#include "afxdialogex.h"


// Myd 对话框

IMPLEMENT_DYNAMIC(Myd, CDialogEx)

Myd::Myd(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Myd::~Myd()
{
}

void Myd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Myd, CDialogEx)
END_MESSAGE_MAP()


// Myd 消息处理程序
