
// MFCApplication27Set.cpp : CMFCApplication27Set 类的实现
//

#include "stdafx.h"
#include "MFCApplication27.h"
#include "MFCApplication27Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication27Set 实现

// 代码生成在 2020年5月26日, 20:33

IMPLEMENT_DYNAMIC(CMFCApplication27Set, CRecordset)

CMFCApplication27Set::CMFCApplication27Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_1 = 0;
	m_2 = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMFCApplication27Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x76f8\x7247;DBQ=E:\\Temp\\db3.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCApplication27Set::GetDefaultSQL()
{
	return _T("[学生图片]");
}

void CMFCApplication27Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[字段1]"), m_1);
	RFX_Text(pFX, _T("[字段2]"), m_2);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication27Set 诊断

#ifdef _DEBUG
void CMFCApplication27Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication27Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

