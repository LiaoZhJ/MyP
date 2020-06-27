
// MFCApplication22Set.cpp : CMFCApplication22Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication22.h"
#include "MFCApplication22Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication22Set ʵ��

// ���������� 2020��5��5��, 20:00

IMPLEMENT_DYNAMIC(CMFCApplication22Set, CRecordset)

CMFCApplication22Set::CMFCApplication22Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_1 = 0;
	m_2 = L"";
	m_3 = 0;
	m_4 = 0;
	m_5 = 0;
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û�������֤��
CString CMFCApplication22Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f;DBQ=E:\\Temp\\Database1.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCApplication22Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void CMFCApplication22Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Long(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Long(pFX, _T("[�ֶ�4]"), m_4);
	RFX_Long(pFX, _T("[�ֶ�5]"), m_5);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication22Set ���

#ifdef _DEBUG
void CMFCApplication22Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication22Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
