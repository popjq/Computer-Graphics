// 0031View.cpp : implementation of the CMy0031View class
//

#include "stdafx.h"
#include "0031.h"

#include"shdlg.h"

#include "0031Doc.h"
#include "0031View.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy0031View

IMPLEMENT_DYNCREATE(CMy0031View, CView)

BEGIN_MESSAGE_MAP(CMy0031View, CView)
	//{{AFX_MSG_MAP(CMy0031View)
	ON_COMMAND(ID_xieerce, Onxieerce)
	ON_COMMAND(ID_toushi, Ontoushi)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_translate, Ontranslate)
	ON_COMMAND(ID_scale, Onscale)
	ON_COMMAND(ID_rotatex, Onrotatex)
	ON_COMMAND(ID_rotatey, Onrotatey)
	ON_COMMAND(rotatez, Onrotatez)
	ON_COMMAND(ID_translateq, Ontranslateq)
	ON_COMMAND(ID_translateh, Ontranslateh)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy0031View construction/destruction

CMy0031View::CMy0031View()
{
	// TODO: add construction code here
	centerX = 200;
	centerY = 200;

	shadowMode = false;
	angle = 0.1;
	mode = 1;
	trans = 5;
	scale = 1.1;

	cube[0][0] = 0;//qicizuobiao
	cube[0][1] = 0;
	cube[0][2] = 50;
	cube[0][3] = 1;

	cube[1][0] = 0;
	cube[1][1] = 0;
	cube[1][2] = 100;
	cube[1][3] = 1;

	cube[2][0] = 0;
	cube[2][1] = 50;
	cube[2][2] = 50;
	cube[2][3] = 1;

	cube[3][0] = 0;
	cube[3][1] = 50;
	cube[3][2] = 100;
	cube[3][3] = 1;

	cube[4][0] = 50;
	cube[4][1] = 0;
	cube[4][2] = 50;
	cube[4][3] = 1;

	cube[5][0] = 50;
	cube[5][1] = 0;
	cube[5][2] = 100;
	cube[5][3] = 1;

	cube[6][0] = 50;
	cube[6][1] = 50;
	cube[6][2] = 50;
	cube[6][3] = 1;

	cube[7][0] = 50;
	cube[7][1] = 50;
	cube[7][2] = 100;
	cube[7][3] = 1;
}

CMy0031View::~CMy0031View()
{
}

BOOL CMy0031View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy0031View drawing

void CMy0031View::OnDraw(CDC* pDC)
{
	CMy0031Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	drawShadow(pDC);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMy0031View printing

BOOL CMy0031View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy0031View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy0031View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy0031View diagnostics

#ifdef _DEBUG
void CMy0031View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0031View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0031Doc* CMy0031View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0031Doc)));
	return (CMy0031Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy0031View message handlers

void CMy0031View::ChangeCube(float change[4][4])
{
	float result[8][4];
	float num = 0;
	for(int i = 0;i<8;i++)
	{
		for(int j =0;j<4;j++)
		{
			for(int k = 0;k<4;k++)
			{
				num += cube[i][k] * change[j][k];
			}
			result[i][j] = num;						    
			num = 0;
		}
	}

	for(int a = 0;a<8;a++)
	{
		for(int b = 0;b<4;b++)
		{
			cube[a][b] = result[a][b];
		}
	}
}

void CMy0031View::Onxieerce() 
{
	// TODO: Add your command handler code here
//ClearScreen();
 shadowMode=false;
/*	CClientDC dc(this);
	float a,b;
	a= b = 0.5;
	float d = -z0;
	float l= 2/sqrt(3);
double Alpha = 20;	
	Alpha *= 3.1415926/180;
	double c = cos(Alpha);
	double s = sin(Alpha);
float mat1[4][4] =    {1,0,l*c,0,
					   0,1,l*s,0,
					   0,0,0,0,
					   0,0,0,1};		


	float result[8][4];
	float num = 0;
		for(int i = 0;i<8;i++)
		{
			for(int j =0;j<4;j++)
			{
				for(int k = 0;k<4;k++)
				{
						num += cube[i][k] * mat1[j][k];
				}
				result[i][j] = num;						    
				num = 0;
			}
		}
    dc.MoveTo(centerX + result[0][0],centerY + result[0][1]);			//按照立体图上的相连关系，在平面投影上把他们连接起来。 只关注x,y坐标
	dc.LineTo(centerX + result[1][0],centerY + result[1][1]);
	
	dc.MoveTo(centerX + result[0][0],centerY + result[0][1]);
	dc.LineTo(centerX + result[2][0],centerY + result[2][1]);

	dc.MoveTo(centerX + result[0][0],centerY + result[0][1]);
	dc.LineTo(centerX + result[4][0],centerY + result[4][1]);

	dc.MoveTo(centerX + result[7][0],centerY + result[7][1]);
	dc.LineTo(centerX + result[3][0],centerY + result[3][1]);

	dc.MoveTo(centerX + result[7][0],centerY + result[7][1]);
	dc.LineTo(centerX + result[5][0],centerY + result[5][1]);

	dc.MoveTo(centerX + result[7][0],centerY + result[7][1]);
	dc.LineTo(centerX + result[6][0],centerY + result[6][1]);

	dc.MoveTo(centerX + result[2][0],centerY + result[2][1]);
	dc.LineTo(centerX + result[3][0],centerY + result[3][1]);

	dc.MoveTo(centerX + result[2][0],centerY + result[2][1]);
	dc.LineTo(centerX + result[6][0],centerY + result[6][1]);

	dc.MoveTo(centerX + result[1][0],centerY + result[1][1]);
	dc.LineTo(centerX + result[3][0],centerY + result[3][1]);

	dc.MoveTo(centerX + result[1][0],centerY + result[1][1]);
	dc.LineTo(centerX + result[5][0],centerY + result[5][1]);

	dc.MoveTo(centerX + result[4][0],centerY + result[4][1]);
	dc.LineTo(centerX + result[5][0],centerY + result[5][1]);

	dc.MoveTo(centerX + result[4][0],centerY + result[4][1]);
	dc.LineTo(centerX + result[6][0],centerY + result[6][1]);	*/
}

void CMy0031View::Ontoushi() 
{
	// TODO: Add your command handler code here
/*ClearScreen();
	float mat2[4][4] = {1,0,-x0/z0,0,
					   0,1,-y0/z0,0,
					   0,0,0,0,
					   0,0,-1/z0,1};	
	float result[8][4];*/
	shadowMode = true;
//	float num=0;
shdlg dlg;
		if(dlg.DoModal() == IDOK)
	{
		x0 = dlg.m_x;
		y0 = dlg.m_y;
		z0 = dlg.m_z;
	}
/*for(int i = 0;i<8;i++)
		{
			for(int j =0;j<4;j++)
			{
				for(int k = 0;k<4;k++)
				{
						num += cube[i][k] * mat2[j][k];
				}
				result[i][j] = num;						    
				num = 0;
			}
		}
	CClientDC dc(this);
  dc.MoveTo(centerX + result[0][0],centerY + result[0][1]);			//按照立体图上的相连关系，在平面投影上把他们连接起来。 只关注x,y坐标
	dc.LineTo(centerX + result[1][0],centerY + result[1][1]);
	
	dc.MoveTo(centerX + result[0][0],centerY + result[0][1]);
	dc.LineTo(centerX + result[2][0],centerY + result[2][1]);

	dc.MoveTo(centerX + result[0][0],centerY + result[0][1]);
	dc.LineTo(centerX + result[4][0],centerY + result[4][1]);

	dc.MoveTo(centerX + result[7][0],centerY + result[7][1]);
	dc.LineTo(centerX + result[3][0],centerY + result[3][1]);

	dc.MoveTo(centerX + result[7][0],centerY + result[7][1]);
	dc.LineTo(centerX + result[5][0],centerY + result[5][1]);

	dc.MoveTo(centerX + result[7][0],centerY + result[7][1]);
	dc.LineTo(centerX + result[6][0],centerY + result[6][1]);

	dc.MoveTo(centerX + result[2][0],centerY + result[2][1]);
	dc.LineTo(centerX + result[3][0],centerY + result[3][1]);

	dc.MoveTo(centerX + result[2][0],centerY + result[2][1]);
	dc.LineTo(centerX + result[6][0],centerY + result[6][1]);

	dc.MoveTo(centerX + result[1][0],centerY + result[1][1]);
	dc.LineTo(centerX + result[3][0],centerY + result[3][1]);

	dc.MoveTo(centerX + result[1][0],centerY + result[1][1]);
	dc.LineTo(centerX + result[5][0],centerY + result[5][1]);

	dc.MoveTo(centerX + result[4][0],centerY + result[4][1]);
	dc.LineTo(centerX + result[5][0],centerY + result[5][1]);

	dc.MoveTo(centerX + result[4][0],centerY + result[4][1]);
	dc.LineTo(centerX + result[6][0],centerY + result[6][1]);	*/
}

void CMy0031View::ClearScreen()
{
	CClientDC dc(this);	
	CRect window; 
	GetClientRect(window);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	dc.Rectangle(window);
}

void CMy0031View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	trans=2;
	// TODO: Add your message handler code here and/or call default
		if(mode == 1)
	{
		float mat[4][4] = {1,0,0,0,
						   0,1,0,0,
					       0,0,1,0,
						   0,0,0,1};
		switch(nChar)
		{
		   case VK_LEFT:	 mat[0][3] = -trans;  break;		    
		   case VK_RIGHT:	 mat[0][3] = trans;  break;				
		   case VK_UP:	     mat[1][3] = -trans;  break;			
		   case VK_DOWN:	 mat[1][3] = trans;  break;
		   case VK_ESCAPE:	     mat[2][3] = -trans;  break;
		   case VK_RETURN :       mat[2][3] = trans;  break;
		}
		
		ChangeCube(mat);
	}
	else if(mode == 3)
	{
		float mat[4][4] = {1,0,0,0,
						   0,1,0,0,
					       0,0,1,0,
						   0,0,0,1};
		if(nChar == VK_LEFT)
		{
			mat[0][0] = mat[1][1] = mat[2][2] = scale;
		}
		else if(nChar == VK_RIGHT)
		{
			mat[0][0] = mat[1][1] = mat[2][2] = 2 - scale;
		} 
		ChangeCube(mat);
	}
	else
	{
		float mat1[4][4] = {1,0,0,0,
						   0,1,0,0,
					       0,0,1,0,
						   0,0,0,1};
		float mat2[4][4] = {1,0,0,0,
						   0,1,0,0,
					       0,0,1,0,
						   0,0,0,1};
		float sina = sin(angle);
		float cosa = cos(angle);
		switch(mode)
		{
		case 21:mat1[1][1] = cosa;
				mat1[1][2] = sina;
				mat1[2][1] = -sina;
				mat1[2][2] = cosa;
				break;
		case 22:mat1[0][0] = cosa;
				mat1[0][2] = -sina;
				mat1[2][0] = sina;
				mat1[2][2] = cosa;
				break;
		case 23:mat1[0][0] = cosa;
				mat1[0][1] = sina;
				mat1[1][0] = -sina;
				mat1[1][1] = cosa;
				break;
		}
		ChangeCube(mat1);
	}


	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CMy0031View::Ontranslate() 
{
	// TODO: Add your command handler code here
	mode = 1;	
}

void CMy0031View::drawShadow(CDC *dc)
{
	float a,b;
	a= b = 0.5;
	float d=z0;
	float l= 0.5;
double Alpha = 20;	

	Alpha *= 3.1415926/180;
	double c = cos(Alpha);
	double s = sin(Alpha);
float mat1[4][4] =    {1,0,l*c,0,
					   0,1,l*s,0,
					   0,0,0,0,
					   0,0,0,1};		
	float mat2[4][4] = {1,0,x0/d,0,
					   0,1,y0/d,0,
					   0,0,0,0,
					   0,0,1/d,1};			//单点透视关于x0,y0,z0变换矩阵
	float result[8][4];
	float num = 0;
	if(!shadowMode)
	{
		for(int i = 0;i<8;i++)
		{
			for(int j =0;j<4;j++)
			{
				for(int k = 0;k<4;k++)
				{
						num += cube[i][k] * mat1[j][k];
				}
				result[i][j] = num;						    
				num = 0;
			}
		}
	}
	else
	{
		for(int i = 0;i<8;i++)
		{
			result[i][0] = x0 + (cube[i][0] - x0) * (-z0)/(cube[i][2]-z0);
			result[i][1] = y0 + (cube[i][1] - y0) * (-z0)/(cube[i][2]-z0);
			result[i][2] = 0;
			result[i][3] = 1;
		}
	}

    dc->MoveTo(centerX + result[0][0],centerY + result[0][1]);			//按照立体图上的相连关系，在平面投影上把他们连接起来。 只关注x,y坐标
	dc->LineTo(centerX + result[1][0],centerY + result[1][1]);
	
	dc->MoveTo(centerX + result[0][0],centerY + result[0][1]);
	dc->LineTo(centerX + result[2][0],centerY + result[2][1]);

	dc->MoveTo(centerX + result[0][0],centerY + result[0][1]);
	dc->LineTo(centerX + result[4][0],centerY + result[4][1]);

	dc->MoveTo(centerX + result[7][0],centerY + result[7][1]);
	dc->LineTo(centerX + result[3][0],centerY + result[3][1]);

	dc->MoveTo(centerX + result[7][0],centerY + result[7][1]);
	dc->LineTo(centerX + result[5][0],centerY + result[5][1]);

	dc->MoveTo(centerX + result[7][0],centerY + result[7][1]);
	dc->LineTo(centerX + result[6][0],centerY + result[6][1]);

	dc->MoveTo(centerX + result[2][0],centerY + result[2][1]);
	dc->LineTo(centerX + result[3][0],centerY + result[3][1]);

	dc->MoveTo(centerX + result[2][0],centerY + result[2][1]);
	dc->LineTo(centerX + result[6][0],centerY + result[6][1]);

	dc->MoveTo(centerX + result[1][0],centerY + result[1][1]);
	dc->LineTo(centerX + result[3][0],centerY + result[3][1]);

	dc->MoveTo(centerX + result[1][0],centerY + result[1][1]);
	dc->LineTo(centerX + result[5][0],centerY + result[5][1]);

	dc->MoveTo(centerX + result[4][0],centerY + result[4][1]);
	dc->LineTo(centerX + result[5][0],centerY + result[5][1]);

	dc->MoveTo(centerX + result[4][0],centerY + result[4][1]);
	dc->LineTo(centerX + result[6][0],centerY + result[6][1]);
}

void CMy0031View::Onscale() 
{
	// TODO: Add your command handler code here
	mode=3;
}

void CMy0031View::Onrotatex() 
{
	// TODO: Add your command handler code here
	mode = 21;	
}

void CMy0031View::Onrotatey() 
{
	// TODO: Add your command handler code here
mode=22;	
}

void CMy0031View::Onrotatez() 
{
	// TODO: Add your command handler code here
mode=23;	
}

void CMy0031View::Ontranslateq() 
{
	// TODO: Add your command handler code here
mode=4;	
}

void CMy0031View::Ontranslateh() 
{
	// TODO: Add your command handler code here
mode=5;	
}

void CMy0031View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);	
	float d=z0;
float mat[4][4] =        {1,0,0,0,
						   0,1,0,0,
					       0,0,1,0,
						   0,0,0,1};
	float mat2[4][4] = {1,0,x0/d,0,
					   0,1,y0/d,0,
					   0,0,0,0,
					   0,0,1/d,1};	
trans=2;
if(mode==4)
{
	mat[2][3]=-trans;
	ChangeCube(mat);
}	
else if(mode==5)
{
	mat[2][3]=trans;
		ChangeCube(mat);
}

	CView::OnLButtonDown(nFlags, point);
}
