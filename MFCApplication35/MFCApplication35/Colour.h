#pragma once


// Colour �Ի���

class Colour : public CDialogEx
{
	DECLARE_DYNAMIC(Colour)

public:
	Colour(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Colour();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int Green;
	int Red;
	int Blue;
};
