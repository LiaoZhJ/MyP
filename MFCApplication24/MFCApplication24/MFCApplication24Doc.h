
// MFCApplication24Doc.h : CMFCApplication24Doc ��Ľӿ�
//


#pragma once
#include "MFCApplication24Set.h"


class CMFCApplication24Doc : public CDocument
{
protected: // �������л�����
	CMFCApplication24Doc();
	DECLARE_DYNCREATE(CMFCApplication24Doc)

// ����
public:
	CMFCApplication24Set m_MFCApplication24Set;

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
	virtual ~CMFCApplication24Doc();
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
