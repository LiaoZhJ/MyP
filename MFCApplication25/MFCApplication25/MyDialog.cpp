// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication25.h"
#include "MyDialog.h"
#include "afxdialogex.h"
#include "MFCApplication25Doc.h"
#include "MFCApplication25View.h"



// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDialog::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// MyDialog 消息处理程序



void MyDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void MyDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()

	CImage img;
	img.Load(path);

	CDC* pDC = GetDlgItem(IDC_pic)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_pic)->GetClientRect(&rect);

	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}
