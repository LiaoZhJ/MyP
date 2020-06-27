// MyD.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication21.h"
#include "MyD.h"
#include "afxdialogex.h"
#include"fstream"
#include"string"
#include"iostream"
using namespace std;


// MyD 对话框

IMPLEMENT_DYNAMIC(MyD, CDialogEx)

MyD::MyD(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyD::~MyD()
{
}

void MyD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyD, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyD::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyD 消息处理程序


void MyD::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	string filepath;
	ifstream ifs(_T("D:\\abc.txt"));
	ifs >> filepath;
	
	CImage img;
	int sx, sy, w, h;
	img.Load(CString(filepath.c_str()));
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	foo(img, sx, sy, w, h);
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}





void MyD::foo(CImage &img, int &sx, int &sy, int &w, int &h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

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
}
