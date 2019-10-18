#include "Stdafx.h"
#include "GameOption.h"
#include "GameClientDlg.h"

//////////////////////////////////////////////////////////////////////////

//时间标识
#define IDI_OUT_CARD					200								//出牌定时器
#define IDI_CALL_CARD					201								//叫牌定时器
#define IDI_START_GAME					202								//开始定时器
#define IDI_SEND_CONCEAL				203								//底牌定时器
#define IDI_KOU							204								//扣王定时器

//时间范围
#define TIME_OUT_CARD					30								//出牌时间
#define TIME_CALL_CARD					10								//叫牌时间
#define TIME_START_GAME					30								//开始时间
#define TIME_SEND_CONCEAL				40								//留底时间
#define TIME_KOU						10								//扣王时间

//功能定时器
#define IDI_CONCEAL_CARD				300								//底牌定时器
#define IDI_DISPATCH_CARD				301								//发牌定时器
#define IDI_LAST_TURN_CARD				302								//上轮定时器
#define IDI_THROW_CARD_RESULT			303								//甩牌定时器

//////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CGameClientDlg, CGameFrameDlg)
	ON_WM_TIMER()
	ON_MESSAGE(IDM_START,OnStart)
	ON_MESSAGE(IDM_OUT_CARD,OnOutCard)
	ON_MESSAGE(IDM_CALL_CARD,OnCallCard)
	ON_MESSAGE(IDM_OUT_PROMPT,OnOutPrompt)
	ON_MESSAGE(IDM_SEND_CONCEAL,OnSendConceal)
	ON_MESSAGE(IDM_KOU,OnKouWang)
	ON_MESSAGE(IDM_CONCEAL_CARD,OnConcealCard)
	ON_MESSAGE(IDM_REQUEST_LEAVE,OnRuquestLeave)
	ON_MESSAGE(IDM_LAST_TURN_CARD,OnLastTurnCard)
	ON_MESSAGE(IDM_TRUSTEE_CONTROL,OnStusteeControl)
	ON_MESSAGE(IDM_LEFT_HIT_CARD,OnLeftHitCard)
	ON_MESSAGE(IDM_RIGHT_HIT_CARD,OnRightHitCard)
	ON_MESSAGE(IDM_GIVE_UP,OnGiveUp)
	
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////

//构造函数
CGameClientDlg::CGameClientDlg() : CGameFrameDlg(&m_GameClientView)
{
	//逻辑变量
	m_cbPackCount=0;
	m_cbMainColor=COLOR_ERROR;
	m_cbMainValue=VALUE_ERROR;

	//叫牌信息
	m_cbCallCard=0;
	m_cbCallCount=0;
	m_wCallCardUser=INVALID_CHAIR;

	//状态变量
	m_wBankerUser=INVALID_CHAIR;
	m_wCurrentUser=INVALID_CHAIR;
	
	//得分信息
	m_cbScoreCardCount=0;
	ZeroMemory(m_cbScoreCardData,sizeof(m_cbScoreCardData));

	//甩牌变量
	m_bThrowCard=false;
	m_cbResultCardCount=0;
	m_wThrowCardUser=INVALID_CHAIR;
	ZeroMemory(m_cbResultCardData,sizeof(m_cbResultCardData));

	//出牌变量
	m_bLastTurn=false;
	m_wFirstOutUser=INVALID_CHAIR;
	ZeroMemory(m_cbOutCardData,sizeof(m_cbOutCardData));
	ZeroMemory(m_cbOutCardCount,sizeof(m_cbOutCardCount));

	//底牌扑克
	m_cbConcealCount=0;
	ZeroMemory(m_cbConcealCard,sizeof(m_cbConcealCard));

	//用户扑克
	m_cbHandCardCount=0;
	ZeroMemory(m_cbHandCardData,sizeof(m_cbHandCardData));

	//配置变量
	m_bStustee=false;
	m_bDeasilOrder=false;
	m_dwCardHSpace=DEFAULT_PELS;

	//辅助变量
	m_cbRemnantCardCount=0;
	m_cbDispatchCardCount=0;
	ZeroMemory(m_cbDispatchCardData,sizeof(m_cbDispatchCardData));
	m_wNextUser=INVALID_CHAIR;

	return;
}

//析构函数
CGameClientDlg::~CGameClientDlg()
{
}

//初始函数
bool CGameClientDlg::InitGameFrame()
{
	//设置标题
	SetWindowText(TEXT("对调游戏--测试版本"));

	//设置图标
	HICON hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
	SetIcon(hIcon,TRUE);
	SetIcon(hIcon,FALSE);

	//读取配置
	m_dwCardHSpace=AfxGetApp()->GetProfileInt(TEXT("GameOption"),TEXT("CardSpace"),DEFAULT_PELS);
	m_bDeasilOrder=AfxGetApp()->GetProfileInt(TEXT("GameOption"),TEXT("DeasilOrder"),FALSE)?true:false;

	//调整参数
	if ((m_dwCardHSpace>MAX_PELS)||(m_dwCardHSpace<LESS_PELS)) m_dwCardHSpace=DEFAULT_PELS;

	//配置控件
	m_GameClientView.SetUserOrder(m_bDeasilOrder);
	m_GameClientView.m_HandCardControl.SetCardSpace(m_dwCardHSpace,0,DEF_CARD_SHOOT);
	m_GameClientView.m_KouCardControl.SetCardSpace(m_dwCardHSpace,0,DEF_CARD_SHOOT);
	

	return true;
}

//重置框架
void CGameClientDlg::ResetGameFrame()
{
	//逻辑变量
	m_cbPackCount=0;
	m_cbMainColor=COLOR_ERROR;
	m_cbMainValue=VALUE_ERROR;

	//叫牌信息
	m_cbCallCard=0;
	m_cbCallCount=0;
	m_wCallCardUser=INVALID_CHAIR;

	//状态变量
	m_wBankerUser=INVALID_CHAIR;
	m_wCurrentUser=INVALID_CHAIR;
	
	//得分信息
	m_cbScoreCardCount=0;
	ZeroMemory(m_cbScoreCardData,sizeof(m_cbScoreCardData));

	//甩牌变量
	m_bThrowCard=false;
	m_cbResultCardCount=0;
	m_wThrowCardUser=INVALID_CHAIR;
	ZeroMemory(m_cbResultCardData,sizeof(m_cbResultCardData));

	//出牌变量
	m_bLastTurn=false;
	m_wFirstOutUser=INVALID_CHAIR;
	ZeroMemory(m_cbOutCardData,sizeof(m_cbOutCardData));
	ZeroMemory(m_cbOutCardCount,sizeof(m_cbOutCardCount));

	//底牌扑克
	m_cbConcealCount=0;
	ZeroMemory(m_cbConcealCard,sizeof(m_cbConcealCard));

	//用户扑克
	m_cbHandCardCount=0;
	ZeroMemory(m_cbHandCardData,sizeof(m_cbHandCardData));

	//配置变量
	m_bStustee=false;

	//辅助变量
	m_cbRemnantCardCount=0;
	m_cbDispatchCardCount=0;
	ZeroMemory(m_cbDispatchCardData,sizeof(m_cbDispatchCardData));
	m_wNextUser=INVALID_CHAIR;

	//删除定时器
	KillTimer(IDI_CONCEAL_CARD);
	KillTimer(IDI_DISPATCH_CARD);
	KillTimer(IDI_LAST_TURN_CARD);
	KillTimer(IDI_THROW_CARD_RESULT);

	return;
}

//游戏设置
void CGameClientDlg::OnGameOptionSet()
{
	//构造数据
	CGameOption GameOption;
	GameOption.m_dwCardHSpace=m_dwCardHSpace;
	GameOption.m_bEnableSound=IsEnableSound();
	GameOption.m_bDeasilOrder=m_GameClientView.IsDeasilOrder();

	//配置数据
	if (GameOption.DoModal()==IDOK)
	{
		//获取参数
		m_bDeasilOrder=GameOption.m_bDeasilOrder;
		m_dwCardHSpace=GameOption.m_dwCardHSpace;

		//设置控件
		EnableSound(GameOption.m_bEnableSound);
		m_GameClientView.SetUserOrder(GameOption.m_bDeasilOrder);
		m_GameClientView.m_HandCardControl.SetCardSpace(m_dwCardHSpace,0,20);
		m_GameClientView.m_KouCardControl.SetCardSpace(m_dwCardHSpace,0,20);
		

		//保存配置
		AfxGetApp()->WriteProfileInt(TEXT("GameOption"),TEXT("CardSpace"),m_dwCardHSpace);
		AfxGetApp()->WriteProfileInt(TEXT("GameOption"),TEXT("DeasilOrder"),m_bDeasilOrder?TRUE:FALSE);
	}

	return;
}

//时间消息
bool CGameClientDlg::OnTimerMessage(WORD wChairID, UINT nElapse, UINT nTimerID)
{
	switch (nTimerID)
	{
	case IDI_OUT_CARD:			//用户出牌
		{
			//超时判断
			if ((nElapse==0)||((m_bStustee==true)&&(nElapse<(TIME_OUT_CARD))))
			{
				if ((IsLookonMode()==false)&&(wChairID==GetMeChairID())) AutomatismOutCard();
				return true;
			}

			//播放声音
			if ((nElapse<=3)&&(wChairID==GetMeChairID())&&(IsLookonMode()==false)) PlayGameSound(AfxGetInstanceHandle(),TEXT("GAME_WARN"));

			return true;
		}
	case IDI_CALL_CARD:			//用户叫牌
		{
			//超时判断
			if ((nElapse==0)||((m_bStustee==true)&&(nElapse<(TIME_CALL_CARD))))
			{
				//隐藏控件
				m_GameClientView.m_CallCardWnd.ShowWindow(SW_HIDE);
				m_GameClientView.m_CallCardWnd.UpdateCallControl(CALL_NONE);

				//发送消息
				if (IsLookonMode()==false) SendData(SUB_C_CALL_FINISH);

				return true;
			}

			return true;
		}
	case IDI_KOU:               //扣王时间
		{
			if ((nElapse==0)||((m_bStustee==true)&&(nElapse<(TIME_KOU))))
			{
				if ((IsLookonMode()==false)&&(wChairID==GetMeChairID()))
				{
					m_GameClientView.m_btKouWang.ShowWindow(SW_HIDE);
					m_GameClientView.m_btKouWang.EnableWindow(false);
					m_GameClientView.m_btGiveUp.ShowWindow(SW_HIDE);
					m_GameClientView.m_btGiveUp.EnableWindow(false);

					//构造数据
					CMD_C_KouWang KouWang;
					KouWang.cbConcealCount=m_cbConcealCount;
					CopyMemory(KouWang.cbConcealCard,m_cbConcealCard,m_cbConcealCount*sizeof(BYTE));
					KouWang.cbUserCardCount=m_cbHandCardCount;
					CopyMemory(KouWang.cbUserCardData,m_cbHandCardData,m_cbHandCardCount*sizeof(BYTE));

					//发送数据
					SendData(SUB_C_KOU_WANG,&KouWang,sizeof(KouWang));
				}
				return true;
			}
			if ((nElapse<=3)&&(wChairID==GetMeChairID())&&(IsLookonMode()==false)) PlayGameSound(AfxGetInstanceHandle(),TEXT("GAME_WARN"));

			return true;
		}
	case IDI_START_GAME:		//开始游戏
		{
			if ((nElapse==0)||((m_bStustee==true)&&(nElapse<(TIME_START_GAME))))
			{
				if ((IsLookonMode()==false)&&(wChairID==GetMeChairID())) OnStart(0,0);
				return true;
			}
			if ((nElapse<=3)&&(wChairID==GetMeChairID())&&(IsLookonMode()==false)) PlayGameSound(AfxGetInstanceHandle(),TEXT("GAME_WARN"));

			return true;
		}
	case IDI_SEND_CONCEAL:		//发送底牌
		{
			if ((nElapse==0)||((m_bStustee==true)&&(nElapse<(TIME_SEND_CONCEAL))))
			{
				//自动留底
				if ((IsLookonMode()==false)&&(wChairID==GetMeChairID()))
				{
					//删除定时器
					KillGameTimer(IDI_SEND_CONCEAL);

					//删除扑克
					m_cbHandCardCount-=m_cbConcealCount;
					m_GameLogic.RemoveCard(m_cbConcealCard,m_cbConcealCount,m_cbHandCardData,m_cbHandCardCount+m_cbConcealCount);

					//设置界面
					m_GameClientView.m_btSendConceal.ShowWindow(SW_HIDE);
					m_GameClientView.m_btSendConceal.EnableWindow(FALSE);
					SetHandCardControl(m_cbHandCardData,m_cbHandCardCount);

					//构造数据
					CMD_C_ConcealCard ConcealCard;
					ConcealCard.cbConcealCount=m_cbConcealCount;
					CopyMemory(ConcealCard.cbConcealCard,m_cbConcealCard,m_cbConcealCount*sizeof(BYTE));

					//发送数据
					SendData(SUB_C_CONCEAL_CARD,&ConcealCard,sizeof(ConcealCard));

					//提示信息
					if (m_bStustee==false) InsertSystemString(TEXT("限定的时间到了，系统为您自动埋底牌"));

					return false;
				}

				return true;
			}
			if ((nElapse<=3)&&(wChairID==GetMeChairID())&&(IsLookonMode()==false)) PlayGameSound(AfxGetInstanceHandle(),TEXT("GAME_WARN"));

			return true;
		}
	}

	return false;
}

//旁观状态
void CGameClientDlg::OnLookonChanged(bool bLookonUser, const void * pBuffer, WORD wDataSize)
{
	//扑克控制
	m_GameClientView.m_HandCardControl.SetDisplayFlag((IsAllowLookon()==true));
	m_GameClientView.m_KouCardControl.SetDisplayFlag((IsAllowLookon()==true));
	
	//功能按钮
	m_GameClientView.m_btConcealCard.EnableWindow(((m_cbConcealCount>0)&&((IsLookonMode==false)||(IsAllowLookon()==true)))?TRUE:FALSE);

	return;
}

//网络消息
bool CGameClientDlg::OnGameMessage(WORD wSubCmdID, const void * pBuffer, WORD wDataSize)
{
	switch (wSubCmdID)
	{
	case SUB_S_GAME_START:		//游戏开始
		{
			return OnSubGameStart(pBuffer,wDataSize);
		}
	case SUB_S_SEND_CARD:		//发送扑克
		{
			return OnSubSendCard(pBuffer,wDataSize);
		}
	case SUB_S_CALL_CARD:		//用户叫牌
		{
			return OnSubCallCard(pBuffer,wDataSize);
		}
	case SUB_S_SEND_CONCEAL:	//发送底牌
		{
			return OnSubSendConceal(pBuffer,wDataSize);
		}
	case SUB_S_KOU_WANG:        //用户扣王
		{
			return OnSubKouWang(pBuffer,wDataSize);
		}
	case SUB_S_GAME_PLAY:		//游戏开始
		{
			return OnSubGamePlay(pBuffer,wDataSize);
		}
	case SUB_S_OUT_CARD:		//用户出牌
		{
			return OnSubOutCard(pBuffer,wDataSize);
		}
	case SUB_S_THROW_RESULT:	//甩牌结果
		{
			return OnSubThrowResult(pBuffer,wDataSize);
		}
	case SUB_S_TURN_BALANCE:	//一轮结算
		{
			return OnSubTurnBalance(pBuffer,wDataSize);
		}
	case SUB_S_GAME_END:		//游戏结束
		{
			return OnSubGameEnd(pBuffer,wDataSize);
		}
	}

	return true;
}

//游戏场景
bool CGameClientDlg::OnGameSceneMessage(BYTE cbGameStation, bool bLookonOther, const void * pBuffer, WORD wDataSize)
{
	switch (cbGameStation)
	{
	case GS_UG_FREE:	//空闲状态
		{
			//效验数据
			if (wDataSize!=sizeof(CMD_S_StatusFree)) return false;
			CMD_S_StatusFree * pStatusFree=(CMD_S_StatusFree *)pBuffer;

			//设置控件
			if (IsLookonMode()==false)
			{
				m_GameClientView.m_btStart.ShowWindow(TRUE);
				m_GameClientView.m_btStart.SetFocus();
			}

			//玩家设置
			if (IsLookonMode()==false)
			{
				//m_GameClientView.m_btStusteeControl.EnableWindow(TRUE);
				m_GameClientView.m_HandCardControl.SetDisplayFlag(true);
				m_GameClientView.m_KouCardControl.ShowWindow(SW_HIDE);
			}

			return true;
		}
	case GS_UG_CALL:	//叫牌状态
		{
			//效验数据
			if (wDataSize!=sizeof(CMD_S_StatusCall)) return false;
			CMD_S_StatusCall * pStatusCall=(CMD_S_StatusCall *)pBuffer;

			//逻辑变量
			m_cbPackCount=pStatusCall->cbPackCount;
			m_cbMainValue=pStatusCall->cbMainValue;
			m_wBankerUser=pStatusCall->wBankerUser;

			//叫牌信息
			m_cbCallCard=pStatusCall->cbCallCard;
			m_cbCallCount=pStatusCall->cbCallCount;
			m_wCallCardUser=pStatusCall->wCallCardUser;

			//设置扑克
			m_cbHandCardCount=pStatusCall->cbCardCount;
			CopyMemory(m_cbHandCardData,pStatusCall->cbCardData,sizeof(BYTE)*m_cbHandCardCount);

			//逻辑组件
			m_GameLogic.SetPackCount(m_cbPackCount);
			m_GameLogic.SetMainColor(m_cbMainColor);
			m_GameLogic.SetMainValue(m_cbMainValue);

			//主牌信息
			WORD wMeChairID=GetMeChairID();
			BYTE cbValueMySelf=pStatusCall->cbValueOrder[wMeChairID%2];
			BYTE cbValueOther=pStatusCall->cbValueOrder[(wMeChairID+1)%2];
			m_GameClientView.SetValueOrder(m_cbMainValue,cbValueMySelf,cbValueOther);

			//叫牌信息
			if (m_wCallCardUser!=INVALID_CHAIR)
			{
				WORD wViewChairID=SwitchViewChairID(m_wCallCardUser);
				BYTE cbCallColor=m_GameLogic.GetCardColor(m_cbCallCard);
				m_GameClientView.SetCallCardInfo(wViewChairID,cbCallColor,m_cbCallCount);
			}

			//叫牌界面
			BYTE cbCallCard[2];
			WORD wViewChairID=SwitchViewChairID(m_wCallCardUser);
			for (BYTE i=0;i<m_cbCallCount;i++) cbCallCard[i]=m_cbCallCard;
			m_GameClientView.m_UserCardControl[wViewChairID].SetCardData(cbCallCard,m_cbCallCount);

			//设置庄家
			if (m_wBankerUser!=INVALID_CHAIR) m_GameClientView.SetBankerUser(SwitchViewChairID(m_wBankerUser));

			//玩家设置
			if (IsLookonMode()==false) 
			{
				//m_GameClientView.m_btStusteeControl.EnableWindow(TRUE);
				m_GameClientView.m_HandCardControl.SetDisplayFlag(true);
				m_GameClientView.m_KouCardControl.SetDisplayFlag(false);
			}

			//扑克设置
			if (pStatusCall->cbComplete==FALSE)
			{
				//控制设置
				m_GameClientView.m_CallCardWnd.ShowWindow(SW_SHOW);
				m_GameClientView.m_CallCardWnd.UpdateCallControl(CALL_NONE);

				//派发扑克
				DispatchUserCard(m_cbHandCardData,m_cbHandCardCount);
			}
			else
			{
				//排列扑克
				m_GameLogic.SortCardList(m_cbHandCardData,m_cbHandCardCount);

				//设置扑克
				SetHandCardControl(m_cbHandCardData,m_cbHandCardCount);
			}

			return true;
		}
	case GS_UG_BACK:	//留底状态
		{
			//效验数据
			if (wDataSize!=sizeof(CMD_S_StatusBack)) return false;
			CMD_S_StatusBack * pStatusBack=(CMD_S_StatusBack *)pBuffer;

			//逻辑变量
			m_cbPackCount=pStatusBack->cbPackCount;
			m_cbMainColor=pStatusBack->cbMainColor;
			m_cbMainValue=pStatusBack->cbMainValue;

			//叫牌信息
			m_cbCallCard=pStatusBack->cbCallCard;
			m_cbCallCount=pStatusBack->cbCallCount;
			m_wCallCardUser=pStatusBack->wCallCardUser;

			//用户变量
			m_wBankerUser=pStatusBack->wBankerUser;
			m_wCurrentUser=pStatusBack->wCurrentUser;
			m_wCallCardUser=pStatusBack->wCallCardUser;

			//逻辑组件
			m_GameLogic.SetPackCount(m_cbPackCount);
			m_GameLogic.SetMainColor(m_cbMainColor);
			m_GameLogic.SetMainValue(m_cbMainValue);

			//设置底牌
			m_cbConcealCount=pStatusBack->cbConcealCount;
			CopyMemory(m_cbConcealCard,pStatusBack->cbConcealCard,m_cbConcealCount*sizeof(BYTE));

			//设置扑克
			m_cbHandCardCount=pStatusBack->cbCardCount;
			CopyMemory(m_cbHandCardData,pStatusBack->cbCardData,sizeof(BYTE)*m_cbHandCardCount);

			//主牌信息
			WORD wMeChairID=GetMeChairID();
			BYTE cbValueMySelf=pStatusBack->cbValueOrder[wMeChairID%2];
			BYTE cbValueOther=pStatusBack->cbValueOrder[(wMeChairID+1)%2];
			m_GameClientView.SetValueOrder(m_cbMainValue,cbValueMySelf,cbValueOther);

			//叫牌信息
			if (m_wCallCardUser!=INVALID_CHAIR)
			{
				WORD wViewChairID=SwitchViewChairID(m_wCallCardUser);
				BYTE cbCallColor=m_GameLogic.GetCardColor(m_cbCallCard);
				m_GameClientView.SetCallCardInfo(wViewChairID,cbCallColor,m_cbCallCount);
			}

			//排列扑克
			m_GameLogic.SortCardList(m_cbHandCardData,m_cbHandCardCount);

			//界面设置
			SetHandCardControl(m_cbHandCardData,m_cbHandCardCount);
			m_GameClientView.SetBankerUser(SwitchViewChairID(m_wBankerUser));

			//玩家设置
			if (IsLookonMode()==false) 
			{
				//扑克设置
				//m_GameClientView.m_btStusteeControl.EnableWindow(TRUE);
				m_GameClientView.m_HandCardControl.SetDisplayFlag(true);
				m_GameClientView.m_KouCardControl.ShowWindow(SW_HIDE);

				//留底设置
				if (m_wCurrentUser==GetMeChairID())
				{
					m_GameClientView.m_btSendConceal.EnableWindow(TRUE);
					m_GameClientView.m_btSendConceal.ShowWindow(SW_SHOW);
					m_GameClientView.m_HandCardControl.SetPositively(true);
					m_GameClientView.m_HandCardControl.SetShootCard(m_cbConcealCard,m_cbConcealCount);
				}
				else m_GameClientView.SetWaitConceal(true);
			}
			else m_GameClientView.SetWaitConceal(true);

			//时间设置
			SetGameTimer(m_wCurrentUser,IDI_SEND_CONCEAL,TIME_SEND_CONCEAL);

			return true;
		}
	case GS_UG_PLAY:	//游戏状态
		{
			//效验数据
			if (wDataSize!=sizeof(CMD_S_StatusPlay)) return false;
			CMD_S_StatusPlay * pStatusPlay=(CMD_S_StatusPlay *)pBuffer;

			//逻辑变量
			m_cbPackCount=pStatusPlay->cbPackCount;
			m_cbMainColor=pStatusPlay->cbMainColor;
			m_cbMainValue=pStatusPlay->cbMainValue;

			//叫牌信息
			m_cbCallCard=pStatusPlay->cbCallCard;
			m_cbCallCount=pStatusPlay->cbCallCount;
			m_wCallCardUser=pStatusPlay->wCallCardUser;

			//用户变量
			m_wBankerUser=pStatusPlay->wBankerUser;
			m_wCurrentUser=pStatusPlay->wCurrentUser;
			m_wFirstOutUser=pStatusPlay->wFirstOutUser;

			//逻辑组件
			m_GameLogic.SetPackCount(m_cbPackCount);
			m_GameLogic.SetMainColor(m_cbMainColor);
			m_GameLogic.SetMainValue(m_cbMainValue);

			//设置底牌
			m_cbConcealCount=pStatusPlay->cbConcealCount;
			CopyMemory(m_cbConcealCard,pStatusPlay->cbConcealCard,m_cbConcealCount*sizeof(BYTE));

			//设置扑克
			m_cbHandCardCount=pStatusPlay->cbCardCount;
			CopyMemory(m_cbHandCardData,pStatusPlay->cbCardData,sizeof(BYTE)*m_cbHandCardCount);

			//出牌变量
			for (WORD i=0;i<GAME_PLAYER;i++)
			{
				m_cbOutCardCount[i][0]=pStatusPlay->cbOutCardCount[i];
				CopyMemory(m_cbOutCardData[i][0],pStatusPlay->cbOutCardData[i],sizeof(BYTE)*m_cbOutCardCount[i][0]);
			}

			//得分信息
			m_cbScoreCardCount=pStatusPlay->cbScoreCardCount;
			CopyMemory(m_cbScoreCardData,pStatusPlay->cbScoreCardData,sizeof(BYTE)*m_cbScoreCardCount);

			//主牌信息
			WORD wMeChairID=GetMeChairID();
			BYTE cbValueMySelf=pStatusPlay->cbValueOrder[wMeChairID%2];
			BYTE cbValueOther=pStatusPlay->cbValueOrder[(wMeChairID+1)%2];
			m_GameClientView.SetValueOrder(m_cbMainValue,cbValueMySelf,cbValueOther);

			//叫牌信息
			if (m_wCallCardUser!=INVALID_CHAIR)
			{
				WORD wViewChairID=SwitchViewChairID(m_wCallCardUser);
				BYTE cbCallColor=m_GameLogic.GetCardColor(m_cbCallCard);
				m_GameClientView.SetCallCardInfo(wViewChairID,cbCallColor,m_cbCallCount);
			}

			//得分视图
			m_GameClientView.m_CardScore.SetCardData(m_cbScoreCardData,m_cbScoreCardCount);
			m_GameClientView.SetCardScore(m_GameLogic.GetCardScore(m_cbScoreCardData,m_cbScoreCardCount));

			//出牌界面
			for (WORD i=0;i<GAME_PLAYER;i++)
			{
				WORD wViewChairID=SwitchViewChairID(i);
				m_GameClientView.m_UserCardControl[wViewChairID].SetCardData(m_cbOutCardData[i][0],m_cbOutCardCount[i][0]);
			}

			//排列扑克
			m_GameLogic.SortCardList(m_cbHandCardData,m_cbHandCardCount);

			//界面设置
			SetHandCardControl(m_cbHandCardData,m_cbHandCardCount);
			m_GameClientView.SetBankerUser(SwitchViewChairID(m_wBankerUser));

			//玩家设置
			if (IsLookonMode()==false) 
			{
				//m_GameClientView.m_btStusteeControl.EnableWindow(TRUE);
				m_GameClientView.m_HandCardControl.SetPositively(true);
				m_GameClientView.m_HandCardControl.SetDisplayFlag(true);
				m_GameClientView.m_KouCardControl.ShowWindow(SW_HIDE);
			}

			//旁观设置
			if (IsAllowLookon()==true) 
			{
				m_GameClientView.m_HandCardControl.SetDisplayFlag(true);
				m_GameClientView.m_KouCardControl.ShowWindow(SW_HIDE);
			}
			//出牌设置
			if ((IsLookonMode()==false)&&(m_wCurrentUser==GetMeChairID()))
			{
				m_GameClientView.m_btOutCard.ShowWindow(SW_SHOW);
				m_GameClientView.m_btOutPrompt.ShowWindow(SW_SHOW);
				m_GameClientView.m_btOutCard.EnableWindow((VerdictOutCard()==true)?TRUE:FALSE);
			}

			//功能按钮
			m_GameClientView.m_btConcealCard.EnableWindow(((m_cbConcealCount>0)&&((IsLookonMode==false)||(IsAllowLookon()==true)))?TRUE:FALSE);

			//时间设置
			SetGameTimer(m_wCurrentUser,IDI_OUT_CARD,TIME_OUT_CARD);

			return true;
		}
	}

	return false;
}

//游戏开始
bool CGameClientDlg::OnSubGameStart(const void * pBuffer, WORD wDataSize)
{
	//效验数据
	ASSERT(wDataSize==sizeof(CMD_S_GameStart));
	if (wDataSize!=sizeof(CMD_S_GameStart)) return false;

	//消息处理
	CMD_S_GameStart * pGameStart=(CMD_S_GameStart *)pBuffer;

	//辅助变量
	m_wNextUser=INVALID_CHAIR;

	//设置状态
	SetGameStatus(GS_UG_CALL);

	//逻辑变量
	m_cbMainColor=COLOR_ERROR;
	m_cbMainValue=pGameStart->cbMainValue;
	m_cbPackCount=pGameStart->cbPackCount;

	//叫牌变量
	m_cbCallCard=0;
	m_cbCallCount=0;
	m_wCallCardUser=INVALID_CHAIR;

	//底牌变量
	m_cbConcealCount=0;
	ZeroMemory(m_cbConcealCard,sizeof(m_cbConcealCard));

	//状态变量
	m_wCurrentUser=INVALID_CHAIR;
	m_wBankerUser=pGameStart->wBankerUser;

	//得分信息
	m_cbScoreCardCount=0;
	ZeroMemory(m_cbScoreCardData,sizeof(m_cbScoreCardData));

	//出牌变量
	m_wFirstOutUser=INVALID_CHAIR;
	ZeroMemory(m_cbOutCardData,sizeof(m_cbOutCardData));
	ZeroMemory(m_cbOutCardCount,sizeof(m_cbOutCardCount));

	//逻辑组件
	m_GameLogic.SetPackCount(m_cbPackCount);
	m_GameLogic.SetMainColor(m_cbMainColor);
	m_GameLogic.SetMainValue(m_cbMainValue);

	//界面设置
	m_GameClientView.SetCardScore(0xFFFF);
	m_GameClientView.m_CardScore.SetCardData(NULL,0);
	m_GameClientView.SetCallCardInfo(INVALID_CHAIR,COLOR_ERROR,0);

	//底牌控制
	m_GameClientView.m_btConcealCard.EnableWindow(FALSE);
	m_GameClientView.m_ConcealCardView.ShowWindow(SW_HIDE);
	m_GameClientView.m_ConcealCardView.SetConcealCard(NULL,0);

	//主牌信息
	WORD wMeChairID=GetMeChairID();
	BYTE cbValueMySelf=pGameStart->cbValueOrder[wMeChairID%2];
	BYTE cbValueOther=pGameStart->cbValueOrder[(wMeChairID+1)%2];
	m_GameClientView.SetValueOrder(m_cbMainValue,cbValueMySelf,cbValueOther);

	//设置庄家
	if (m_wBankerUser==INVALID_CHAIR) m_GameClientView.SetBankerUser(INVALID_CHAIR);
	else m_GameClientView.SetBankerUser(SwitchViewChairID(m_wBankerUser));

	//设置界面
	if (IsLookonMode()==true)
	{
		SetHandCardControl(NULL,0);
		m_GameClientView.SetWaitConceal(false);
		m_GameClientView.m_ScoreView.ShowWindow(SW_HIDE);
		m_GameClientView.m_CardScore.SetCardData(NULL,0);
		m_GameClientView.m_UserCardControl[0].SetCardData(NULL,0);
		m_GameClientView.m_UserCardControl[1].SetCardData(NULL,0);
		m_GameClientView.m_UserCardControl[2].SetCardData(NULL,0);
		m_GameClientView.m_UserCardControl[3].SetCardData(NULL,0);
	}

	//控制设置
	bool bPlayerMode=(IsLookonMode()==false);
	m_GameClientView.m_HandCardControl.SetDisplayFlag(bPlayerMode);
	
	m_GameClientView.m_KouCardControl.ShowWindow(SW_HIDE);
	m_GameClientView.m_KouCardControl.SetDisplayFlag(false);
	
	//if ((IsLookonMode()==false)&&(m_bStustee==false)) ActiveGameFrame();

	//环境设置
	PlayGameSound(AfxGetInstanceHandle(),TEXT("GAME_START"));

	return true;
}

//发送扑克
bool CGameClientDlg::OnSubSendCard(const void * pBuffer, WORD wDataSize)
{
	//变量定义
	CMD_S_SendCard * pSendCard=(CMD_S_SendCard *)pBuffer;
	WORD wFirstSize=sizeof(CMD_S_SendCard)-sizeof(pSendCard->cbCardData);

	//效验数据
	ASSERT(wDataSize>=wFirstSize);
	if (wDataSize<wFirstSize) return false;
	ASSERT(wDataSize==(wFirstSize+pSendCard->cbCardCount*sizeof(BYTE)));
	if (wDataSize!=(wFirstSize+pSendCard->cbCardCount*sizeof(BYTE))) return false;

	//设置扑克
	m_cbHandCardCount=pSendCard->cbCardCount;
	CopyMemory(m_cbHandCardData,pSendCard->cbCardData,sizeof(BYTE)*m_cbHandCardCount);

	//更新控制
	m_GameClientView.m_CallCardWnd.ShowWindow(SW_SHOW);
	m_GameClientView.m_CallCardWnd.UpdateCallControl(CALL_NONE);

	//派发扑克
	DispatchUserCard(m_cbHandCardData,m_cbHandCardCount);

	//环境设置
	//if ((IsLookonMode()==false)&&(m_bStustee==false)) ActiveGameFrame();

	return true;
}

//用户叫牌
bool CGameClientDlg::OnSubCallCard(const void * pBuffer, WORD wDataSize)
{
	//效验数据
	ASSERT(wDataSize==sizeof(CMD_S_CallCard));
	if (wDataSize!=sizeof(CMD_S_CallCard)) return false;

	//消息处理
	CMD_S_CallCard * pCallCard=(CMD_S_CallCard *)pBuffer;

	//清理叫牌
	if ((m_wCallCardUser!=INVALID_CHAIR)&&(m_wCallCardUser!=pCallCard->wCallCardUser))
	{
		WORD wViewChairID=SwitchViewChairID(m_wCallCardUser);
		m_GameClientView.m_UserCardControl[wViewChairID].SetCardData(NULL,0);
	}

	//设置变量
	m_cbCallCard=pCallCard->cbCallCard;
	m_cbCallCount=pCallCard->cbCallCount;
	m_wCallCardUser=pCallCard->wCallCardUser;

	//叫牌界面
	BYTE cbCallCard[2];
	WORD wViewChairID=SwitchViewChairID(m_wCallCardUser);
	for (BYTE i=0;i<m_cbCallCount;i++) cbCallCard[i]=m_cbCallCard;
	m_GameClientView.m_UserCardControl[wViewChairID].SetCardData(cbCallCard,m_cbCallCount);

	//视图信息
	BYTE cbCallColor=m_GameLogic.GetCardColor(m_cbCallCard);
	m_GameClientView.SetCallCardInfo(wViewChairID,cbCallColor,m_cbCallCount);

	//播放声音
	PlayGameSound(AfxGetInstanceHandle(),TEXT("CALL_CARD"));

	//更新控制
	UpdateCallCardControl();

	return true;
}

//发送底牌
bool CGameClientDlg::OnSubSendConceal(const void * pBuffer, WORD wDataSize)
{
	//效验数据
	ASSERT(wDataSize==sizeof(CMD_S_SendConceal));
	if (wDataSize!=sizeof(CMD_S_SendConceal)) return false;

	//消息处理
	CMD_S_SendConceal * pSendConceal=(CMD_S_SendConceal *)pBuffer;

	//设置变量
	m_cbMainColor=pSendConceal->cbMainColor;
	m_wBankerUser=pSendConceal->wBankerUser;
	m_wCurrentUser=pSendConceal->wCurrentUser;

	//状态设置
	SetGameStatus(GS_UG_BACK);
	m_GameLogic.SetMainColor(m_cbMainColor);
	m_GameClientView.SetBankerUser(SwitchViewChairID(m_wBankerUser));
	m_GameClientView.SetCallCardInfo(SwitchViewChairID(m_wBankerUser),m_cbMainColor,1);

	//叫牌清理
	if (m_wCallCardUser!=INVALID_CHAIR)
	{
		WORD wViewChairID=SwitchViewChairID(m_wCallCardUser);
		m_GameClientView.m_UserCardControl[wViewChairID].SetCardData(NULL,0);
	}

	//扑克设置
	if (m_wCurrentUser==GetMeChairID())
	{
		//设置底牌
		m_cbConcealCount=pSendConceal->cbConcealCount;
		CopyMemory(m_cbConcealCard,pSendConceal->cbConcealCard,m_cbConcealCount*sizeof(BYTE));

		//设置扑克
		CopyMemory(&m_cbHandCardData[m_cbHandCardCount],m_cbConcealCard,m_cbConcealCount*sizeof(BYTE));
		m_cbHandCardCount+=m_cbConcealCount;

		//设置扑克
		m_GameLogic.SortCardList(m_cbHandCardData,m_cbHandCardCount);
		SetHandCardControl(m_cbHandCardData,m_cbHandCardCount);

		//设置控制
		if (IsLookonMode()==false) 
		{
			//激活框架
			//if (m_bStustee==false) ActiveGameFrame();

			//设置控件
			m_GameClientView.m_btSendConceal.EnableWindow(TRUE);
			m_GameClientView.m_btSendConceal.ShowWindow(SW_SHOW);
			m_GameClientView.m_HandCardControl.SetPositively(true);
			m_GameClientView.m_HandCardControl.SetShootCard(m_cbConcealCard,m_cbConcealCount);
		}
		else 
		{
			//设置提示
			m_GameClientView.SetWaitConceal(true);
		}
	}
	else
	{
		//设置提示
		m_GameClientView.SetWaitConceal(true);

		//设置扑克
		m_GameLogic.SortCardList(m_cbHandCardData,m_cbHandCardCount);
		SetHandCardControl(m_cbHandCardData,m_cbHandCardCount);
	}

	//环境设置
	SetGameTimer(m_wCurrentUser,IDI_SEND_CONCEAL,TIME_SEND_CONCEAL);

	return true;
}

//用户扣王
bool CGameClientDlg::OnSubKouWang(const void * pBuffer, WORD wDataSize)
{
	//效验数据
	ASSERT(wDataSize==sizeof(CMD_S_KouWang));
	if (wDataSize!=sizeof(CMD_S_KouWang)) return false;
	
	//消息处理
	CMD_S_KouWang * pKouWang=(CMD_S_KouWang *)pBuffer;

	//时间处理
	KillGameTimer(IDI_SEND_CONCEAL);
	KillGameTimer(IDI_KOU);

	//设置变量
	SetGameStatus(GS_UG_KOU);
	WORD wNextUser=pKouWang->wNextUser;
	m_wNextUser=wNextUser;
	m_cbConcealCount=pKouWang->cbConcealCount;
	CopyMemory(m_cbConcealCard,pKouWang->cbConcealCard,m_cbConcealCount*sizeof(BYTE));
	
	//底牌设置
	if ((IsLookonMode()==true)&&(m_cbConcealCount!=0))
	{
		//删除扑克
		m_cbHandCardCount-=m_cbConcealCount;
		m_GameLogic.RemoveCard(m_cbConcealCard,m_cbConcealCount,m_cbHandCardData,m_cbHandCardCount+m_cbConcealCount);

		//设置扑克
		SetHandCardControl(m_cbHandCardData,m_cbHandCardCount);
	}

	//设置底牌
	m_GameClientView.m_ConcealCardView.SetConcealCard(m_cbConcealCard,m_cbConcealCount);
	m_GameClientView.m_btConcealCard.EnableWindow(FALSE);
	m_GameClientView.m_KouCardControl.SetCardData(m_cbConcealCard,m_cbConcealCount);
	m_GameClientView.m_KouCardControl.ShowWindow(SW_SHOW);
	m_GameClientView.m_KouCardControl.SetDisplayFlag(true);
	m_GameClientView.m_HandCardControl.SetPositively(false);

	m_GameClientView.SetWaitConceal(false);

	//当前玩家
	if ((IsLookonMode()==false)&&(wNextUser==GetMeChairID()))
	{
		m_GameClientView.m_HandCardControl.SetPositively(true);
		m_GameClientView.m_KouCardControl.SetPositively(true);
		
		m_GameClientView.m_btConcealCard.EnableWindow(FALSE);
		m_GameClientView.m_btOutCard.ShowWindow(SW_HIDE);
		m_GameClientView.m_btOutCard.EnableWindow(FALSE);
		m_GameClientView.m_btOutPrompt.ShowWindow(SW_HIDE);

		m_GameClientView.m_btKouWang.ShowWindow(SW_SHOW);
		m_GameClientView.m_btKouWang.EnableWindow(false);
		m_GameClientView.m_btGiveUp.ShowWindow(SW_SHOW);
		m_GameClientView.m_btGiveUp.EnableWindow(true);
	}
	SetGameTimer(wNextUser,IDI_KOU,TIME_KOU);
	return true;
}

//游戏开始
bool CGameClientDlg::OnSubGamePlay(const void * pBuffer, WORD wDataSize)
{
	//效验数据
	ASSERT(wDataSize==sizeof(CMD_S_GamePlay));
	if (wDataSize!=sizeof(CMD_S_GamePlay)) return false;

	//消息处理
	CMD_S_GamePlay * pGamePlay=(CMD_S_GamePlay *)pBuffer;

	//设置变量
	m_wCurrentUser=pGamePlay->wCurrentUser;
	m_wFirstOutUser=pGamePlay->wCurrentUser;
	m_cbConcealCount=pGamePlay->cbConcealCount;
	CopyMemory(m_cbConcealCard,pGamePlay->cbConcealCard,m_cbConcealCount*sizeof(BYTE));

	//底牌设置
	if ((IsLookonMode()==true)&&(m_cbConcealCount!=0))
	{
		//删除扑克
		m_cbHandCardCount-=m_cbConcealCount;
		m_GameLogic.RemoveCard(m_cbConcealCard,m_cbConcealCount,m_cbHandCardData,m_cbHandCardCount+m_cbConcealCount);

		//设置扑克
		SetHandCardControl(m_cbHandCardData,m_cbHandCardCount);
	}

	//设置底牌
	m_GameClientView.m_ConcealCardView.SetConcealCard(m_cbConcealCard,m_cbConcealCount);
	m_GameClientView.m_btConcealCard.EnableWindow(((m_cbConcealCount!=0)&&((IsLookonMode()==false)||(IsAllowLookon()==true)))?TRUE:FALSE);

	//设置状态
	SetGameStatus(GS_UG_PLAY);
	m_GameClientView.SetCardScore(0);
	m_GameClientView.SetWaitConceal(false);

	//控制设置
	bool bPlayerMode=(IsLookonMode()==false);
	m_GameClientView.m_HandCardControl.SetPositively(bPlayerMode);
	m_GameClientView.m_KouCardControl.ShowWindow(SW_HIDE);

	//当前玩家
	if ((IsLookonMode()==false)&&(m_wCurrentUser==GetMeChairID()))
	{
		//if (m_bStustee==false) ActiveGameFrame();
		m_GameClientView.m_btOutCard.ShowWindow(SW_SHOW);
		m_GameClientView.m_btOutCard.EnableWindow(FALSE);
		m_GameClientView.m_btOutPrompt.ShowWindow(SW_SHOW);
	}

	//环境设置
	SetGameTimer(m_wCurrentUser,IDI_OUT_CARD,TIME_OUT_CARD);
	PlayGameSound(AfxGetInstanceHandle(),TEXT("GAME_START"));

	return true;
}

//用户出牌
bool CGameClientDlg::OnSubOutCard(const void * pBuffer, WORD wDataSize)
{
	//变量定义
	CMD_S_OutCard * pOutCard=(CMD_S_OutCard *)pBuffer;
	WORD wFirstSize=sizeof(CMD_S_OutCard)-sizeof(pOutCard->cbCardData);

	//效验数据
	ASSERT(wDataSize>=wFirstSize);
	if (wDataSize<wFirstSize) return false;
	ASSERT(wDataSize==(wFirstSize+pOutCard->cbCardCount*sizeof(BYTE)));
	if (wDataSize!=(wFirstSize+pOutCard->cbCardCount*sizeof(BYTE))) return false;

	//变量定义
	WORD wMeChairID=GetMeChairID();
	WORD wOutCardUser=pOutCard->wOutCardUser;
	WORD wOutViewChairID=SwitchViewChairID(wOutCardUser);

	//出牌处理
	SwitchToThrowResult();
	KillGameTimer(IDI_OUT_CARD);

	//扑克界面
	if ((IsLookonMode()==true)||(wMeChairID!=wOutCardUser))
	{
		//历史扑克
		if (wOutCardUser==m_wFirstOutUser)
		{
			for (WORD i=0;i<GAME_PLAYER;i++) 
			{
				if (i==wOutCardUser) continue;
				m_GameClientView.m_UserCardControl[SwitchViewChairID(i)].SetCardData(NULL,0);
			}
		}

		//控制界面
		m_GameClientView.m_UserCardControl[wOutViewChairID].SetCardData(pOutCard->cbCardData,pOutCard->cbCardCount);
	}

	//历史扑克
	if ((wOutCardUser==m_wFirstOutUser)&&(m_cbOutCardCount[m_wFirstOutUser][0]!=0))
	{
		//设置扑克
		for (WORD i=0;i<GAME_PLAYER;i++) 
		{
			//保存扑克
			m_cbOutCardCount[i][1]=m_cbOutCardCount[i][0];
			CopyMemory(m_cbOutCardData[i][1],m_cbOutCardData[i][0],sizeof(BYTE)*m_cbOutCardCount[i][0]);

			//清理扑克
			m_cbOutCardCount[i][0]=0;
			ZeroMemory(m_cbOutCardData[i][0],sizeof(m_cbOutCardData[i][0]));
		}

		//控制按钮
		m_GameClientView.m_btLastTurnCard.EnableWindow(TRUE);
	}

	//出牌记录
	m_cbOutCardCount[wOutCardUser][0]=pOutCard->cbCardCount;
	CopyMemory(m_cbOutCardData[wOutCardUser][0],pOutCard->cbCardData,pOutCard->cbCardCount*sizeof(BYTE));

	//当前界面
	SwitchToCurrentCard();

	//玩家扑克
	if ((IsLookonMode()==true)&&(wOutCardUser==wMeChairID))
	{
		//删除扑克 
		BYTE cbSourceCount=m_cbHandCardCount;
		m_cbHandCardCount-=pOutCard->cbCardCount;
		m_GameLogic.RemoveCard(pOutCard->cbCardData,pOutCard->cbCardCount,m_cbHandCardData,cbSourceCount);

		//设置扑克
		SetHandCardControl(m_cbHandCardData,m_cbHandCardCount);
	}

	//播放声音
	if ((IsLookonMode()==true)||(wMeChairID!=wOutCardUser)) PlayGameSound(AfxGetInstanceHandle(),TEXT("OUT_CARD"));

	//设置变量
	m_wCurrentUser=pOutCard->wCurrentUser;

	//玩家设置
	if ((IsLookonMode()==false)&&(m_wCurrentUser==wMeChairID))
	{
		//if (m_bStustee==false) ActiveGameFrame();
		m_GameClientView.m_btOutCard.ShowWindow(SW_SHOW);
		m_GameClientView.m_btOutPrompt.ShowWindow(SW_SHOW);
		m_GameClientView.m_btOutCard.EnableWindow((VerdictOutCard()==true)?TRUE:FALSE);
	}

	//设置时间
	if (m_wCurrentUser!=INVALID_CHAIR) SetGameTimer(m_wCurrentUser,IDI_OUT_CARD,TIME_OUT_CARD);

	return true;
}

//甩牌结果
bool CGameClientDlg::OnSubThrowResult(const void * pBuffer, WORD wDataSize)
{
	//变量定义
	CMD_S_ThrowResult * pThrowResult=(CMD_S_ThrowResult *)pBuffer;
	WORD wCardCount=pThrowResult->cbThrowCardCount+pThrowResult->cbResultCardCount;
	WORD wFirstSize=sizeof(CMD_S_ThrowResult)-sizeof(pThrowResult->cbCardDataArray);

	//效验数据
	ASSERT(wDataSize>=wFirstSize);
	if (wDataSize<wFirstSize) return false;
	ASSERT(wDataSize==(wFirstSize+wCardCount*sizeof(BYTE)));
	if (wDataSize!=(wFirstSize+wCardCount*sizeof(BYTE))) return false;

	//变量定义
	WORD wMeChairID=GetMeChairID();
	WORD wOutCardUser=pThrowResult->wOutCardUser;
	WORD wOutViewChairID=SwitchViewChairID(wOutCardUser);

	//扑克变量
	BYTE cbThrowCardCount=pThrowResult->cbThrowCardCount;
	BYTE cbResultCardCount=pThrowResult->cbResultCardCount;
	BYTE * pcbThrowCardData=&pThrowResult->cbCardDataArray[0];
	BYTE * pcbResultCardData=&pThrowResult->cbCardDataArray[pThrowResult->cbThrowCardCount];

	//还原界面
	SwitchToCurrentCard();

	//出牌处理
	KillGameTimer(IDI_OUT_CARD);
	PlayGameSound(AfxGetInstanceHandle(),TEXT("THROW_RESULT"));

	//清理扑克
	for (WORD i=0;i<GAME_PLAYER;i++) 
	{
		//设置扑克
		if (i!=wOutCardUser) m_GameClientView.m_UserCardControl[SwitchViewChairID(i)].SetCardData(NULL,0);
	}

	//历史扑克
	if (m_cbOutCardCount[m_wFirstOutUser][0]!=0)
	{
		//设置扑克
		for (WORD i=0;i<GAME_PLAYER;i++) 
		{
			//保存扑克
			m_cbOutCardCount[i][1]=m_cbOutCardCount[i][0];
			CopyMemory(m_cbOutCardData[i][1],m_cbOutCardData[i][0],sizeof(BYTE)*m_cbOutCardCount[i][0]);

			//清理扑克
			m_cbOutCardCount[i][0]=0;
			ZeroMemory(m_cbOutCardData[i][0],sizeof(m_cbOutCardData[i][0]));
		}
	}

	//出牌界面
	m_GameClientView.m_UserCardControl[wOutViewChairID].SetCardData(pcbThrowCardData,cbThrowCardCount);

	//出牌记录
	m_cbOutCardCount[wOutCardUser][0]=cbResultCardCount;
	CopyMemory(m_cbOutCardData[wOutCardUser][0],pcbResultCardData,cbResultCardCount*sizeof(BYTE));

	//玩家扑克
	if (wOutCardUser==wMeChairID)
	{
		//填补扑克
		if (IsLookonMode()==false)
		{
			//设置扑克
			BYTE cbSourceCount=m_cbHandCardCount;
			m_cbHandCardCount+=cbThrowCardCount;
			CopyMemory(&m_cbHandCardData[cbSourceCount],pcbThrowCardData,sizeof(BYTE)*cbThrowCardCount);

			//排列扑克
			m_GameLogic.SortCardList(m_cbHandCardData,m_cbHandCardCount);
		}

		//删除扑克
		BYTE cbSourceCount=m_cbHandCardCount;
		m_cbHandCardCount-=cbResultCardCount;
		m_GameLogic.RemoveCard(pcbResultCardData,cbResultCardCount,m_cbHandCardData,cbSourceCount);

		//设置界面
		SetHandCardControl(m_cbHandCardData,m_cbHandCardCount);
	}

	//设置变量
	m_bThrowCard=true;
	m_cbResultCardCount=cbResultCardCount;
	m_wCurrentUser=pThrowResult->wCurrentUser;
	m_wThrowCardUser=pThrowResult->wOutCardUser;
	CopyMemory(m_cbResultCardData,pcbResultCardData,sizeof(BYTE)*cbResultCardCount);

	//设置时间
	SetTimer(IDI_THROW_CARD_RESULT,2000,NULL);

	//上轮设置
	m_GameClientView.m_btLastTurnCard.EnableWindow(FALSE);

	return true;
}

//一轮结算
bool CGameClientDlg::OnSubTurnBalance(const void * pBuffer, WORD wDataSize)
{
	//效验数据
	ASSERT(wDataSize==sizeof(CMD_TurnBalance));
	if (wDataSize!=sizeof(CMD_TurnBalance)) return false;

	//消息处理
	CMD_TurnBalance * pTurnBalance=(CMD_TurnBalance *)pBuffer;

	//计算得分
	WORD wWinnerUser=pTurnBalance->wTurnWinner;
	if ((wWinnerUser!=m_wBankerUser)&&((wWinnerUser+2)%GAME_PLAYER!=m_wBankerUser))
	{
		//获取分牌
		for (WORD i=0;i<GAME_PLAYER;i++)
		{
			BYTE * pcbScoreCard=&m_cbScoreCardData[m_cbScoreCardCount];
			BYTE cbMaxCount=CountArray(m_cbScoreCardData)-m_cbScoreCardCount;
			m_cbScoreCardCount+=m_GameLogic.GetScoreCard(m_cbOutCardData[i][0],m_cbOutCardCount[i][0],pcbScoreCard,cbMaxCount);
		}

		//设置界面
		m_GameClientView.m_CardScore.SetCardData(m_cbScoreCardData,m_cbScoreCardCount);
		m_GameClientView.SetCardScore(m_GameLogic.GetCardScore(m_cbScoreCardData,m_cbScoreCardCount));
	}

	//设置用户
	m_wCurrentUser=pTurnBalance->wCurrentUser;
	m_wFirstOutUser=pTurnBalance->wCurrentUser;

	//玩家设置
	if ((IsLookonMode()==false)&&(m_wCurrentUser==GetMeChairID()))
	{
		//if (m_bStustee==false) ActiveGameFrame();
		m_GameClientView.m_btOutCard.ShowWindow(SW_SHOW);
		m_GameClientView.m_btOutPrompt.ShowWindow(SW_SHOW);
		m_GameClientView.m_btOutCard.EnableWindow((VerdictOutCard()==true)?TRUE:FALSE);
	}

	//设置时间
	if (m_wCurrentUser!=INVALID_CHAIR) SetGameTimer(m_wCurrentUser,IDI_OUT_CARD,TIME_OUT_CARD);

	return true;
}

//游戏结束
bool CGameClientDlg::OnSubGameEnd(const void * pBuffer, WORD wDataSize)
{
	//效验数据
	ASSERT(wDataSize==sizeof(CMD_S_GameEnd));
	if (wDataSize!=sizeof(CMD_S_GameEnd)) return false;

	//消息处理
	CMD_S_GameEnd * pGameEnd=(CMD_S_GameEnd *)pBuffer;

	//游戏定时器
	KillGameTimer(IDI_OUT_CARD);
	KillGameTimer(IDI_CALL_CARD);
	KillGameTimer(IDI_SEND_CONCEAL);
	KillGameTimer(IDI_KOU);

	//功能定时器
	KillTimer(IDI_CONCEAL_CARD);
	KillTimer(IDI_DISPATCH_CARD);
	KillTimer(IDI_LAST_TURN_CARD);
	KillTimer(IDI_THROW_CARD_RESULT);

	//隐藏控件
	m_GameClientView.m_btOutCard.ShowWindow(SW_HIDE);
	m_GameClientView.m_CallCardWnd.ShowWindow(SW_HIDE);
	m_GameClientView.m_btOutPrompt.ShowWindow(SW_HIDE);
	m_GameClientView.m_btSendConceal.ShowWindow(SW_HIDE);
	m_GameClientView.m_btSendConceal.EnableWindow(FALSE);
	m_GameClientView.m_CallCardWnd.ShowWindow(SW_HIDE);
	m_GameClientView.m_btKouWang.ShowWindow(SW_HIDE);
	m_GameClientView.m_btGiveUp.ShowWindow(SW_HIDE);
	m_GameClientView.m_btKouWang.ShowWindow(SW_HIDE);
	m_GameClientView.m_btGiveUp.ShowWindow(SW_HIDE);


	//控制界面
	m_GameClientView.m_btConcealCard.EnableWindow(FALSE);
	m_GameClientView.m_btLastTurnCard.EnableWindow(FALSE);
	m_GameClientView.m_ConcealCardView.ShowWindow(SW_HIDE);
	m_GameClientView.m_ConcealCardView.SetConcealCard(NULL,0);

	//设置控件
	SwitchToCurrentCard();
	SwitchToThrowResult();
	m_GameClientView.SetWaitConceal(false);
	m_GameClientView.m_btOutCard.EnableWindow(FALSE);
	m_GameClientView.m_btKouWang.EnableWindow(FALSE);
	m_GameClientView.m_btGiveUp.EnableWindow(FALSE);

	//设置结束
	tagScoreViewInfo ScoreViewInfo;
	ScoreViewInfo.wGameScore=pGameEnd->wGameScore;
	ScoreViewInfo.wConcealTime=pGameEnd->wConcealTime;
	ScoreViewInfo.wConcealScore=pGameEnd->wConcealScore;
	ScoreViewInfo.cbConcealCount=pGameEnd->cbConcealCount;
	CopyMemory(ScoreViewInfo.cbConcealCard,pGameEnd->cbConcealCard,sizeof(BYTE)*pGameEnd->cbConcealCount);
	m_GameClientView.m_ScoreView.SetScoreViewInfo(ScoreViewInfo);

	//设置积分
	for (WORD i=0;i<GAME_PLAYER;i++)
	{
		const tagUserData * pUserData=GetUserData(i);
		m_GameClientView.m_ScoreView.SetGameScore(i,pUserData->szName,pGameEnd->lScore[i]);
	}

	//显示成绩
	m_GameClientView.m_ScoreView.ShowWindow(SW_SHOW);

	//播放声音
	WORD wMeChairID=GetMeChairID();
	LONG lMeScore=pGameEnd->lScore[GetMeChairID()];
	if (lMeScore>0L) PlayGameSound(AfxGetInstanceHandle(),TEXT("GAME_WIN"));
	else if (lMeScore<0L) PlayGameSound(AfxGetInstanceHandle(),TEXT("GAME_LOST"));
	else PlayGameSound(GetModuleHandle(NULL),TEXT("GAME_END"));

	//设置界面
	if (IsLookonMode()==false)
	{
		m_GameClientView.m_KouCardControl.ShowWindow(SW_HIDE);
		m_GameClientView.m_btStart.ShowWindow(SW_SHOW);
		//SetGameTimer(GetMeChairID(),IDI_START_GAME,TIME_START_GAME);
	}

	return true;
}

//出牌判断
bool CGameClientDlg::VerdictOutCard()
{
	//状态判断
	if (m_GameClientView.m_btOutCard.IsWindowVisible()==FALSE) return false;

	//获取扑克
	BYTE cbCardData[MAX_COUNT];
	BYTE cbShootCount=(BYTE)m_GameClientView.m_HandCardControl.GetShootCard(cbCardData,CountArray(cbCardData));

	
	//出牌判断
	if (cbShootCount>0L)
	{
		//排列扑克
		m_GameLogic.SortCardList(cbCardData,cbShootCount);

		//首出牌者
		if (m_wFirstOutUser==GetMeChairID())
		{
			//类型判断
			BYTE cbCardType=m_GameLogic.GetCardType(cbCardData,cbShootCount);
			if (cbCardType==CT_ERROR) return false;

			return true;
		}

		//跟随出牌
		BYTE cbTurnCardCount=m_cbOutCardCount[m_wFirstOutUser][0];
		bool bLegality=m_GameLogic.EfficacyOutCard(cbCardData,cbShootCount,m_cbOutCardData[m_wFirstOutUser][0],
			cbTurnCardCount,m_cbHandCardData,m_cbHandCardCount);

		return bLegality;
	}

	return false;
}

//自动出牌
bool CGameClientDlg::AutomatismOutCard()
{
	//变量定义
	tagOutCardResult OutCardResult;
	ZeroMemory(&OutCardResult,sizeof(OutCardResult));

	//搜索出牌
	BYTE cbTurnCardCount=(m_wCurrentUser==m_wFirstOutUser)?0:m_cbOutCardCount[m_wFirstOutUser][0];
	m_GameLogic.SearchOutCard(m_cbHandCardData,m_cbHandCardCount,m_cbOutCardData[m_wFirstOutUser][0],cbTurnCardCount,OutCardResult);

	//设置变量
	KillGameTimer(IDI_OUT_CARD);
	m_wCurrentUser=INVALID_CHAIR;

	//设置控件
	m_GameClientView.m_btOutCard.ShowWindow(SW_HIDE);
	m_GameClientView.m_btOutCard.EnableWindow(FALSE);
	m_GameClientView.m_btOutPrompt.ShowWindow(SW_HIDE);

	//设置扑克
	if (m_wFirstOutUser==GetMeChairID())
	{
		for (WORD i=0;i<GAME_PLAYER;i++)
		{
			if (i!=2) m_GameClientView.m_UserCardControl[i].SetCardData(NULL,0);
		}
	}
	
	//发送数据
	CMD_C_OutCard OutCard;
	OutCard.cbCardCount=OutCardResult.cbCardCount;
	CopyMemory(OutCard.cbCardData,OutCardResult.cbResultCard,sizeof(BYTE)*OutCard.cbCardCount);
	SendData(SUB_C_OUT_CARD,&OutCard,sizeof(OutCard)-sizeof(OutCard.cbCardData)+OutCard.cbCardCount*sizeof(BYTE));

	//预先显示
	PlayGameSound(AfxGetInstanceHandle(),TEXT("OUT_CARD"));
	m_GameClientView.m_UserCardControl[2].SetCardData(OutCard.cbCardData,OutCard.cbCardCount);

	//预先删除
	BYTE cbSourceCount=m_cbHandCardCount;
	m_cbHandCardCount-=OutCard.cbCardCount;
	m_GameLogic.RemoveCard(OutCard.cbCardData,OutCard.cbCardCount,m_cbHandCardData,cbSourceCount);

	//设置扑克
	SetHandCardControl(m_cbHandCardData,m_cbHandCardCount);

	return true;
}

//当前扑克
bool CGameClientDlg::SwitchToCurrentCard()
{
	//处理判断
	if (m_bLastTurn==false) return false;

	//环境设置
	m_bLastTurn=false;
	KillTimer(IDI_LAST_TURN_CARD);
	m_GameClientView.SetLastTurnCard(false);

	//设置扑克
	for (WORD i=0;i<GAME_PLAYER;i++)
	{
		WORD wViewChairID=SwitchViewChairID(i);
		m_GameClientView.m_UserCardControl[wViewChairID].SetCardData(m_cbOutCardData[i][0],m_cbOutCardCount[i][0]);
	}

	return true;
}

//甩牌结果
bool CGameClientDlg::SwitchToThrowResult()
{
	//处理判断
	if (m_bThrowCard==false) return false;
	if (m_wThrowCardUser==INVALID_CHAIR) return false;

	//时间设置
	KillTimer(IDI_THROW_CARD_RESULT);

	//设置界面
	WORD wViewChairID=SwitchViewChairID(m_wThrowCardUser);
	m_GameClientView.m_UserCardControl[wViewChairID].SetCardData(m_cbResultCardData,m_cbResultCardCount);

	//界面设置
	if (m_cbOutCardCount[0][1]!=0) m_GameClientView.m_btLastTurnCard.EnableWindow(TRUE);

	//设置变量
	m_bThrowCard=false;
	m_cbResultCardCount=0;
	m_wThrowCardUser=INVALID_CHAIR;
	ZeroMemory(m_cbResultCardData,sizeof(m_cbResultCardData));

	return true;
}

//更新叫牌
bool CGameClientDlg::UpdateCallCardControl()
{
	//状态过滤
	if (IsLookonMode()==true) return false;
	if (GetGameStatus()!=GS_UG_CALL) return false;

	//变量定义
	BYTE cbCallMask=CALL_NONE;
	BYTE cbCallColor=m_GameLogic.GetCardColor(m_cbCallCard);

	//辅助变量
	BYTE cbCardCount[6]={0,0,0,0,0,0};
	/*
	BYTE cbCallMaskArray[6]={CALL_FANG_KUAI,CALL_MEI_HUA,CALL_HONG_TAO,CALL_HEI_TAO,CALL_NT,CALL_NT};
	BYTE cbCallColorArray[6]={COLOR_FANG_KUAI,COLOR_MEI_HUA,COLOR_HONG_TAO,COLOR_HEI_TAO,COLOR_NT,COLOR_NT};
	*/
	BYTE cbCallMaskArray[6]={CALL_MEI_HUA,CALL_HEI_TAO,CALL_FANG_KUAI,CALL_HONG_TAO,CALL_NT,CALL_NT};
	BYTE cbCallColorArray[6]={COLOR_MEI_HUA,COLOR_HEI_TAO,COLOR_FANG_KUAI,COLOR_HONG_TAO,COLOR_NT,COLOR_NT};

	//更新调整
	if (m_wCallCardUser!=GetMeChairID())
	{
		//扑克统计
		for (BYTE i=0;i<m_cbDispatchCardCount;i++)
		{
			//获取属性
			BYTE cbCardColor=m_GameLogic.GetCardColor(m_cbDispatchCardData[i]);
			BYTE cbCardValue=m_GameLogic.GetCardValue(m_cbDispatchCardData[i]);

			//数据统计
			if (cbCardColor==COLOR_NT) cbCardCount[4+cbCardValue-0x0E]++;
			else if (cbCardValue==m_cbMainValue) cbCardCount[cbCardColor>>4]++;
		}

		//主牌控制
		for (BYTE i=0;i<CountArray(cbCardCount);i++)
		{
			//规则判断
			if ((cbCardCount[i]==0)||(cbCardCount[i]<m_cbCallCount)) continue;

			//数目判断
			if ((i<4)&&(cbCardCount[i]>m_cbCallCount))
			{
				cbCallMask|=cbCallMaskArray[i];
				continue;
			}

			//无主判断
			if ((i>=4)&&(cbCardCount[i]>m_cbCallCount)&&(cbCardCount[i]>=2))
			{
				cbCallMask|=cbCallMaskArray[i];
				continue;
			}

			//花色判断
			BYTE cbPackCount=m_GameLogic.GetPackCount();
			if ((cbCardCount[i]==cbPackCount)&&(cbCallColorArray[i]>cbCallColor))
			{
				cbCallMask|=cbCallMaskArray[i];
				continue;
			}
		}
	}
	else
	{
		//扑克统计
		BYTE cbCallCardCount=0;
		for (BYTE i=0;i<m_cbDispatchCardCount;i++)
		{
			if (m_cbDispatchCardData[i]==m_cbCallCard) cbCallCardCount++;
		}

		//叫牌控制
		if (cbCallCardCount>m_cbCallCount) cbCallMask=cbCallMaskArray[cbCallColor>>4];
	}

	//更新控制
	m_GameClientView.m_CallCardWnd.UpdateCallControl(cbCallMask);

	return true;
}

//派发扑克
bool CGameClientDlg::DispatchUserCard(BYTE cbCardData[], BYTE cbCardCount)
{
	//设置变量
	m_cbDispatchCardCount=0;
	m_cbRemnantCardCount=cbCardCount;
	CopyMemory(m_cbDispatchCardData,cbCardData,sizeof(BYTE)*cbCardCount);

	//设置定时器
	SetTimer(IDI_DISPATCH_CARD,400,NULL);

	return true;
}

//设置扑克
bool CGameClientDlg::SetHandCardControl(BYTE cbCardData[], BYTE cbCardCount)
{
	//设置过滤
	if (cbCardCount>0)
	{
		//变量定义
		BYTE cbRectifyCount=1;
		BYTE cbRectifyCard[MAX_COUNT+4]={cbCardData[0]};

		//获取属性
		BYTE cbLogicColor=m_GameLogic.GetCardLogicColor(cbCardData[0]);

		//变换扑克
		for (BYTE i=1;i<cbCardCount;i++)
		{
			//获取属性
			BYTE cbCurrentColor=m_GameLogic.GetCardLogicColor(cbCardData[i]);

			//插入判断
			if (cbCurrentColor!=cbLogicColor)
			{
				cbLogicColor=cbCurrentColor;
				cbRectifyCard[cbRectifyCount++]=255;
				cbRectifyCard[cbRectifyCount++]=cbCardData[i];
			}
			else cbRectifyCard[cbRectifyCount++]=cbCardData[i];
		}

		//设置扑克
		m_GameClientView.m_HandCardControl.SetCardData(cbRectifyCard,cbRectifyCount);

		return true;
	}
	else m_GameClientView.m_HandCardControl.SetCardData(NULL,0);

	return true;
}

//设置扑克
bool CGameClientDlg::SetBackCardControl(BYTE cbCardData[], BYTE cbCardCount)
{
	//设置过滤
	if (cbCardCount>0)
	{
		//变量定义
		BYTE cbRectifyCount=1;
		BYTE cbRectifyCard[MAX_COUNT+4]={cbCardData[0]};

		//获取属性
		BYTE cbLogicColor=m_GameLogic.GetCardLogicColor(cbCardData[0]);

		//变换扑克
		for (BYTE i=1;i<cbCardCount;i++)
		{
			//获取属性
			BYTE cbCurrentColor=m_GameLogic.GetCardLogicColor(cbCardData[i]);

			//插入判断
			if (cbCurrentColor!=cbLogicColor)
			{
				cbLogicColor=cbCurrentColor;
				cbRectifyCard[cbRectifyCount++]=255;
				cbRectifyCard[cbRectifyCount++]=cbCardData[i];
			}
			else cbRectifyCard[cbRectifyCount++]=cbCardData[i];
		}

		//设置扑克
		m_GameClientView.m_KouCardControl.SetCardData(cbRectifyCard,cbRectifyCount);

		return true;
	}
	else m_GameClientView.m_KouCardControl.SetCardData(NULL,0);

	return true;
}

//定时器消息
void CGameClientDlg::OnTimer(UINT nIDEvent)
{
	switch (nIDEvent)
	{
	case IDI_CONCEAL_CARD:		//查看底牌
		{
			//显示设置
			KillTimer(IDI_CONCEAL_CARD);
			m_GameClientView.m_ConcealCardView.ShowWindow(SW_HIDE);

			return;
		}
	case IDI_DISPATCH_CARD:		//派发扑克
		{
			//派发控制
			if (m_cbRemnantCardCount>0)
			{
				//获取属性
				BYTE cbCardColor=m_GameLogic.GetCardColor(m_cbDispatchCardData[m_cbDispatchCardCount]);
				BYTE cbCardValue=m_GameLogic.GetCardValue(m_cbDispatchCardData[m_cbDispatchCardCount]);

				//派发扑克
				m_cbRemnantCardCount--;
				m_cbDispatchCardCount++;
				m_GameLogic.SortCardList(m_cbDispatchCardData,m_cbDispatchCardCount);
				SetHandCardControl(m_cbDispatchCardData,m_cbDispatchCardCount);

				//叫牌控制
				if ((cbCardColor==COLOR_NT)||(cbCardValue==m_cbMainValue)) UpdateCallCardControl();

				//播放声音
				PlayGameSound(AfxGetInstanceHandle(),TEXT("OUT_CARD"));
			}
			
			//中止判断
			if (m_cbRemnantCardCount==0) 
			{
				//删除定时器
				KillTimer(IDI_DISPATCH_CARD);

				//环境设置
				SetGameTimer(GetMeChairID(),IDI_CALL_CARD,TIME_CALL_CARD);
				//if ((IsLookonMode()==false)&&(m_bStustee==false)) ActiveGameFrame();
			}

			return;
		}
	
	case IDI_LAST_TURN_CARD:	//上轮扑克
		{
			//还原界面
			SwitchToCurrentCard();

			return;
		}
	case IDI_THROW_CARD_RESULT:	//甩牌结果
		{
			//还原界面
			SwitchToThrowResult();

			//当前玩家
			if ((IsLookonMode()==false)&&(m_wCurrentUser==GetMeChairID()))
			{
				//if (m_bStustee==false) ActiveGameFrame();
				m_GameClientView.m_btOutCard.ShowWindow(SW_SHOW);
				m_GameClientView.m_btOutPrompt.ShowWindow(SW_SHOW);
				m_GameClientView.m_btOutCard.EnableWindow((VerdictOutCard()==true)?TRUE:FALSE);
			}

			//设置定时器
			SetGameTimer(m_wCurrentUser,IDI_OUT_CARD,TIME_OUT_CARD);

			return;
		}
	}

	__super::OnTimer(nIDEvent);
}

//开始按钮
LRESULT CGameClientDlg::OnStart(WPARAM wParam, LPARAM lParam)
{
	//设置环境
	KillGameTimer(IDI_START_GAME);

	//设置界面
	m_GameClientView.SetCardScore(0xFFFF);
	m_GameClientView.SetWaitConceal(false);
	m_GameClientView.SetBankerUser(INVALID_CHAIR);
	m_GameClientView.SetCallCardInfo(INVALID_CHAIR,COLOR_ERROR,0);

	//隐藏控件
	m_GameClientView.m_btStart.ShowWindow(FALSE);
	m_GameClientView.m_ScoreView.ShowWindow(SW_HIDE);

	//底牌控制
	m_GameClientView.m_btConcealCard.EnableWindow(FALSE);
	m_GameClientView.m_ConcealCardView.ShowWindow(SW_HIDE);
	m_GameClientView.m_ConcealCardView.SetConcealCard(NULL,0);

	//设置扑克
	SetHandCardControl(NULL,0);
	m_GameClientView.m_CardScore.SetCardData(NULL,0);
	m_GameClientView.m_HandCardControl.SetPositively(false);
	m_GameClientView.m_KouCardControl.SetPositively(false);
	for (WORD i=0;i<GAME_PLAYER;i++) m_GameClientView.m_UserCardControl[i].SetCardData(NULL,0);

	//发送消息
	SendUserReady(NULL,0);

	return 0;
}

//出牌消息
LRESULT CGameClientDlg::OnOutCard(WPARAM wParam, LPARAM lParam)
{
	//状态判断
	if (m_GameClientView.m_btOutCard.IsWindowEnabled()==FALSE) return 0;
	if (m_GameClientView.m_btOutCard.IsWindowVisible()==FALSE) return 0;

	//设置变量
	KillGameTimer(IDI_OUT_CARD);
	m_wCurrentUser=INVALID_CHAIR;

	//设置控件
	m_GameClientView.m_btOutCard.ShowWindow(SW_HIDE);
	m_GameClientView.m_btOutCard.EnableWindow(FALSE);
	m_GameClientView.m_btOutPrompt.ShowWindow(SW_HIDE);

	//设置扑克
	if (m_wFirstOutUser==GetMeChairID())
	{
		for (WORD i=0;i<GAME_PLAYER;i++)
		{
			if (i!=2) m_GameClientView.m_UserCardControl[i].SetCardData(NULL,0);
		}
	}
	
	//发送数据
	CMD_C_OutCard OutCard;
	OutCard.cbCardCount=(BYTE)m_GameClientView.m_HandCardControl.GetShootCard(OutCard.cbCardData,CountArray(OutCard.cbCardData));
	m_GameLogic.SortCardList(OutCard.cbCardData,OutCard.cbCardCount);
	SendData(SUB_C_OUT_CARD,&OutCard,sizeof(OutCard)-sizeof(OutCard.cbCardData)+OutCard.cbCardCount*sizeof(BYTE));

	//预先显示
	PlayGameSound(AfxGetInstanceHandle(),TEXT("OUT_CARD"));
	m_GameClientView.m_UserCardControl[2].SetCardData(OutCard.cbCardData,OutCard.cbCardCount);

	//预先删除
	BYTE cbSourceCount=m_cbHandCardCount;
	m_cbHandCardCount-=OutCard.cbCardCount;
	m_GameLogic.RemoveCard(OutCard.cbCardData,OutCard.cbCardCount,m_cbHandCardData,cbSourceCount);

	//设置扑克
	SetHandCardControl(m_cbHandCardData,m_cbHandCardCount);

	return 0;
}

//叫牌消息
LRESULT CGameClientDlg::OnCallCard(WPARAM wParam, LPARAM lParam)
{
	//变量定义
	BYTE cbCallCount=0;
	BYTE cbCallCard=0x00;
	BYTE cbCallColor=(BYTE)lParam;

	//数据统计
	if (cbCallColor==COLOR_NT)
	{
		//数目统计
		BYTE cbNTCount[2]={0,0};
		for (BYTE i=0;i<m_cbDispatchCardCount;i++)
		{
			BYTE cbCardData=m_cbDispatchCardData[i];
			if ((cbCardData==0x4E)||(cbCardData==0x4F)) cbNTCount[cbCardData-0x4E]++;
		}

		//叫牌数据
		if (cbNTCount[0]>=cbNTCount[1])
		{
			cbCallCard=0x4E;
			cbCallCount=cbNTCount[0];
		}
		else
		{
			cbCallCard=0x4F;
			cbCallCount=cbNTCount[1];
		}
	}
	else
	{
		//数目统计
		for (BYTE i=0;i<m_cbDispatchCardCount;i++)
		{
			//获取属性
			BYTE cbCardData=m_cbDispatchCardData[i];
			BYTE cbCardColor=m_GameLogic.GetCardColor(cbCardData);
			BYTE cbCardValue=m_GameLogic.GetCardValue(cbCardData);

			//数据统计
			if ((cbCardValue==m_cbMainValue)&&(cbCardColor==cbCallColor)) 
			{
				cbCallCount++;
				cbCallCard=cbCardData;
			}
		}
	}

	//更新界面
	m_GameClientView.m_CallCardWnd.UpdateCallControl(CALL_NONE);

	//构造数据
	CMD_C_CallCard CallCard;
	CallCard.cbCallCard=cbCallCard;
	CallCard.cbCallCount=cbCallCount;

	//发送数据
	SendData(SUB_C_CALL_CARD,&CallCard,sizeof(CallCard));

	return 0;
}

//出牌提示
LRESULT CGameClientDlg::OnOutPrompt(WPARAM wParam, LPARAM lParam)
{
	//变量定义
	tagOutCardResult OutCardResult;
	ZeroMemory(&OutCardResult,sizeof(OutCardResult));

	//搜索出牌
	BYTE cbTurnCardCount=(m_wCurrentUser==m_wFirstOutUser)?0:m_cbOutCardCount[m_wFirstOutUser][0];
	bool bSuccess=m_GameLogic.SearchOutCard(m_cbHandCardData,m_cbHandCardCount,m_cbOutCardData[m_wFirstOutUser][0],cbTurnCardCount,OutCardResult);

	//失败判断
	if (bSuccess==false)
	{
		InsertSystemString(TEXT("自动提示出牌错误，请你把此状态信息截图并给我们提供，谢谢！"));
		return false;
	}

	//设置界面
	m_GameClientView.m_btOutCard.EnableWindow(TRUE);
	m_GameClientView.m_HandCardControl.SetShootCard(OutCardResult.cbResultCard,OutCardResult.cbCardCount);

	return 0;
}

//留底消息
LRESULT CGameClientDlg::OnSendConceal(WPARAM wParam, LPARAM lParam)
{
	//获取扑克
	BYTE cbCardData[MAX_COUNT];
	BYTE cbCardCount=(BYTE)m_GameClientView.m_HandCardControl.GetShootCard(cbCardData,CountArray(cbCardData));

	//删除扑克
	m_cbHandCardCount-=cbCardCount;
	m_GameLogic.RemoveCard(cbCardData,cbCardCount,m_cbHandCardData,m_cbHandCardCount+cbCardCount);

	//设置界面
	m_GameClientView.m_btSendConceal.ShowWindow(SW_HIDE);
	m_GameClientView.m_btSendConceal.EnableWindow(FALSE);
	SetHandCardControl(m_cbHandCardData,m_cbHandCardCount);

	//构造数据
	CMD_C_ConcealCard ConcealCard;
	ConcealCard.cbConcealCount=cbCardCount;
	CopyMemory(ConcealCard.cbConcealCard,cbCardData,cbCardCount*sizeof(BYTE));

	//发送数据
	SendData(SUB_C_CONCEAL_CARD,&ConcealCard,sizeof(ConcealCard));

	return 0;
}

//扣王
LRESULT CGameClientDlg::OnKouWang(WPARAM wParam, LPARAM lParam)
{
	//调试用 ASSERT(1>5);
	
	//获取扑克
	BYTE cbKouCardData[MAX_COUNT];
	BYTE cbKouShootCount=(BYTE)m_GameClientView.m_KouCardControl.GetShootCard(cbKouCardData,CountArray(cbKouCardData));
	
	BYTE cbCardData[MAX_COUNT];
	BYTE cbShootCount=(BYTE)m_GameClientView.m_HandCardControl.GetShootCard(cbCardData,CountArray(cbCardData));

	//时间控件
	KillGameTimer(IDI_KOU);

	//设置控件
	m_GameClientView.m_HandCardControl.SetPositively(false);
	m_GameClientView.m_KouCardControl.SetPositively(false);
		
	m_GameClientView.m_btKouWang.ShowWindow(SW_HIDE);
	m_GameClientView.m_btKouWang.EnableWindow(false);
	m_GameClientView.m_btGiveUp.ShowWindow(SW_HIDE);
	m_GameClientView.m_btGiveUp.EnableWindow(false);
	//--------------------------------------------------------------------------------------------------------
	//删除手上扑克
	m_cbHandCardCount-=cbShootCount;
	m_GameLogic.RemoveCard(cbCardData,cbShootCount,m_cbHandCardData,m_cbHandCardCount+cbShootCount);

	//设置手上扑克
	CopyMemory(&m_cbHandCardData[m_cbHandCardCount],cbKouCardData,cbKouShootCount*sizeof(BYTE));
	m_cbHandCardCount+=cbKouShootCount;

	
	//设置手上扑克
	m_GameLogic.SortCardList(m_cbHandCardData,m_cbHandCardCount);
	SetHandCardControl(m_cbHandCardData,m_cbHandCardCount);
	//m_GameClientView.m_HandCardControl.SetCardData(m_cbHandCardData,m_cbHandCardCount);
	
	
	//--------------------------------------------------------------------------------------------------------

	//删除底牌扑克
	m_cbConcealCount-=cbKouShootCount;
	m_GameLogic.RemoveCard(cbKouCardData,cbKouShootCount,m_cbConcealCard,m_cbConcealCount+cbKouShootCount);

	//设置底牌扑克
	CopyMemory(&m_cbConcealCard[m_cbConcealCount],cbCardData,cbShootCount*sizeof(BYTE));
	m_cbConcealCount+=cbShootCount;

	//设置底牌扑克
	//m_GameLogic.SortCardList(m_cbConcealCard,m_cbConcealCount);
	//SetBackCardControl(m_cbConcealCard,m_cbConcealCount);
	m_GameClientView.m_KouCardControl.SetCardData(m_cbConcealCard,m_cbConcealCount);

	//--------------------------------------------------------------------------------------------------------
	//构造数据
	CMD_C_KouWang KouWang;
	KouWang.cbConcealCount=m_cbConcealCount;
	CopyMemory(KouWang.cbConcealCard,m_cbConcealCard,m_cbConcealCount*sizeof(BYTE));
	KouWang.cbUserCardCount=m_cbHandCardCount;
	CopyMemory(KouWang.cbUserCardData,m_cbHandCardData,m_cbHandCardCount*sizeof(BYTE));

	//发送数据
	SendData(SUB_C_KOU_WANG,&KouWang,sizeof(KouWang));

	return 0;
}

//放弃
LRESULT CGameClientDlg::OnGiveUp(WPARAM wParam, LPARAM lParam)
{
	//设置界面
	KillGameTimer(IDI_KOU);

	//设置控件
	m_GameClientView.m_btKouWang.ShowWindow(SW_HIDE);
	m_GameClientView.m_btKouWang.EnableWindow(false);
	m_GameClientView.m_btGiveUp.ShowWindow(SW_HIDE);
	m_GameClientView.m_btGiveUp.EnableWindow(false);

	//构造数据
	CMD_C_KouWang KouWang;
	KouWang.cbConcealCount=m_cbConcealCount;
	CopyMemory(KouWang.cbConcealCard,m_cbConcealCard,m_cbConcealCount*sizeof(BYTE));
	KouWang.cbUserCardCount=m_cbHandCardCount;
	CopyMemory(KouWang.cbUserCardData,m_cbHandCardData,m_cbHandCardCount*sizeof(BYTE));

	//发送数据
	SendData(SUB_C_KOU_WANG,&KouWang,sizeof(KouWang));
	return 0;
}

//查看底牌
LRESULT CGameClientDlg::OnConcealCard(WPARAM wParam, LPARAM lParam)
{
	//查看设置
	if (m_GameClientView.m_ConcealCardView.IsWindowVisible())
	{
		KillTimer(IDI_CONCEAL_CARD);
		m_GameClientView.m_ConcealCardView.ShowWindow(SW_HIDE);
	}
	else
	{
		SetTimer(IDI_CONCEAL_CARD,5000,NULL);
		m_GameClientView.m_ConcealCardView.ShowWindow(SW_SHOW);
	}

	return 0;
}

//请求离开
LRESULT CGameClientDlg::OnRuquestLeave(WPARAM wParam, LPARAM lParam)
{
	return 0;
}

//上轮扑克
LRESULT CGameClientDlg::OnLastTurnCard(WPARAM wParam, LPARAM lParam)
{
	if (m_bLastTurn==false)
	{
		//设置扑克
		for (WORD i=0;i<GAME_PLAYER;i++)
		{
			WORD wViewChairID=SwitchViewChairID(i);
			m_GameClientView.m_UserCardControl[wViewChairID].SetCardData(m_cbOutCardData[i][1],m_cbOutCardCount[i][1]);
		}

		//环境设置
		m_bLastTurn=true;
		m_GameClientView.SetLastTurnCard(true);
		SetTimer(IDI_LAST_TURN_CARD,3000,NULL);
	}
	else SwitchToCurrentCard();

	return 0;
}

//拖管控制
LRESULT CGameClientDlg::OnStusteeControl(WPARAM wParam, LPARAM lParam)
{
	//设置状态
	if (m_bStustee==true)
	{
		m_bStustee=false;
		//m_GameClientView.m_btStusteeControl.SetButtonImage(IDB_START_TRUSTEE,AfxGetInstanceHandle(),false);
	}
	else
	{
		m_bStustee=true;
		//m_GameClientView.m_btStusteeControl.SetButtonImage(IDB_STOP_TRUSTEE,AfxGetInstanceHandle(),false);
	}

	return 0;
}

//左键扑克
LRESULT CGameClientDlg::OnLeftHitCard(WPARAM wParam, LPARAM lParam)
{
	//获取状态
	BYTE cbGameStatue=GetGameStatus();

	//留底状态
	switch (cbGameStatue)
	{
	case GS_UG_BACK:	//留底状态
		{
			//状态控制
			if ((IsLookonMode()==false)&&(m_wCurrentUser==GetMeChairID()))
			{
				//获取扑克
				BYTE cbCardData[MAX_COUNT];
				BYTE cbCardCount=(BYTE)m_GameClientView.m_HandCardControl.GetShootCard(cbCardData,CountArray(cbCardData));

				//控制按钮
				m_GameClientView.m_btSendConceal.EnableWindow((cbCardCount==m_cbConcealCount)?TRUE:FALSE);
			}

			return 0;
		}
	case GS_UG_KOU:	//扣王状态
		{
			m_GameClientView.m_btKouWang.EnableWindow(false);
			//状态控制
			if ((IsLookonMode()==false)&&(m_wNextUser==GetMeChairID()))
			{
				
				//获取扑克
				BYTE cbCardData[MAX_COUNT];
				BYTE cbCardCount=(BYTE)m_GameClientView.m_HandCardControl.GetShootCard(cbCardData,CountArray(cbCardData));
				
				BYTE cbKouCardData[MAX_COUNT];
				BYTE cbKouCardCount=(BYTE)m_GameClientView.m_KouCardControl.GetShootCard(cbKouCardData,CountArray(cbKouCardData));

				bool bFlagNum=false,bFlagKing=false,bFlagCard=false;

				//匹配扣王扑克与手中选择扑克数量是否相等
				if(cbCardCount==cbKouCardCount)
				{
					bFlagNum=true;
			
					//不为大小王
					for(byte i=0;i<cbCardCount;i++)
					{
						BYTE bTempValue=m_GameLogic.GetCardValue(cbCardData[i]);
						if(bTempValue==14||bTempValue==15) bFlagKing=true;
					}
					
					//匹配条件：大于10。不等于5，10，K。不是主牌，只能扣大小王
					for(byte i=0;i<cbKouCardCount;i++)
					{
						if(m_GameLogic.GetCardColor(cbKouCardData[i])!=m_cbMainColor&&m_GameLogic.GetCardValue(cbKouCardData[i])!=m_cbMainValue&&m_GameLogic.GetCardValue(cbKouCardData[i])!=5&&m_GameLogic.GetCardValue(cbKouCardData[i])<=9) bFlagCard=true;
					}
					
					if((bFlagNum==true)&&(bFlagKing==true)&&(bFlagCard==true))
					{
						m_GameClientView.m_btKouWang.EnableWindow(true);
					}
					else
					{
						m_GameClientView.m_btKouWang.EnableWindow(false);
					}
				}  
				
			}

			return 0;
		}
	case GS_UG_PLAY:	//游戏状态
		{
			//设置控件
			bool bOutCard=VerdictOutCard();
			m_GameClientView.m_btOutCard.EnableWindow(bOutCard?TRUE:FALSE);

			return 0;
		}
	}

	return 0;
}

//右键扑克
LRESULT CGameClientDlg::OnRightHitCard(WPARAM wParam, LPARAM lParam)
{
	//用户出牌
	OnOutCard(0,0);

	return 0;
}

//////////////////////////////////////////////////////////////////////////
