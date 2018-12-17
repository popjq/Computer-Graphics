// test2View.cpp : implementation of the CTest2View class
//

#include "stdafx.h"
#include "test2.h"

#include "test2Doc.h"
#include "test2View.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CTest2View

IMPLEMENT_DYNCREATE(CTest2View, CView)

BEGIN_MESSAGE_MAP(CTest2View, CView)
	//{{AFX_MSG_MAP(CTest2View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(padding, Onpadding)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest2View construction/destruction

CTest2View::CTest2View()
{
	// TODO: add construction code here

}

CTest2View::~CTest2View()
{
}

BOOL CTest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest2View drawing

void CTest2View::OnDraw(CDC* pDC)
{
	CTest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTest2View printing

BOOL CTest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest2View diagnostics

#ifdef _DEBUG
void CTest2View::AssertValid() const
{
	CView::AssertValid();
}

void CTest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest2Doc* CTest2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest2Doc)));
	return (CTest2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest2View message handlers

int pointCounter=0;                            //����ε������

//�ṹ�壬���ڼ�¼������
struct PointLine
{
	CPoint point;
	PointLine * next;
};

PointLine headpoint;                           //��¼���е�����õ���������λ�ڵ�
PointLine * qLine;
PointLine * pLine;
PointLine * pp;
PointLine * qp;
CPoint pointleft,pointright;

//ѧ�ŵľ���
int studentnumber[14][40]={
	{0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,1,0,0, 0,0,1,1,1,1,1,1,0,0, 0,0,1,1,1,1,1,1,0,0, 0,0,1,1,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,1,0,0, 0,0,1,1,1,1,1,1,0,0, 0,0,1,1,1,1,1,1,0,0, 0,0,1,1,0,0,0,0,0,0},
	{0,0,1,1,0,0,1,1,0,0, 0,0,0,0,0,0,1,1,0,0, 0,0,0,0,0,0,1,1,0,0, 0,0,1,1,0,0,0,0,0,0},
	{0,0,1,1,0,0,1,1,0,0, 0,0,0,0,0,1,1,0,0,0, 0,0,0,0,0,0,1,1,0,0, 0,0,1,1,0,0,0,0,0,0},
	{0,0,1,1,0,0,1,1,0,0, 0,0,0,0,0,1,1,0,0,0, 0,0,1,1,1,1,1,1,0,0, 0,0,1,1,0,0,0,0,0,0},
	{0,0,1,1,0,0,1,1,0,0, 0,0,0,0,0,1,1,0,0,0, 0,0,1,1,1,1,1,1,0,0, 0,0,1,1,0,0,0,0,0,0},
	{0,0,1,1,0,0,1,1,0,0, 0,0,0,0,1,1,0,0,0,0, 0,0,0,0,0,0,1,1,0,0, 0,0,1,1,0,0,0,0,0,0},
	{0,0,1,1,0,0,1,1,0,0, 0,0,0,0,1,1,0,0,0,0, 0,0,0,0,0,0,1,1,0,0, 0,0,1,1,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,1,0,0, 0,0,0,0,1,1,0,0,0,0, 0,0,1,1,1,1,1,1,0,0, 0,0,1,1,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,1,0,0, 0,0,0,0,1,1,0,0,0,0, 0,0,1,1,1,1,1,1,0,0, 0,0,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0},
};


void CTest2View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    //�����ǰ������Ϊ0�����¼������
	if(pointCounter==0)
	{
		headpoint.point=point;
		headpoint.next=NULL;
		pointCounter++;
	}
	//�����������1������л���
	if(pointCounter>0)
	{
		pLine=&headpoint;                                 //�ҵ����е���󵥻��������ĵ�
		while(pLine->next!=NULL)
		{
			pLine=pLine->next;
		}
        qLine=new PointLine();
		qLine->point=point;
		qLine->next=NULL;
		pLine->next=qLine;
		CClientDC dc(this);
		dc.MoveTo((pLine->point));
		dc.LineTo(qLine->point);
		pointCounter++;                                   //��������һ
	}
	CView::OnLButtonDown(nFlags, point);
}

void CTest2View::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CView::OnLButtonDblClk(nFlags, point);
	//ʵ����β����
	CClientDC dc(this);
	dc.MoveTo(headpoint.point);
	pLine=headpoint.next;
	while(pLine->next!=NULL)
	{
		pLine=pLine->next;
	}
	dc.LineTo(pLine->point);
}

void CTest2View::Onpadding() 
{
	// TODO: Add your command handler code here
	int xmax,xmin,ymax,ymin,xc,yc,a,b;


	//�ҵ������������С����
	xmax=headpoint.point.x;
	xmin=headpoint.point.x;
	ymax=headpoint.point.y;
	ymin=headpoint.point.y;
	pLine=headpoint.next;
	while(pLine->next!=NULL)
	{
		if(pLine->point.x<xmin)
			xmin=pLine->point.x;
		if(pLine->point.x>xmax)
			xmax=pLine->point.x;
		if(pLine->point.y<ymin)
			ymin=pLine->point.y;
		if(pLine->point.y>ymax)
			ymax=pLine->point.y;
		pLine=pLine->next;
	}
	if(pLine->point.x<xmin)
		xmin=pLine->point.x;
	if(pLine->point.x>xmax)
		xmax=pLine->point.x;
	if(pLine->point.y<ymin)
		ymin=pLine->point.y;
	if(pLine->point.y>ymax)
		ymax=pLine->point.y;


	//����С����ȫ�����ѧ�ţ���������ε��߱���
    CClientDC dc(this);
	for(xc=xmin;xc<=xmax;xc++)
	{
		for(yc=ymin;yc<=ymax;yc++)
		{
			a=xc%40;
			b=yc%14;
			if(studentnumber[b][a]==1&&dc.GetPixel(xc,yc)!=RGB(0,0,0))
				dc.SetPixel(xc,yc,RGB(0,0,128));
		}
	}

	int type=0;

	//�����ң����ϵ��£����������߶��ಿ�ֲ���
	int x=xmin,y=ymin;
	while(y<=ymax)
	{
		type=0;
		x=xmin;
		while(x<=xmax)
		{
			if(type==0&&dc.GetPixel(x,y)!=RGB(0,0,0))
				dc.SetPixel(x,y,RGB(255,255,255));
			if(dc.GetPixel(x,y)==RGB(0,0,0)&&type==0&&dc.GetPixel(x-1,y)!=(0,0,0))
			{
				type=1;
				x++;
			}
			if(dc.GetPixel(x,y)==RGB(0,0,0)&&type==1&&dc.GetPixel(x-1,y)!=(0,0,0))
			{
				type=0;
				x++;
			}
			x++;
		}
		y++;
	}

	//���ҵ��󣬴��ϵ��£���������ұ߶���Ĳ��ֲ���
	x=xmax,y=ymin;
	while(y<=ymax)
	{
		type=0;
		x=xmax;
		while(x>=xmin)
		{
			if(type==0&&dc.GetPixel(x,y)!=RGB(0,0,0))
				dc.SetPixel(x,y,RGB(255,255,255));
			if(dc.GetPixel(x,y)==RGB(0,0,0)&&type==0&&dc.GetPixel(x+1,y)!=(0,0,0))
			{
				type=1;
				x--;
			}
			if(dc.GetPixel(x,y)==RGB(0,0,0)&&type==1&&dc.GetPixel(x+1,y)!=(0,0,0))
			{
				type=0;
				x--;
			}
			x--;
		}
		y++;
	}


    //�ͷ��ڴ棬�������Ķ���εĵ��ͷ�
	pLine=headpoint.next;
	headpoint.next=NULL;
	headpoint.point=(0,0);
	pointCounter=0;
	delete(pLine);

	
}
