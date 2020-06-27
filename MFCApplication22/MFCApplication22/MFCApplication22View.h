
// MFCApplication22View.h : CMFCApplication22View 类的接口
//

#pragma once

class CMFCApplication22Set;

class CMFCApplication22View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCApplication22View();
	DECLARE_DYNCREATE(CMFCApplication22View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION22_FORM };
#endif
	CMFCApplication22Set* m_pSet;

// 特性
public:
	CMFCApplication22Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCApplication22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	long age;
	long number;
	long phonenum;
};

#ifndef _DEBUG  // MFCApplication22View.cpp 中的调试版本
inline CMFCApplication22Doc* CMFCApplication22View::GetDocument() const
   { return reinterpret_cast<CMFCApplication22Doc*>(m_pDocument); }
#endif

