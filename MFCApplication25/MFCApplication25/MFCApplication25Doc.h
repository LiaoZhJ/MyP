
// MFCApplication25Doc.h : CMFCApplication25Doc ��Ľӿ�
//


#pragma once
#include "MFCApplication25Set.h"


class CMFCApplication25Doc : public CDocument
{
protected: // �������л�����
	CMFCApplication25Doc();
	DECLARE_DYNCREATE(CMFCApplication25Doc)

// ����
public:
	CMFCApplication25Set m_MFCApplication25Set;

// ����
public:
	
// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFCApplication25Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ�����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};