
// Student CatalogView.cpp : implementation of the CStudentCatalogView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Student Catalog.h"
#endif

#include "Student CatalogSet.h"
#include "Student CatalogDoc.h"
#include "Student CatalogView.h"

#include "AddNew.h"
#include "ConfirmDelete.h"
#include "EditRow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudentCatalogView

IMPLEMENT_DYNCREATE(CStudentCatalogView, CRecordView)

BEGIN_MESSAGE_MAP(CStudentCatalogView, CRecordView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_FIRST, &CStudentCatalogView::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CStudentCatalogView::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CStudentCatalogView::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CStudentCatalogView::OnRecordLast)
	ON_COMMAND(ID_DATA_ADDNEW, &CStudentCatalogView::OnDataAddnew)
	ON_COMMAND(ID_DATA_DELETECURRENT, &CStudentCatalogView::OnDataDeletecurrent)
	ON_COMMAND(ID_DATA_EDITCURRENT, &CStudentCatalogView::OnDataEditcurrent)
END_MESSAGE_MAP()

// CStudentCatalogView construction/destruction

CStudentCatalogView::CStudentCatalogView()
	: CRecordView(IDD_STUDENTCATALOG_FORM)
{
	m_pSet = NULL;
	// TODO: add construction code here

}

CStudentCatalogView::~CStudentCatalogView()
{
}

void CStudentCatalogView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// you can insert DDX_Field* functions here to 'connect' your controls to the database fields, ex.
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// See MSDN and ODBC samples for more information
}

BOOL CStudentCatalogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CStudentCatalogView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_StudentCatalogSet;
	CRecordView::OnInitialUpdate();

}


// CStudentCatalogView printing

BOOL CStudentCatalogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStudentCatalogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStudentCatalogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CStudentCatalogView diagnostics

#ifdef _DEBUG
void CStudentCatalogView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CStudentCatalogView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CStudentCatalogDoc* CStudentCatalogView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentCatalogDoc)));
	return (CStudentCatalogDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentCatalogView database support
CRecordset* CStudentCatalogView::OnGetRecordset()
{
	return m_pSet;
}



// CStudentCatalogView message handlers


void CStudentCatalogView::OnRecordFirst()
{
	// TODO: Add your command handler code here
	m_pSet->MoveFirst();
	Invalidate();
}


void CStudentCatalogView::OnRecordPrev()
{
	// TODO: Add your command handler code here
	if (!m_pSet->IsBOF()) {
		m_pSet->MovePrev();
		Invalidate();
	}
}


void CStudentCatalogView::OnRecordNext()
{
	// TODO: Add your command handler code here
	if (!m_pSet->IsEOF()) {
		m_pSet->MoveNext();
		Invalidate();
	}
}


void CStudentCatalogView::OnRecordLast()
{
	// TODO: Add your command handler code here
	m_pSet->MoveLast();
	Invalidate();
}


void CStudentCatalogView::OnDraw(CDC* pDC)
{
	// TODO: Add your specialized code here and/or call the base class
	CString str;
	CString name = CString(m_pSet->m_studentName);
	CString major = CString(m_pSet->m_studentMajor);
	CString year = CString(m_pSet->m_studentYear);

	str.Format(CString("ID: %d"), m_pSet->m_Id);
	pDC->TextOut(10, 10, str);

	str.Format(CString("Name: %s"), name);
	pDC->TextOut(10, 30, str);

	str.Format(CString("Major: %s"), major);
	pDC->TextOut(10, 50, str);

	str.Format(CString("Year: %s"), year);
	pDC->TextOut(10, 70, str);
}


void CStudentCatalogView::OnDataAddnew()
{
	// TODO: Add your command handler code here
	CAddNew obj;
	int id;
	CString newName, newMajor, newYear;

	if (obj.DoModal() == IDOK) {
		if (m_pSet->CanAppend()) {
			m_pSet->MoveLast();
			id = m_pSet->m_Id + 1;

			newName = obj.m_newStudentName;
			newMajor = obj.m_newStudentMajor;
			newYear = obj.m_newStudentYear;

			m_pSet->AddNew();

			m_pSet->m_Id = id;
			m_pSet->m_studentName = newName;
			m_pSet->m_studentMajor = newMajor;
			m_pSet->m_studentYear = newYear;

			m_pSet->Update();
			MessageBox(CString("Added"));
		}

		m_pSet->Requery();
		Invalidate();
	}
}


void CStudentCatalogView::OnDataDeletecurrent()
{
	// TODO: Add your command handler code here
	CConfirmDelete obj;
	if (obj.DoModal() == IDOK) {
		m_pSet->Delete();
		m_pSet->Requery();
		Invalidate();
	}
}


void CStudentCatalogView::OnDataEditcurrent()
{
	// TODO: Add your command handler code here
	CEditRow obj;

	CString name, major, year;

	if (obj.DoModal() == IDOK) {
		name = obj.m_editName;
		major = obj.m_editMajor;
		year = obj.m_editYear;

		obj.m_editName = m_pSet->m_studentName;
		obj.m_editMajor = m_pSet->m_studentMajor;
		obj.m_editYear = m_pSet->m_studentYear;

		m_pSet->Edit();
		m_pSet->m_studentName = name;
		m_pSet->m_studentMajor = major;
		m_pSet->m_studentYear = year;

		m_pSet->Update();
		m_pSet->Requery();
		Invalidate();
	}
}
