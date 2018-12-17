// shdlg.cpp : implementation file
//

#include "stdafx.h"
#include "0031.h"
#include "shdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// shdlg dialog


shdlg::shdlg(CWnd* pParent /*=NULL*/)
	: CDialog(shdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(shdlg)
	m_x = 0;
	m_y = 0;
	m_z = 0;
	//}}AFX_DATA_INIT
}


void shdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(shdlg)
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDX_Text(pDX, IDC_EDIT2, m_y);
	DDX_Text(pDX, IDC_EDIT3, m_z);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(shdlg, CDialog)
	//{{AFX_MSG_MAP(shdlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// shdlg message handlers
