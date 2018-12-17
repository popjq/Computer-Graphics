#if !defined(AFX_SHDLG_H__80577E39_83A8_4AF1_9808_50736B3B3281__INCLUDED_)
#define AFX_SHDLG_H__80577E39_83A8_4AF1_9808_50736B3B3281__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// shdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// shdlg dialog

class shdlg : public CDialog
{
// Construction
public:
	shdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(shdlg)
	enum { IDD = IDD_DIALOG1 };
	int		m_x;
	int		m_y;
	int		m_z;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(shdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(shdlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHDLG_H__80577E39_83A8_4AF1_9808_50736B3B3281__INCLUDED_)
