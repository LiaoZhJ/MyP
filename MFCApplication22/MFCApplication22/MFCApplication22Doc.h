
// MFCApplication22Doc.h : CMFCApplication22Doc ��Ľӿ�
//


#pragma once
#include "MFCApplication22Set.h"


class CMFCApplication22Doc : public CDocument
{
protected: // �������л�����
	CMFCApplication22Doc();
	DECLARE_DYNCREATE(CMFCApplication22Doc)

// ����
public:
	CMFCApplication22Set m_MFCApplication22Set;

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
	virtual ~CMFCApplication22Doc();
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
