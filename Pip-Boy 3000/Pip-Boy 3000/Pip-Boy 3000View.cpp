
// Pip-Boy 3000View.cpp : implementation of the CPipBoy3000View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Pip-Boy 3000.h"
#endif

#include "Pip-Boy 3000Set.h"
#include "Pip-Boy 3000Doc.h"
#include "Pip-Boy 3000View.h"

#include "WeaponsDialog.h"
#include "InventoryManagement.h"
#include "MainFrm.h"
#include "PickUpDialog.h"
#include "DropItemDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPipBoy3000View

IMPLEMENT_DYNCREATE(CPipBoy3000View, CRecordView)

BEGIN_MESSAGE_MAP(CPipBoy3000View, CRecordView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_STN_CLICKED(IDC_STATIC_WEAPONS, &CPipBoy3000View::OnStnClickedStaticWeapons)
	ON_BN_CLICKED(IDC_BUTTON_PICKUP, &CPipBoy3000View::OnBnClickedButtonPickup)
	ON_BN_CLICKED(IDC_BUTTON_DROP, &CPipBoy3000View::OnBnClickedButtonDrop)
END_MESSAGE_MAP()

// CPipBoy3000View construction/destruction

CPipBoy3000View::CPipBoy3000View()
	: CRecordView(IDD_PIPBOY3000_FORM)
	, selectedCategory(0)
{
	m_pSet = NULL;
	// TODO: add construction code here

}

CPipBoy3000View::~CPipBoy3000View()
{
}

void CPipBoy3000View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// you can insert DDX_Field* functions here to 'connect' your controls to the database fields, ex.
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// See MSDN and ODBC samples for more information
	DDX_Control(pDX, IDC_STATIC_APPAREL, m_apparelButton);
	DDX_Control(pDX, IDC_STATIC_WEAPONS, m_weaponsButton);
	DDX_Control(pDX, IDC_STATIC_AID, m_aidButton);
	DDX_Control(pDX, IDC_LIST_INVENTORY, m_inventoryList);
	DDX_Control(pDX, IDC_IMAGE_WEAPONS, m_weapons);
	DDX_Control(pDX, IDC_IMAGE_APPAREL, m_apparel);
	DDX_Control(pDX, IDC_IMAGE_AID, m_aid);
}

BOOL CPipBoy3000View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CPipBoy3000View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_PipBoy3000Set;
	CRecordView::OnInitialUpdate();

	m_apparel.MoveWindow(5, 1, 96, 32);
	m_weapons.MoveWindow(120, 0, 96, 32);
	m_aid.MoveWindow(216, 1, 96, 32);

	m_apparelButton.MoveWindow(5, 1, 96, 32);
	m_weaponsButton.MoveWindow(120, 0, 96, 32);
	m_aidButton.MoveWindow(216, 1, 96, 32);

	category = "Apparel";
}


// CPipBoy3000View printing

BOOL CPipBoy3000View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPipBoy3000View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPipBoy3000View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CPipBoy3000View diagnostics

#ifdef _DEBUG
void CPipBoy3000View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CPipBoy3000View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CPipBoy3000Doc* CPipBoy3000View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPipBoy3000Doc)));
	return (CPipBoy3000Doc*)m_pDocument;
}
#endif //_DEBUG


// CPipBoy3000View database support
CRecordset* CPipBoy3000View::OnGetRecordset()
{
	return m_pSet;
}



// CPipBoy3000View message handlers


void CPipBoy3000View::OnDraw(CDC* pDC)
{
	// TODO: Add your specialized code here and/or call the base class
	CRgn win;
	CRect obj;
	GetClientRect(obj);

	win.CreateRectRgn(0, 0, obj.Width(), obj.Height());
	CBrush b = RGB(0, 51, 0);
	pDC->FillRgn(&win, &b);



	pDC->SetBkColor(RGB(0, 51, 0));
	pDC->SetTextColor(RGB(0, 204, 68));

	pDC->TextOut(10, 40, CString("[Name]"));
	pDC->TextOutW(210, 40, CString("[Weight]"));
	pDC->TextOutW(410, 40, CString("[Quantity]"));

	CString str;
	int pos = 60;
	while (!m_pSet->IsEOF()) {
		if (m_pSet->m_category == category) {
			CString name = CString(m_pSet->m_itemName);
			pDC->TextOut(10, pos, name);
			str.Format(CString("%.2f"), m_pSet->m_weight);
			pDC->TextOut(210, pos, str);
			str.Format(CString("%d"), m_pSet->m_quantity);
			pDC->TextOut(410, pos, str);
			pos += 20;
		}
		m_pSet->MoveNext();
	}
}


void CPipBoy3000View::OnStnClickedStaticWeapons()
{
	// TODO: Add your control notification handler code here

}
BEGIN_EVENTSINK_MAP(CPipBoy3000View, CRecordView)
	ON_EVENT(CPipBoy3000View, IDC_IMAGE_WEAPONS, DISPID_MOUSEDOWN, CPipBoy3000View::MouseDownImageWeapons, VTS_I2 VTS_I2 VTS_R4 VTS_R4)
	ON_EVENT(CPipBoy3000View, IDC_IMAGE_APPAREL, DISPID_MOUSEDOWN, CPipBoy3000View::MouseDownImageApparel, VTS_I2 VTS_I2 VTS_R4 VTS_R4)
	ON_EVENT(CPipBoy3000View, IDC_IMAGE_AID, DISPID_MOUSEDOWN, CPipBoy3000View::MouseDownImageAid, VTS_I2 VTS_I2 VTS_R4 VTS_R4)
END_EVENTSINK_MAP()


void CPipBoy3000View::MouseDownImageApparel(short Button, short Shift, float X, float Y)
{
	// TODO: Add your message handler code here
	m_pSet->MoveFirst();
	category = "Apparel";
	Invalidate();
}

void CPipBoy3000View::MouseDownImageWeapons(short Button, short Shift, float X, float Y)
{
	// TODO: Add your message handler code here
	m_pSet->MoveFirst();
	category = "Weapons";
	Invalidate();
}

void CPipBoy3000View::MouseDownImageAid(short Button, short Shift, float X, float Y)
{
	// TODO: Add your message handler code here
	m_pSet->MoveFirst();
	category = "Aid";
	Invalidate();
}

void CPipBoy3000View::OnBnClickedButtonPickup()
{
	// TODO: Add your control notification handler code here
	CPickUpDialog dlg;

	if (dlg.DoModal() == IDOK) {
		CString itemCategory, itemName;
		int id, quantity = 1;
		double weight;
		BOOL found = false;

		m_pSet->MoveLast();
		id = m_pSet->m_Id + 1;

		if (dlg.m_itemSelection != "") {
			if (dlg.m_itemSelection == "Bathrobe") {
				itemCategory = "Apparel";
				itemName = dlg.m_itemSelection;
				weight = 2;

				m_pSet->MoveFirst();
				while (!m_pSet->IsEOF()) {
					if (m_pSet->m_itemName == CStringA(itemName)) {
						quantity = m_pSet->m_quantity + 1;
						m_pSet->Delete();
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
						found = true;
						break;
					}
					m_pSet->MoveNext();
				}

				if (!found) {
					m_pSet->AddNew();
					m_pSet->m_Id = id;
					m_pSet->m_category = itemCategory;
					m_pSet->m_itemName = itemName;
					m_pSet->m_weight = weight;
					m_pSet->m_quantity = quantity;
					m_pSet->Update();
				}
			}
			if (dlg.m_itemSelection == "Black vest and slacks") {
				itemCategory = "Apparel";
				itemName = dlg.m_itemSelection;
				weight = 3;

				m_pSet->MoveFirst();
				while (!m_pSet->IsEOF()) {
					if (m_pSet->m_itemName == CStringA(itemName)) {
						quantity = m_pSet->m_quantity + 1;
						m_pSet->Delete();
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
						found = true;
						break;
					}
					m_pSet->MoveNext();
				}

				if (!found) {
					m_pSet->AddNew();
					m_pSet->m_Id = id;
					m_pSet->m_category = itemCategory;
					m_pSet->m_itemName = itemName;
					m_pSet->m_weight = weight;
					m_pSet->m_quantity = quantity;
					m_pSet->Update();
				}
			}
			if (dlg.m_itemSelection == "Bomber jacket") {
				itemCategory = "Apparel";
				itemName = dlg.m_itemSelection;
				weight = 2;

				m_pSet->MoveFirst();
				while (!m_pSet->IsEOF()) {
					if (m_pSet->m_itemName == CStringA(itemName)) {
						quantity = m_pSet->m_quantity + 1;
						m_pSet->Delete();
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
						found = true;
						break;
					}
					m_pSet->MoveNext();
				}

				if (!found) {
					m_pSet->AddNew();
					m_pSet->m_Id = id;
					m_pSet->m_category = itemCategory;
					m_pSet->m_itemName = itemName;
					m_pSet->m_weight = weight;
					m_pSet->m_quantity = quantity;
					m_pSet->Update();
				}
			}
			if (dlg.m_itemSelection == "Casual outfit") {
				itemCategory = "Apparel";
				itemName = dlg.m_itemSelection;
				weight = 3;

				m_pSet->MoveFirst();
				while (!m_pSet->IsEOF()) {
					if (m_pSet->m_itemName == CStringA(itemName)) {
						quantity = m_pSet->m_quantity + 1;
						m_pSet->Delete();
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
						found = true;
						break;
					}
					m_pSet->MoveNext();
				}

				if (!found) {
					m_pSet->AddNew();
					m_pSet->m_Id = id;
					m_pSet->m_category = itemCategory;
					m_pSet->m_itemName = itemName;
					m_pSet->m_weight = weight;
					m_pSet->m_quantity = quantity;
					m_pSet->Update();
				}
			}
			if (dlg.m_itemSelection == "Clean black suit") {
				itemCategory = "Apparel";
				itemName = dlg.m_itemSelection;
				weight = 3;

				m_pSet->MoveFirst();
				while (!m_pSet->IsEOF()) {
					if (m_pSet->m_itemName == CStringA(itemName)) {
						quantity = m_pSet->m_quantity + 1;
						m_pSet->Delete();
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
						found = true;
						break;
					}
					m_pSet->MoveNext();
				}

				if (!found) {
					m_pSet->AddNew();
					m_pSet->m_Id = id;
					m_pSet->m_category = itemCategory;
					m_pSet->m_itemName = itemName;
					m_pSet->m_weight = weight;
					m_pSet->m_quantity = quantity;
					m_pSet->Update();
				}
			}
			if (dlg.m_itemSelection == "Postman uniform") {
				itemCategory = "Apparel";
				itemName = dlg.m_itemSelection;
				weight = 3;

				m_pSet->MoveFirst();
				while (!m_pSet->IsEOF()) {
					if (m_pSet->m_itemName == CStringA(itemName)) {
						quantity = m_pSet->m_quantity + 1;
						m_pSet->Delete();
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
						found = true;
						break;
					}
					m_pSet->MoveNext();
				}

				if (!found) {
					m_pSet->AddNew();
					m_pSet->m_Id = id;
					m_pSet->m_category = itemCategory;
					m_pSet->m_itemName = itemName;
					m_pSet->m_weight = weight;
					m_pSet->m_quantity = quantity;
					m_pSet->Update();
				}
			}
			if (dlg.m_itemSelection == "Red dress") {
				itemCategory = "Apparel";
				itemName = dlg.m_itemSelection;
				weight = 1.2;

				m_pSet->MoveFirst();
				while (!m_pSet->IsEOF()) {
					if (m_pSet->m_itemName == CStringA(itemName)) {
						quantity = m_pSet->m_quantity + 1;
						m_pSet->Delete();
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
						found = true;
						break;
					}
					m_pSet->MoveNext();
				}

				if (!found) {
					m_pSet->AddNew();
					m_pSet->m_Id = id;
					m_pSet->m_category = itemCategory;
					m_pSet->m_itemName = itemName;
					m_pSet->m_weight = weight;
					m_pSet->m_quantity = quantity;
					m_pSet->Update();
				}
			}
			if (dlg.m_itemSelection == "Vault-Tec lab coat") {
				itemCategory = "Apparel";
				itemName = dlg.m_itemSelection;
				weight = 2;

				m_pSet->MoveFirst();
				while (!m_pSet->IsEOF()) {
					if (m_pSet->m_itemName == CStringA(itemName)) {
						quantity = m_pSet->m_quantity + 1;
						m_pSet->Delete();
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
						found = true;
						break;
					}
					m_pSet->MoveNext();
				}

				if (!found) {
					m_pSet->AddNew();
					m_pSet->m_Id = id;
					m_pSet->m_category = itemCategory;
					m_pSet->m_itemName = itemName;
					m_pSet->m_weight = weight;
					m_pSet->m_quantity = quantity;
					m_pSet->Update();
				}
			}
			m_pSet->Requery();
			Invalidate();
		}

		else if (dlg.m_weaponsSelection != "") {
			if (dlg.m_weaponsSelection == ".44 pistol") {
				itemCategory = "Weapons";
				itemName = dlg.m_weaponsSelection;
				weight = 5.2;

				m_pSet->MoveFirst();
				while (!m_pSet->IsEOF()) {
					if (m_pSet->m_itemName == CStringA(itemName)) {
						quantity = m_pSet->m_quantity + 1;
						m_pSet->Delete();
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
						found = true;
						break;
					}
					m_pSet->MoveNext();
				}
				if (!found) {
					m_pSet->AddNew();
					m_pSet->m_Id = id;
					m_pSet->m_category = itemCategory;
					m_pSet->m_itemName = itemName;
					m_pSet->m_weight = weight;
					m_pSet->m_quantity = quantity;
					m_pSet->Update();
				}
			}
				if (dlg.m_weaponsSelection == "10mm pistol") {
					itemCategory = "Weapons";
					itemName = dlg.m_weaponsSelection;
					weight = 4.2;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_weaponsSelection == "Pipe pistol") {
					itemCategory = "Weapons";
					itemName = dlg.m_weaponsSelection;
					weight = 2.8;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_weaponsSelection == "Laser pistol") {
					itemCategory = "Weapons";
					itemName = dlg.m_weaponsSelection;
					weight = 3.5;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_weaponsSelection == "Plasma pistol") {
					itemCategory = "Weapons";
					itemName = dlg.m_weaponsSelection;
					weight = 3.9;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_weaponsSelection == "Assault rifle") {
					itemCategory = "Weapons";
					itemName = dlg.m_weaponsSelection;
					weight = 13.1;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_weaponsSelection == "Combat rifle") {
					itemCategory = "Weapons";
					itemName = dlg.m_weaponsSelection;
					weight = 11.1;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_weaponsSelection == "Hunting rifle") {
					itemCategory = "Weapons";
					itemName = dlg.m_weaponsSelection;
					weight = 9.6;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_weaponsSelection == "Spray n' Pray") {
					itemCategory = "Weapons";
					itemName = dlg.m_weaponsSelection;
					weight = 19;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_weaponsSelection == "Shotgun") {
					itemCategory = "Weapons";
					itemName = dlg.m_weaponsSelection;
					weight = 11.1;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_weaponsSelection == "Fat Man") {
					itemCategory = "Weapons";
					itemName = dlg.m_weaponsSelection;
					weight = 30.7;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_weaponsSelection == "Minigun") {
					itemCategory = "Weapons";
					itemName = dlg.m_weaponsSelection;
					weight = 27.4;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_weaponsSelection == "Gauss rifle") {
					itemCategory = "Weapons";
					itemName = dlg.m_weaponsSelection;
					weight = 15.8;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				m_pSet->Requery();
				Invalidate();
			}

			else if (dlg.m_aidSelection != "") {
				if (dlg.m_aidSelection == "Carrot") {
					itemCategory = "Aid";
					itemName = dlg.m_aidSelection;
					weight = 0.1;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_aidSelection == "Corn") {
					itemCategory = "Aid";
					itemName = dlg.m_aidSelection;
					weight = 0.1;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_aidSelection == "Deathclaw steak") {
					itemCategory = "Aid";
					itemName = dlg.m_aidSelection;
					weight = 1;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_aidSelection == "Gourd") {
					itemCategory = "Aid";
					itemName = dlg.m_aidSelection;
					weight = 1;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_aidSelection == "Beer") {
					itemCategory = "Aid";
					itemName = dlg.m_aidSelection;
					weight = 1;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_aidSelection == "Rum") {
					itemCategory = "Aid";
					itemName = dlg.m_aidSelection;
					weight = 1;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_aidSelection == "Nuka Cola") {
					itemCategory = "Aid";
					itemName = dlg.m_aidSelection;
					weight = 1;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_aidSelection == "Nuka Cola Quantum") {
					itemCategory = "Aid";
					itemName = dlg.m_aidSelection;
					weight = 1;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_aidSelection == "Nuka Cherry") {
					itemCategory = "Aid";
					itemName = dlg.m_aidSelection;
					weight = 1;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}if (dlg.m_aidSelection == "Stimpack") {
					itemCategory = "Aid";
					itemName = dlg.m_aidSelection;
					weight = 0.5;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				if (dlg.m_aidSelection == "Stealth Boy") {
					itemCategory = "Aid";
					itemName = dlg.m_aidSelection;
					weight = 1;

					m_pSet->MoveFirst();
					while (!m_pSet->IsEOF()) {
						if (m_pSet->m_itemName == CStringA(itemName)) {
							quantity = m_pSet->m_quantity + 1;
							m_pSet->Delete();
							m_pSet->AddNew();
							m_pSet->m_Id = id;
							m_pSet->m_category = itemCategory;
							m_pSet->m_itemName = itemName;
							m_pSet->m_weight = weight;
							m_pSet->m_quantity = quantity;
							m_pSet->Update();
							found = true;
							break;
						}
						m_pSet->MoveNext();
					}
					if (!found) {
						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = itemName;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
					}
				}
				m_pSet->Requery();
				Invalidate();
			}
		}
	}


	void CPipBoy3000View::OnBnClickedButtonDrop()
	{
		// TODO: Add your control notification handler code here
		CDropItemDialog dlg;

		dlg.m_pSet = m_pSet;
		dlg.category = &category;

		CStringA item, itemCategory;
		int id, quantity;
		double weight;

		if (dlg.DoModal() == IDOK) {
			item = dlg.m_itemSelection;
			m_pSet->MoveFirst();
			while (!m_pSet->IsEOF()) {
				if (m_pSet->m_itemName == item) {
					if (m_pSet->m_quantity <= 1) {
						m_pSet->Delete();
						break;
					}
					else {
						id = m_pSet->m_Id;
						itemCategory = m_pSet->m_category;
						weight = m_pSet->m_weight;
						quantity = m_pSet->m_quantity - 1;
						m_pSet->Delete();

						m_pSet->AddNew();
						m_pSet->m_Id = id;
						m_pSet->m_category = itemCategory;
						m_pSet->m_itemName = item;
						m_pSet->m_weight = weight;
						m_pSet->m_quantity = quantity;
						m_pSet->Update();
						break;
					}
				}
				m_pSet->MoveNext();
			}
			m_pSet->Requery();
			Invalidate();
		}
	}
