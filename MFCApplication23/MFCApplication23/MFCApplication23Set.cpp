
// MFCApplication23Set.cpp : CMFCApplication23Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication23.h"
#include "MFCApplication23Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication23Set ʵ��

// ���������� 2020��5��12��, 19:46

IMPLEMENT_DYNAMIC(CMFCApplication23Set, CRecordset)

CMFCApplication23Set::CMFCApplication23Set(CDatabase* pdb)
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
CString CMFCApplication23Set::GetDefaultConnect()
{
	return _T("DSN=pic;DBQ=E:\\Temp\\db3.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCApplication23Set::GetDefaultSQL()
{
	return _T("[ѧ��ͼƬ]");
}

void CMFCApplication23Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication23Set ���

#ifdef _DEBUG
void CMFCApplication23Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication23Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

