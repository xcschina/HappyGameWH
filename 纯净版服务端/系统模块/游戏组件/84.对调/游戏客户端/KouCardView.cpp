#include "StdAfx.h"
#include "KouCardView.h"

//////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CKouCardView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////

//构造函数
CKouCardView::CKouCardView()
{
	//设置数据
	m_cbConcealCount=0;
	ZeroMemory(m_cbConcealCard,sizeof(m_cbConcealCard));

	//加载资源
	m_ImageCard.SetLoadInfo(IDB_CARD,AfxGetInstanceHandle());
	m_ImageBack.SetLoadInfo(IDB_CONCEAL_CARD_VIEW,AfxGetInstanceHandle());

	//获取大小
	CImageHandle CardImageHandle(&m_ImageCard);
	m_CardSize.cx=m_ImageCard.GetWidth()/13;
	m_CardSize.cy=m_ImageCard.GetHeight()/5;

	return;
}

//析构函数
CKouCardView::~CKouCardView()
{
}

//建立消息
int CKouCardView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (__super::OnCreate(lpCreateStruct)==-1) return -1;

	//设置背景
	SetClassLong(m_hWnd,GCL_HBRBACKGROUND,NULL);

	//移动窗口
	CImageHandle ImageHandle(&m_ImageBack);
	SetWindowPos(NULL,0,0,m_ImageBack.GetWidth(),m_ImageBack.GetHeight(),SWP_NOMOVE|SWP_NOZORDER);

	return 0;
}

//重画函数
void CKouCardView::OnPaint() 
{
	CPaintDC dc(this); 

	//加载资源
	CImageHandle HandleBack(&m_ImageBack);
	CImageHandle HandleCard(&m_ImageCard);

	//绘画背景
	m_ImageBack.BitBlt(dc,0,0);

	//绘画扑克
	if (m_cbConcealCount>0)
	{
		//获取位置
		CRect rcClient;
		GetClientRect(&rcClient);

		//计算大小
		CSize ControlSize;
		ControlSize.cy=m_CardSize.cy;
		ControlSize.cx=m_CardSize.cx+(m_cbConcealCount-1)*18;

		//定义位置
		int nXPos=(rcClient.Width()-ControlSize.cx)/2+17;
		int nYPos=(rcClient.Height()-ControlSize.cy)/2;

		//绘画扑克
		for (BYTE i=0;i<m_cbConcealCount;i++)
		{
			//变量定义
			int nXImagePos=0,nYImagePos=0;

			//图片位置
			if (m_cbConcealCard[i]!=0)
			{
				if ((m_cbConcealCard[i]==0x4E)||(m_cbConcealCard[i]==0x4F))
				{
					nYImagePos=((m_cbConcealCard[i]&CARD_MASK_COLOR)>>4)*m_CardSize.cy;
					nXImagePos=((m_cbConcealCard[i]&CARD_MASK_VALUE)%14)*m_CardSize.cx;
				}
				else
				{
					nXImagePos=((m_cbConcealCard[i]&CARD_MASK_VALUE)-1)*m_CardSize.cx;
					nYImagePos=((m_cbConcealCard[i]&CARD_MASK_COLOR)>>4)*m_CardSize.cy;
				}
			}
			else
			{
				nXImagePos=m_CardSize.cx*2;
				nYImagePos=m_CardSize.cy*4;
			}

			//绘画扑克
			m_ImageCard.AlphaDrawImage(&dc,nXPos+i*18,nYPos,m_CardSize.cx,m_CardSize.cy,nXImagePos,nYImagePos,RGB(255,0,255));
		}
	}

	return;
}

//设置信息
void CKouCardView::SetConcealCard(BYTE cbConcealCard[], BYTE cbConcealCount)
{
	//设置变量
	m_cbConcealCount=cbConcealCount;
	CopyMemory(m_cbConcealCard,cbConcealCard,cbConcealCount*sizeof(BYTE));

	//刷新界面
	if (m_hWnd!=NULL) Invalidate(FALSE);

	return;
}

//////////////////////////////////////////////////////////////////////////
