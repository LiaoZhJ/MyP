
// MFCApplication36Dlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplication36Dlg �Ի���



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


// CMFCApplication36Dlg ��Ϣ�������

BOOL CMFCApplication36Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	CString str;
	ifstream ifs("D:\\ѧ������.txt");
	string s;
	while (ifs >> s)
	{
		Lbox.AddString(CString(s.c_str()));
	}
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication36Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication36Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CMFCApplication36Dlg::OnLbnSelchangeList2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	Lbox.GetText(Lbox.GetCurSel(),Select);
	UpdateData(false);
}


void CMFCApplication36Dlg::Alter()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	Lbox.DeleteString(Lbox.GetCurSel());             // ɾ���б��ѡ���ַ���
	Lbox.InsertString(Lbox.GetCurSel(), Select);    // �ѻ���str�е��ַ������뵽�б��B�����һ��
	UpdateData(false);
}


//BOOL CMFCApplication36Dlg::DestroyWindow()
//{
//	// TODO: �ڴ����ר�ô����/����û���

//	exit(0);
//	return CDialogEx::DestroyWindow();
//}


//void CMFCApplication36Dlg::OnClose()
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	ofstream ofs("D:\\ѧ������.txt");
//	while(ofs << s);
//	CDialogEx::OnClose();
//}


//void CMFCApplication36Dlg::OnBnClickedOk()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	ofstream ofs("D:\\ѧ������.txt");
//	while (ofs << s);
//	CDialogEx::OnOK();
//}
