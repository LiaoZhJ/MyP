// traverse.cpp : 实现文件
//

#include "stdafx.h"
#include "综合实验.h"
#include "traverse.h"
#include "afxdialogex.h"


// traverse 对话框

IMPLEMENT_DYNAMIC(traverse, CDialogEx)

traverse::traverse(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

traverse::~traverse()
{
}

void traverse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(traverse, CDialogEx)
END_MESSAGE_MAP()


// traverse 消息处理程序
