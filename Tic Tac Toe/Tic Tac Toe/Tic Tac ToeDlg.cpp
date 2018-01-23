
// Tic Tac ToeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Tic Tac Toe.h"
#include "Tic Tac ToeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTicTacToeDlg dialog



CTicTacToeDlg::CTicTacToeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TICTACTOE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTicTacToeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTicTacToeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_TOPLEFT, &CTicTacToeDlg::OnBnClickedTopleft)
	ON_BN_CLICKED(ID_RESET, &CTicTacToeDlg::OnBnClickedReset)
	ON_BN_CLICKED(ID_TOPMIDDLE, &CTicTacToeDlg::OnBnClickedTopmiddle)
	ON_BN_CLICKED(ID_TOPRIGHT, &CTicTacToeDlg::OnBnClickedTopright)
	ON_BN_CLICKED(ID_MIDDLELEFT, &CTicTacToeDlg::OnBnClickedMiddleleft)
	ON_BN_CLICKED(ID_CENTER, &CTicTacToeDlg::OnBnClickedCenter)
	ON_BN_CLICKED(ID_MIDDLERIGHT, &CTicTacToeDlg::OnBnClickedMiddleright)
	ON_BN_CLICKED(ID_BOTTOMLEFT, &CTicTacToeDlg::OnBnClickedBottomleft)
	ON_BN_CLICKED(ID_BOTTOMMIDDLE, &CTicTacToeDlg::OnBnClickedBottommiddle)
	ON_BN_CLICKED(ID_BOTTOMRIGHT, &CTicTacToeDlg::OnBnClickedBottomright)
END_MESSAGE_MAP()


// CTicTacToeDlg message handlers

BOOL CTicTacToeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//Initialize the "notification dialog" to say that X goes first
	GetDlgItem(ID_TURN)->SetWindowTextW(CString("X, you go first!"));
	GetDlgItem(ID_TURN)->EnableWindow(false);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTicTacToeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTicTacToeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTicTacToeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL turn = 0;
BOOL winner = 0;
int moves = 8;
char board[3][3];

void CTicTacToeDlg::OnBnClickedTopleft()
{
	// TODO: Add your control notification handler code here
	//if turn == 0, it is X's turn
	if (!turn) {
		//When it is X's turn and the top left button is clicked, make that button an X and disable it
		GetDlgItem(ID_TOPLEFT)->SetWindowTextW(CString("X"));
		GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
		//add an X to the corresponding location in the board array
		board[0][0] = 'X';
		//notify that it is now O's turn if there is no winner
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("O's turn"));

		//check if any combination of places on the board including the one just clicked are Xs
		if (board[0][0] == 'X' && (board[0][0] == board[0][1] && board[0][1] == board[0][2]) || (board[0][0] == board[1][0] && board[1][0] == board[2][0]) || (board[0][0] == board[1][1] && board[1][1] == board[2][2])) {
			//if X has three in a row, give a notification and disable the board
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("X wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}
	else {
		//When it is O's turn and the top left button is clicked, make that button an O and disable it
		GetDlgItem(ID_TOPLEFT)->SetWindowTextW(CString("O"));
		GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
		//add an O to the corresponding location in the board array
		board[0][0] = 'O';
		//notify that it is now X's turn if there is no winner
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("X's turn"));

		//check if any combination of places on the board including the one just clicked are Os
		if (board[0][0] == 'O' && (board[0][0] == board[0][1] && board[0][1] == board[0][2]) || (board[0][0] == board[1][0] && board[1][0] == board[2][0]) || (board[0][0] == board[1][1] && board[1][1] == board[2][2])) {
			//if O has three in a row, give a notification and disable the board
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("O wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}

	//if the board has no empty spaces and there is no winner yet, declare a tie
	if (moves <= 0 && !winner)
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("It's a tie!"));

	//switch turns
	turn = !turn;
	moves--;
}

void CTicTacToeDlg::OnBnClickedTopmiddle()
{
	// TODO: Add your control notification handler code here
	if (!turn) {
		GetDlgItem(ID_TOPMIDDLE)->SetWindowTextW(CString("X"));
		GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
		board[0][1] = 'X';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("O's turn"));


		if (board[0][1] == 'X' && (board[0][0] == board[0][1] && board[0][1] == board[0][2]) || (board[0][1] == board[1][1] && board[1][1] == board[2][1])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("X wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}
	else {
		GetDlgItem(ID_TOPMIDDLE)->SetWindowTextW(CString("O"));
		GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
		board[0][1] = 'O';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("X's turn"));

		if (board[0][1] == 'O' && (board[0][0] == board[0][1] && board[0][1] == board[0][2]) || (board[0][1] == board[1][1] && board[1][1] == board[2][1])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("O wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}

	if (moves <= 0 && !winner)
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("It's a tie!"));

	turn = !turn;
	moves--;
}


void CTicTacToeDlg::OnBnClickedTopright()
{
	// TODO: Add your control notification handler code here
	if (!turn) {
		GetDlgItem(ID_TOPRIGHT)->SetWindowTextW(CString("X"));
		GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
		board[0][2] = 'X';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("O's turn"));


		if (board[0][2] == 'X' && (board[0][0] == board[0][1] && board[0][1] == board[0][2]) || (board[0][2] == board[1][2] && board[1][2] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("X wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}
	else {
		GetDlgItem(ID_TOPRIGHT)->SetWindowTextW(CString("O"));
		GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
		board[0][2] = 'O';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("X's turn"));

		if (board[0][2] == 'O' && (board[0][0] == board[0][1] && board[0][1] == board[0][2]) || (board[0][2] == board[1][2] && board[1][2] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("O wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}

	if (moves <= 0 && !winner)
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("It's a tie!"));

	turn = !turn;
	moves--;
}


void CTicTacToeDlg::OnBnClickedMiddleleft()
{
	// TODO: Add your control notification handler code here
	if (!turn) {
		GetDlgItem(ID_MIDDLELEFT)->SetWindowTextW(CString("X"));
		GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
		board[1][0] = 'X';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("O's turn"));


		if (board[1][0] == 'X' && (board[1][0] == board[1][1] && board[1][1] == board[1][2]) || (board[0][0] == board[1][0] && board[1][0] == board[2][0])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("X wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}
	else {
		GetDlgItem(ID_MIDDLELEFT)->SetWindowTextW(CString("O"));
		GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
		board[1][0] = 'O';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("X's turn"));

		if (board[1][0] == 'O' && (board[1][0] == board[1][1] && board[1][1] == board[1][2]) || (board[0][0] == board[1][0] && board[1][0] == board[2][0])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("O wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}

	if (moves <= 0 && !winner)
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("It's a tie!"));

	turn = !turn;
	moves--;
}


void CTicTacToeDlg::OnBnClickedCenter()
{
	// TODO: Add your control notification handler code here
	if (!turn) {
		GetDlgItem(ID_CENTER)->SetWindowTextW(CString("X"));
		GetDlgItem(ID_CENTER)->EnableWindow(false);
		board[1][1] = 'X';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("O's turn"));


		if (board[1][1] == 'X' && (board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]) || (board[1][0] == board[1][1] && board[1][1] == board[1][2]) || (board[0][1] == board[1][1] && board[1][1] == board[2][1])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("X wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}
	else {
		GetDlgItem(ID_CENTER)->SetWindowTextW(CString("O"));
		GetDlgItem(ID_CENTER)->EnableWindow(false);
		board[1][1] = 'O';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("X's turn"));

		if (board[1][1] == 'O' && (board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]) || (board[1][0] == board[1][1] && board[1][1] == board[1][2]) || (board[0][1] == board[1][1] && board[1][1] == board[2][1])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("O wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}

	if (moves <= 0 && !winner)
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("It's a tie!"));

	turn = !turn;
	moves--;
}


void CTicTacToeDlg::OnBnClickedMiddleright()
{
	// TODO: Add your control notification handler code here
	if (!turn) {
		GetDlgItem(ID_MIDDLERIGHT)->SetWindowTextW(CString("X"));
		GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
		board[1][2] = 'X';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("O's turn"));


		if (board[1][2] == 'X' && (board[1][0] == board[1][1] && board[1][1] == board[1][2]) || (board[0][2] == board[1][2] && board[1][2] == board[2][2])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("X wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}
	else {
		GetDlgItem(ID_MIDDLERIGHT)->SetWindowTextW(CString("O"));
		GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
		board[1][2] = 'O';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("X's turn"));

		if (board[1][2] == 'O' && (board[1][0] == board[1][1] && board[1][1] == board[1][2]) || (board[0][2] == board[1][2] && board[1][2] == board[2][2])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("O wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}

	if (moves <= 0 && !winner)
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("It's a tie!"));

	turn = !turn;
	moves--;
}


void CTicTacToeDlg::OnBnClickedBottomleft()
{
	// TODO: Add your control notification handler code here
	if (!turn) {
		GetDlgItem(ID_BOTTOMLEFT)->SetWindowTextW(CString("X"));
		GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
		board[2][0] = 'X';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("O's turn"));


		if (board[2][0] == 'X' && (board[2][0] == board[2][1] && board[2][1] == board[2][2]) || (board[0][0] == board[1][0] && board[1][0] == board[2][0]) || (board[2][0] == board[1][1] && board[1][1] == board[0][2])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("X wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}
	else {
		GetDlgItem(ID_BOTTOMLEFT)->SetWindowTextW(CString("O"));
		GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
		board[2][0] = 'O';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("X's turn"));

		if (board[2][0] == 'O' && (board[2][0] == board[2][1] && board[2][1] == board[2][2]) || (board[0][0] == board[1][0] && board[1][0] == board[2][0]) || (board[2][0] == board[1][1] && board[1][1] == board[0][2])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("O wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}

	if (moves <= 0 && !winner)
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("It's a tie!"));

	turn = !turn;
	moves--;
}


void CTicTacToeDlg::OnBnClickedBottommiddle()
{
	// TODO: Add your control notification handler code here
	if (!turn) {
		GetDlgItem(ID_BOTTOMMIDDLE)->SetWindowTextW(CString("X"));
		GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
		board[2][1] = 'X';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("O's turn"));


		if (board[2][1] == 'X' && (board[2][0] == board[2][1] && board[2][1] == board[2][2]) || (board[0][1] == board[1][1] && board[1][1] == board[2][1])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("X wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}
	else {
		GetDlgItem(ID_BOTTOMMIDDLE)->SetWindowTextW(CString("O"));
		GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
		board[2][1] = 'O';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("X's turn"));

		if (board[2][1] == 'O' && (board[2][0] == board[2][1] && board[2][1] == board[2][2]) || (board[0][1] == board[1][1] && board[1][1] == board[2][1])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("O wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}

	if (moves <= 0 && !winner)
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("It's a tie!"));

	turn = !turn;
	moves--;
}


void CTicTacToeDlg::OnBnClickedBottomright()
{
	// TODO: Add your control notification handler code here
	if (!turn) {
		GetDlgItem(ID_BOTTOMRIGHT)->SetWindowTextW(CString("X"));
		GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
		board[2][2] = 'X';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("O's turn"));


		if (board[2][2] == 'X' && (board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[2][0] == board[2][1] && board[2][1] == board[2][2]) || (board[0][2] == board[1][2] && board[1][2] == board[2][2])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("X wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}
	else {
		GetDlgItem(ID_BOTTOMRIGHT)->SetWindowTextW(CString("O"));
		GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
		board[2][2] = 'O';
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("X's turn"));

		if (board[2][2] == 'O' && (board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[2][0] == board[2][1] && board[2][1] == board[2][2]) || (board[0][2] == board[1][2] && board[1][2] == board[2][2])) {
			GetDlgItem(ID_TURN)->SetWindowTextW(CString("O wins!"));
			GetDlgItem(ID_TOPLEFT)->EnableWindow(false);
			GetDlgItem(ID_TOPMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_TOPRIGHT)->EnableWindow(false);
			GetDlgItem(ID_MIDDLELEFT)->EnableWindow(false);
			GetDlgItem(ID_CENTER)->EnableWindow(false);
			GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(false);
			GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(false);
			winner = true;
		}
	}

	if (moves <= 0 && !winner)
		GetDlgItem(ID_TURN)->SetWindowTextW(CString("It's a tie!"));

	turn = !turn;
	moves--;
}

void CTicTacToeDlg::OnBnClickedReset()
{
	// TODO: Add your control notification handler code here
	//reset the board, including the starting turn and number of open spaces on the board
	turn = 0;
	moves = 8;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = '-';
		}
	}

	//reset all the buttons and enable them again
	GetDlgItem(ID_TOPLEFT)->SetWindowTextW(CString("-"));
	GetDlgItem(ID_TOPLEFT)->EnableWindow(true);

	GetDlgItem(ID_TOPMIDDLE)->SetWindowTextW(CString("-"));
	GetDlgItem(ID_TOPMIDDLE)->EnableWindow(true);

	GetDlgItem(ID_TOPRIGHT)->SetWindowTextW(CString("-"));
	GetDlgItem(ID_TOPRIGHT)->EnableWindow(true);

	GetDlgItem(ID_MIDDLELEFT)->SetWindowTextW(CString("-"));
	GetDlgItem(ID_MIDDLELEFT)->EnableWindow(true);

	GetDlgItem(ID_CENTER)->SetWindowTextW(CString("-"));
	GetDlgItem(ID_CENTER)->EnableWindow(true);

	GetDlgItem(ID_MIDDLERIGHT)->SetWindowTextW(CString("-"));
	GetDlgItem(ID_MIDDLERIGHT)->EnableWindow(true);

	GetDlgItem(ID_BOTTOMLEFT)->SetWindowTextW(CString("-"));
	GetDlgItem(ID_BOTTOMLEFT)->EnableWindow(true);

	GetDlgItem(ID_BOTTOMMIDDLE)->SetWindowTextW(CString("-"));
	GetDlgItem(ID_BOTTOMMIDDLE)->EnableWindow(true);

	GetDlgItem(ID_BOTTOMRIGHT)->SetWindowTextW(CString("-"));
	GetDlgItem(ID_BOTTOMRIGHT)->EnableWindow(true);

	GetDlgItem(ID_TURN)->SetWindowTextW(CString("X, you go first!"));
}
