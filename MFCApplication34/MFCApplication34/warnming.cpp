// warnming.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication34.h"
#include "warnming.h"
#include "afxdialogex.h"


// warnming 对话框

IMPLEMENT_DYNAMIC(warnming, CDialogEx)

warnming::warnming(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

warnming::~warnming()
{
}

void warnming::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(warnming, CDialogEx)
END_MESSAGE_MAP()


// warnming 消息处理程序
