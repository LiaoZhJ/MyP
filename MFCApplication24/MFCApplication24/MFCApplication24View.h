
// MFCApplication24View.h : CMFCApplication24View 类的接口
//

#pragma once

class CMFCApplication24Set;

class CMFCApplication24View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCApplication24View();
	DECLARE_DYNCREATE(CMFCApplication24View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION24_FORM };
#endif
	CMFCApplication24Set* m_pSet;

// 特性
public:
	CMFCApplication24Doc* GetDocument() const;
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
	virtual ~CMFCApplication24View();
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
//	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFCApplication24View.cpp 中的调试版本
inline CMFCApplication24Doc* CMFCApplication24View::GetDocument() const
   { return reinterpret_cast<CMFCApplication24Doc*>(m_pDocument); }
#endif

