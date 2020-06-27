
// MFCApplication23View.h : CMFCApplication23View 类的接口
//

#pragma once

class CMFCApplication23Set;

class CMFCApplication23View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCApplication23View();
	DECLARE_DYNCREATE(CMFCApplication23View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION23_FORM };
#endif
	CMFCApplication23Set* m_pSet;

// 特性
public:
	CMFCApplication23Doc* GetDocument() const;
	void draw_pic(CString filepath);

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
	virtual ~CMFCApplication23View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long id;
	afx_msg void OnBnClickedButton1();

};

#ifndef _DEBUG  // MFCApplication23View.cpp 中的调试版本
inline CMFCApplication23Doc* CMFCApplication23View::GetDocument() const
   { return reinterpret_cast<CMFCApplication23Doc*>(m_pDocument); }
#endif

