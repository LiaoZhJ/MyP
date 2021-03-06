
// MFCApplication36Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication36.h"
#include "MFCApplication36Dlg.h"
#include "afxdialogex.h"
#include"fstream"
#include"string"
#include"iostream"
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication36Dlg 对话框



CMFCApplication36Dlg::CMFCApplication36Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION36_DIALOG, pParent)
	, Select(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication36Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, Lbox);
	DDX_Text(pDX, IDC_EDIT1, Select);
}

BEGIN_MESSAGE_MAP(CMFCApplication36Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_WM_LBUTTONDOWN()
ON_LBN_SELCHANGE(IDC_LIST2, &CMFCApplication36Dlg::OnLbnSelchangeList2)
ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication36Dlg::Alter)
//ON_WM_CLOSE()
//ON_BN_CLICKED(IDOK, &CMFCApplication36Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCApplication36Dlg 消息处理程序

BOOL CMFCApplication36Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	CString str;
	ifstream ifs("D:\\学生名单.txt");
	string s;
	while (ifs >> s)
	{
		Lbox.AddString(CString(s.c_str()));
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication36Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication36Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication36Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CMFCApplication36Dlg::OnLbnSelchangeList2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	Lbox.GetText(Lbox.GetCurSel(),Select);
	UpdateData(false);
}


void CMFCApplication36Dlg::Alter()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	Lbox.DeleteString(Lbox.GetCurSel());             // 删除列表框选定字符串
	Lbox.InsertString(Lbox.GetCurSel(), Select);    // 把缓存str中的字符串插入到列表框B的最后一项
	UpdateData(false);
}


//BOOL CMFCApplication36Dlg::DestroyWindow()
//{
//	// TODO: 在此添加专用代码和/或调用基类

//	exit(0);
//	return CDialogEx::DestroyWindow();
//}


//void CMFCApplication36Dlg::OnClose()
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	ofstream ofs("D:\\学生名单.txt");
//	while(ofs << s);
//	CDialogEx::OnClose();
//}


//void CMFCApplication36Dlg::OnBnClickedOk()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	ofstream ofs("D:\\学生名单.txt");
//	while (ofs << s);
//	CDialogEx::OnOK();
//}
