
// MFCApplication23Doc.h : CMFCApplication23Doc ��Ľӿ�
//


#pragma once
#include "MFCApplication23Set.h"


class CMFCApplication23Doc : public CDocument
{
protected: // �������л�����
	CMFCApplication23Doc();
	DECLARE_DYNCREATE(CMFCApplication23Doc)

// ����
public:
	CMFCApplication23Set m_MFCApplication23Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFCApplication23Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
