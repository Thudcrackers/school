
// Student CatalogView.h : interface of the CStudentCatalogView class
//

#pragma once

class CStudentCatalogSet;

class CStudentCatalogView : public CRecordView
{
protected: // create from serialization only
	CStudentCatalogView();
	DECLARE_DYNCREATE(CStudentCatalogView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_STUDENTCATALOG_FORM };
#endif
	CStudentCatalogSet* m_pSet;

// Attributes
public:
	CStudentCatalogDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CStudentCatalogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnDataAddnew();
	afx_msg void OnDataDeletecurrent();
	afx_msg void OnDataEditcurrent();
};

#ifndef _DEBUG  // debug version in Student CatalogView.cpp
inline CStudentCatalogDoc* CStudentCatalogView::GetDocument() const
   { return reinterpret_cast<CStudentCatalogDoc*>(m_pDocument); }
#endif

