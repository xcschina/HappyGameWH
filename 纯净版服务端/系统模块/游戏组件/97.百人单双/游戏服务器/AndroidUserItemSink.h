#ifndef ANDROID_USER_ITEM_SINK_HEAD_FILE
#define ANDROID_USER_ITEM_SINK_HEAD_FILE

#pragma once

#include "Stdafx.h"


//////////////////////////////////////////////////////////////////////////

//机器人类
class CAndroidUserItemSink : public IAndroidUserItemSink
{
	//限制信息
protected:
	LONG							m_lMeMaxScore;						//最大下注
	LONG							m_lAreaLimitScore;					//区域限制
	LONG							m_lApplyBankerCondition;			//申请条件

	//个人下注
protected:
	LONG							m_lMeTieScore;						//买平总注
	LONG							m_lMeBankerScore;					//买庄总注
	LONG							m_lMePlayerScore;					//买闲总注
	LONG							m_lMeTieSamePointScore;				//同点平注
	LONG							m_lMePlayerKingScore;				//闲天王注
	LONG							m_lMeBankerKingScore;				//庄天王注
	LONG							m_lMePlayerTwoPair;					//对子下注
	LONG							m_lMeBankerTwoPair;					//对子下注

	//庄家信息
protected:
	LONG							m_lBankerScore;						//庄家积分
	WORD							m_wCurrentBanker;					//当前庄家
	INT								m_nApplyUserCount;					//申请数目
	WORD							m_wServerID;			

	//状态变量
protected:
	bool							m_bMeApplyBanker;					//申请标识
	INT								m_nMeBankerCount;					//当庄次数
	INT								m_nMePlayerCount;					//闲家次数
	bool							m_bCancelBanker;					//取消庄家

	//控制变量
protected:
	bool							m_bEnableAndroidUserBanker;			//允许做庄
	TCHAR							m_szConfigFileName[MAX_PATH];		//配置文件
	INT								m_nAndroidUserBankerCount;			//当庄次数
	INT								m_nAndroidUserPlayerCount;			//当庄次数
	INT								m_nMinApplyBankerCount;				//当庄数目

	//控件变量
protected:
	IAndroidUserItem *				m_pIAndroidUserItem;				//用户接口
    static  WORD					m_wAndroidApplyBankerCount;			//机器人申请上庄数量
	static	BOOL					m_blApply;
	bool							m_blInUserArray;

	//函数定义
public:
	//构造函数
	CAndroidUserItemSink();
	//析构函数
	virtual ~CAndroidUserItemSink();

	//基础接口
public:
	//释放对象
	virtual VOID __cdecl Release() { }
	//是否有效
	virtual bool __cdecl IsValid() { return AfxIsValidAddress(this,sizeof(CAndroidUserItemSink))?true:false; }
	//接口查询
	virtual void * __cdecl QueryInterface(const IID & Guid, DWORD dwQueryVer);

	//控制接口
public:
	//初始接口
	virtual bool __cdecl InitUserItemSink(IUnknownEx * pIUnknownEx);
	//重置接口
	virtual bool __cdecl RepositUserItemSink();

	//游戏事件
public:
	//时间消息
	virtual bool __cdecl OnEventTimer(UINT nTimerID);
	//游戏消息
	virtual bool __cdecl OnEventGameMessage(WORD wSubCmdID, void * pData, WORD wDataSize);
	//游戏消息
	virtual bool __cdecl OnEventFrameMessage(WORD wSubCmdID, void * pData, WORD wDataSize);
	//场景消息
	virtual bool __cdecl OnEventGameScene(BYTE cbGameStatus, bool bLookonOther, void * pData, WORD wDataSize);

	//用户事件
public:
	//用户进入
	virtual void __cdecl OnEventUserEnter(IAndroidUserItem * pIAndroidUserItem, bool bLookonUser);
	//用户离开
	virtual void __cdecl OnEventUserLeave(IAndroidUserItem * pIAndroidUserItem, bool bLookonUser);
	//用户积分
	virtual void __cdecl OnEventUserScore(IAndroidUserItem * pIAndroidUserItem, bool bLookonUser);
	//用户状态
	virtual void __cdecl OnEventUserStatus(IAndroidUserItem * pIAndroidUserItem, bool bLookonUser);
	//用户段位
	virtual void __cdecl OnEventUserSegment(IAndroidUserItem * pIAndroidUserItem, bool bLookonUser);

	//辅助函数
private:
	//个人下注
	void SetMePlaceJetton(BYTE cbViewIndex, LONGLONG lJettonCount);
	//设置庄家
	void SetBankerInfo(WORD wBanker,LONGLONG lScore);

	//游戏消息
private:
	//游戏开始
	bool OnSubGameStart(const void * pBuffer, WORD wDataSize);
	//游戏空闲
	bool OnSubGameFree(const void * pBuffer, WORD wDataSize);
	//游戏结束
	bool OnSubGameEnd(const void * pBuffer, WORD wDataSize);	
	//切换庄家
	bool OnSubChangeBanker(const void * pBuffer, WORD wDataSize);
	//申请做庄
	bool OnSubUserApplyBanker(const void * pBuffer, WORD wDataSize);
	//取消做庄
	bool OnSubUserCancelBanker(const void * pBuffer, WORD wDataSize);
	////申请坐庄失败
	//bool OnSubUserApplyFail(const void * pBuffer, WORD wDataSize);
};

//////////////////////////////////////////////////////////////////////////

#endif
