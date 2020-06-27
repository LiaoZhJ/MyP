
// MFCApplication25View.h : CMFCApplication25View 类的接口
//

#pragma once

class CMFCApplication25Set;

class CMFCApplication25View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCApplication25View();
	DECLARE_DYNCREATE(CMFCApplication25View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION25_FORM };
#endif
	CMFCApplication25Set* m_pSet;

// 特性
public:
	CMFCApplication25Doc* GetDocument() const;
	CString filepath;
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
	virtual ~CMFCApplication25View();
	void draw_pic(CString filepath);
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
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // MFCApplication25View.cpp 中的调试版本
inline CMFCApplication25Doc* CMFCApplication25View::GetDocument() const
   { return reinterpret_cast<CMFCApplication25Doc*>(m_pDocument); }
#endif

