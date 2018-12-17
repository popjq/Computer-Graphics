// test2View.h : interface of the CTest2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST2VIEW_H__1D4AD665_0838_43B8_B9EA_4D7F2360B4FF__INCLUDED_)
#define AFX_TEST2VIEW_H__1D4AD665_0838_43B8_B9EA_4D7F2360B4FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest2View : public CView
{
protected: // create from serialization only
	CTest2View();
	DECLARE_DYNCREATE(CTest2View)

// Attributes
public:
	CTest2Doc* GetDocument();

// Operations
public:
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest2View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void Onpadding();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test2View.cpp
inline CTest2Doc* CTest2View::GetDocument()
   { return (CTest2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST2VIEW_H__1D4AD665_0838_43B8_B9EA_4D7F2360B4FF__INCLUDED_)
