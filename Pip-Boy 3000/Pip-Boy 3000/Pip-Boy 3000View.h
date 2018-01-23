
// Pip-Boy 3000View.h : interface of the CPipBoy3000View class
//

#pragma once
#include "afxwin.h"
#include "image_weapons.h"

class CPipBoy3000Set;

class CPipBoy3000View : public CRecordView
{
protected: // create from serialization only
	CPipBoy3000View();
	DECLARE_DYNCREATE(CPipBoy3000View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_PIPBOY3000_FORM };
#endif
	CPipBoy3000Set* m_pSet;

// Attributes
public:
	CPipBoy3000Doc* GetDocument() const;

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
	virtual ~CPipBoy3000View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_apparelButton;
	CStatic m_weaponsButton;
	CStatic m_aidButton;
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnStnClickedStaticWeapons();
	CListBox m_inventoryList;
	CStringA category;
	DECLARE_EVENTSINK_MAP()
	void MouseDownImageWeapons(short Button, short Shift, float X, float Y);
	CImage_weapons m_weapons;
	void MouseDownImageApparel(short Button, short Shift, float X, float Y);
	CImage_weapons m_apparel;
	CImage_weapons m_aid;
	void MouseDownImageAid(short Button, short Shift, float X, float Y);
	afx_msg void OnBnClickedButtonPickup();
	afx_msg void OnBnClickedButtonDrop();
	int selectedCategory;
};

#ifndef _DEBUG  // debug version in Pip-Boy 3000View.cpp
inline CPipBoy3000Doc* CPipBoy3000View::GetDocument() const
   { return reinterpret_cast<CPipBoy3000Doc*>(m_pDocument); }
#endif

