#ifndef TABLE_FRAME_SINK_HEAD_FILE
#define TABLE_FRAME_SINK_HEAD_FILE

#pragma once

#include "Stdafx.h"
#include <vector>

//////////////////////////////////////////////////////////////////////////
//历史记录
#define MAX_SCORE_HISTORY			16									//历史个数
//////////////////////////////////////////////////////////////////////////
//玩家信息
struct tagApplyUserInfo
{
	DWORD							dwUserID;							//玩家ID
	WORD							wChairID;							//椅子号码
	LONGLONG						lUserScore;							//玩家积分
};

typedef CArrayTemplate< tagApplyUserInfo > ApplyUserArrary;

//游戏桌子类
class CTableFrameSink : public ITableFrameSink, public ITableUserAction
{
	//下注信息
protected:
	INT64						m_lAreaLimitScore;						//区域限制

	//玩家成绩
protected:
	INT64						m_lUserWinScore[GAME_PLAYER];			//玩家成绩
	INT64						m_lUserReturnScore[GAME_PLAYER];		//返回下注

	tagScoreInfo				m_ScoreInfo[GAME_PLAYER];
	BOOL						m_bneedWriteTable;

	//状态变量
protected:
	DWORD						m_dwJettonTime;							//开始时间

	//庄家信息
protected:
	INT64						m_lApplyBankerCondition;				//申请条件
	ApplyUserArrary				m_ApplyUserArrary;						//申请列表
	tagApplyUserInfo			m_CurrentBanker;						//当前庄家
	BYTE						m_cbBankerTimer;						//做庄次数
	INT64						m_lBankerWinScore;						//庄家成绩
	bool						m_bCancelBanker;						//玩家下庄
	INT64                       m_lMaxBankerTimer;                      //最大次数
	bool						m_bBankerLeft;
	CString						m_strFileName;

//////////////////////////////////////////////////////////////////////////
	LONGLONG					m_nUserBet[GAME_PLAYER][MAX_AREA];
	LONGLONG					m_nMaxCanBet;
	BYTE						m_cbResult;	//结果

//////////////////////////////////////////////////////////////////////////

	//组件变量
protected:
	ITableFrame					* m_pITableFrame;						//框架接口
	ITableFrameControl			* m_pITableFrameControl;				//框架接口
	const tagGameServiceOption	* m_pGameServiceOption;					//配置参数

	//属性变量
protected:
	static const WORD			m_wPlayerCount;							//游戏人数
	static const enStartMode	m_GameStartMode;						//开始模式

//	CSystemLog					m_systemLog;
	//函数定义
public:
	//构造函数
	CTableFrameSink();
	//析构函数
	virtual ~CTableFrameSink();

	//基础接口
public:
	//释放对象
	virtual VOID __cdecl Release() { if (IsValid()) delete this; return ; }
	//是否有效
	virtual bool __cdecl IsValid() { return AfxIsValidAddress(this,sizeof(CTableFrameSink))?true:false; }
	//接口查询
	virtual void * __cdecl QueryInterface(const IID & Guid, DWORD dwQueryVer);

	//管理接口
public:
	//初始化
	virtual bool __cdecl InitTableFrameSink(IUnknownEx * pIUnknownEx);
	//复位桌子
	virtual void __cdecl RepositTableFrameSink();

	//信息接口
public:
	//开始模式
	virtual enStartMode __cdecl GetGameStartMode();
	//游戏状态
	virtual bool __cdecl IsUserPlaying(WORD wChairID);

	//游戏事件
public:
	//游戏开始
	virtual bool __cdecl OnEventGameStart();
	//游戏结束
	virtual bool __cdecl OnEventGameEnd(WORD wChairID, IServerUserItem * pIServerUserItem, BYTE cbReason);
	//发送场景
	virtual bool __cdecl SendGameScene(WORD wChiarID, IServerUserItem * pIServerUserItem, BYTE cbGameStatus, bool bSendSecret);

	//事件接口
public:
	//定时器事件
	virtual bool __cdecl OnTimerMessage(WORD wTimerID, WPARAM wBindParam);
	//游戏消息处理
	virtual bool __cdecl OnGameMessage(WORD wSubCmdID, const void * pDataBuffer, WORD wDataSize, IServerUserItem * pIServerUserItem);
	//框架消息处理
	virtual bool __cdecl OnFrameMessage(WORD wSubCmdID, const void * pDataBuffer, WORD wDataSize, IServerUserItem * pIServerUserItem);

	//请求事件
public:
	//请求同意
	virtual bool __cdecl OnEventUserReqReady(WORD wChairID, IServerUserItem * pIServerUserItem) { return true; }
	//请求断线
	virtual bool __cdecl OnEventUserReqOffLine(WORD wChairID, IServerUserItem * pIServerUserItem) { return true; }
	//请求重入
	virtual bool __cdecl OnEventUserReqReConnect(WORD wChairID, IServerUserItem * pIServerUserItem) { return true; }
	//请求坐下
	virtual bool __cdecl OnEventUserReqSitDown(WORD wChairID, IServerUserItem * pIServerUserItem, bool bReqLookon) { return true; }
	//请求起来
	virtual bool __cdecl OnEventUserReqStandUp(WORD wChairID, IServerUserItem * pIServerUserItem, bool bReqLookon) { return true; }

	//动作事件
public:
	//用户断线
	virtual bool __cdecl OnActionUserOffLine(WORD wChairID, IServerUserItem * pIServerUserItem) ;
	//用户重入
	virtual bool __cdecl OnActionUserReConnect(WORD wChairID, IServerUserItem * pIServerUserItem){ return true; }
	//用户坐下
	virtual bool __cdecl OnActionUserSitDown(WORD wChairID, IServerUserItem * pIServerUserItem, bool bLookonUser);
	//用户起来
	virtual bool __cdecl OnActionUserStandUp(WORD wChairID, IServerUserItem * pIServerUserItem, bool bLookonUser);
	//用户同意
	virtual bool __cdecl OnActionUserReady(WORD wChairID, IServerUserItem * pIServerUserItem, VOID * pData, WORD wDataSize){ return true; }
	//银行动作
	virtual bool __cdecl OnActionUserBank(WORD wChairID, IServerUserItem * pIServerUserItem, BYTE cbBankType) { return true; }

	//游戏事件
protected:
	//加注事件
	bool OnUserPlaceJetton(WORD wChairID, BYTE cbJettonArea, BYTE cbAnimal, INT64 lJettonScore);
	//申请庄家
	bool OnUserApplyBanker( tagServerUserData *pUserData, bool bApplyBanker );

	//辅助函数
private:

	//发送庄家
	void SendApplyUser( IServerUserItem *pServerUserItem );
	//游戏记录
	void SendGameRecord(IServerUserItem *pIServerUserItem);
	//更换庄家
	void ChangeBanker();
	//轮换庄家
	void SendChangeBankerMsg();
};

//////////////////////////////////////////////////////////////////////////

#endif