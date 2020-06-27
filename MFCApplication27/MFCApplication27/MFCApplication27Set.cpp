
// MFCApplication27Set.cpp : CMFCApplication27Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication27.h"
#include "MFCApplication27Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication27Set ʵ��

// ���������� 2020��5��26��, 20:33

IMPLEMENT_DYNAMIC(CMFCApplication27Set, CRecordset)

CMFCApplication27Set::CMFCApplication27Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_1 = 0;
	m_2 = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCApplication27Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x76f8\x7247;DBQ=E:\\Temp\\db3.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCApplication27Set::GetDefaultSQL()
{
	return _T("[ѧ��ͼƬ]");
}

void CMFCApplication27Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication27Set ���

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

