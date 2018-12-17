// 0031Doc.cpp : implementation of the CMy0031Doc class
//

#include "stdafx.h"
#include "0031.h"

#include "0031Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy0031Doc

IMPLEMENT_DYNCREATE(CMy0031Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy0031Doc, CDocument)
	//{{AFX_MSG_MAP(CMy0031Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy0031Doc construction/destruction

CMy0031Doc::CMy0031Doc()
{
	// TODO: add one-time construction code here

}

CMy0031Doc::~CMy0031Doc()
{
}

BOOL CMy0031Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMy0031Doc serialization

void CMy0031Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMy0031Doc diagnostics

#ifdef _DEBUG
void CMy0031Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy0031Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy0031Doc commands
