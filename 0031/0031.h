// 0031.h : main header file for the 0031 application
//

#if !defined(AFX_0031_H__B3F69A4F_5FCF_4CDF_AF15_DD240EFC7284__INCLUDED_)
#define AFX_0031_H__B3F69A4F_5FCF_4CDF_AF15_DD240EFC7284__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy0031App:
// See 0031.cpp for the implementation of this class
//

class CMy0031App : public CWinApp
{
public:
	CMy0031App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy0031App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMy0031App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_0031_H__B3F69A4F_5FCF_4CDF_AF15_DD240EFC7284__INCLUDED_)
