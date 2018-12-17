// 0031Doc.h : interface of the CMy0031Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_0031DOC_H__5C693D78_5A22_4E42_B936_2A3350EAD391__INCLUDED_)
#define AFX_0031DOC_H__5C693D78_5A22_4E42_B936_2A3350EAD391__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy0031Doc : public CDocument
{
protected: // create from serialization only
	CMy0031Doc();
	DECLARE_DYNCREATE(CMy0031Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy0031Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy0031Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy0031Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_0031DOC_H__5C693D78_5A22_4E42_B936_2A3350EAD391__INCLUDED_)
