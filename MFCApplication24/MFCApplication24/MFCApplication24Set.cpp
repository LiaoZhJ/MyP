
// MFCApplication24Set.cpp : CMFCApplication24Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication24.h"
#include "MFCApplication24Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication24Set ʵ��

// ���������� 2020��5��12��, 23:12

IMPLEMENT_DYNAMIC(CMFCApplication24Set, CRecordset)

CMFCApplication24Set::CMFCApplication24Set(CDatabase* pdb)
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
CString CMFCApplication24Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x76f8\x7247;DBQ=E:\\Temp\\db3.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCApplication24Set::GetDefaultSQL()
{
	return _T("[ѧ��ͼƬ]");
}

void CMFCApplication24Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication24Set ���

#ifdef _DEBUG
void CMFCApplication24Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication24Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

