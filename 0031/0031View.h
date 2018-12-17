// 0031View.h : interface of the CMy0031View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_0031VIEW_H__62389B4C_3251_4095_A679_BA33E283FC40__INCLUDED_)
#define AFX_0031VIEW_H__62389B4C_3251_4095_A679_BA33E283FC40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy0031View : public CView
{
protected: // create from serialization only
	CMy0031View();
	DECLARE_DYNCREATE(CMy0031View)

// Attributes
public:
	CMy0031Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy0031View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

	public:
	float z0;
	float y0;
	float x0;
	bool shadowMode;
	float scale;
	float trans;
	int mode;
	float angle;
	int centerY;//xiangduiweizhi
	int centerX;
	float cube[8][4];
// Implementation
public:
	void drawShadow(CDC *dc);
	void ClearScreen();
	void ChangeCube(float change[4][4]);
	virtual ~CMy0031View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy0031View)
	afx_msg void Onxieerce();
	afx_msg void Ontoushi();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void Ontranslate();
	afx_msg void Onscale();
	afx_msg void Onrotatex();
	afx_msg void Onrotatey();
	afx_msg void Onrotatez();
	afx_msg void Ontranslateq();
	afx_msg void Ontranslateh();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 0031View.cpp
inline CMy0031Doc* CMy0031View::GetDocument()
   { return (CMy0031Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_0031VIEW_H__62389B4C_3251_4095_A679_BA33E283FC40__INCLUDED_)
