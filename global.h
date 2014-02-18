
#pragma once

#include "pugixml.hpp"
#include "XListCtrl/XTrace.h"
#include "DIYCtrl/color.h"
#include "base64.h"
#include "DIYCtrl/ColorStatic.h"
#include "DIYCtrl/NumSpinCtrl.h"
#include "XListCtrl/XListCtrl.h"
#include "DIYCtrl/XPGroupBox.h"
#include "DIYCtrl/MyCombo.h"
#include "DIYCtrl/ComboEx.h"
#include "DIYCtrl/MMStatusBar.h"

#define ENABLE_XLISTCTRL_TRACE
#define XLISTCTRLLIB_STATIC
#define DO_NOT_INCLUDE_XCOMBOLIST

//#include <omp.h>

#ifndef __noop
#if _MSC_VER < 1300
#define __noop ((void)0)
#endif
#endif

#ifdef ENABLE_XLISTCTRL_TRACE
#define XLISTCTRL_TRACE TRACE
#else
#define XLISTCTRL_TRACE __noop
#endif

#include "api_libs/ThostFtdcMdApi.h"
#include "api_libs/ThostFtdcTraderApi.h"
#pragma comment(lib,"api_libs/thostmduserapi.lib")
#pragma comment(lib,"api_libs/thosttraderapi.lib")
#pragma comment(lib,"shlwapi.lib")
#pragma comment(lib,"ws2_32.lib")

#include <iostream>
#include <vector>
#include <algorithm>
#include <XUTILITY>
#include <AFXTEMPL.H>

#include "DelayMsgBox.h"

///合约保证金率
typedef CThostFtdcInstrumentMarginRateField MGRATE,*PMGRATE;
///合约手续费率
typedef CThostFtdcInstrumentCommissionRateField FEERATE,*PFEERATE;

using namespace std;
using namespace pugi;

typedef CThostFtdcInstrumentField INSTINFO,*PINSTINFO;

typedef struct CThostFtdcInstrumentFieldEx
{
	INSTINFO iinf;
	TThostFtdcRatioType	OpenRatioByMoney;
	TThostFtdcRatioType	OpenRatioByVolume;
	TThostFtdcRatioType	CloseRatioByMoney;
	TThostFtdcRatioType	CloseRatioByVolume;
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	TThostFtdcRatioType	CloseTodayRatioByVolume;
}INSINFEX,*PINSINFEX;

typedef struct BkrPara
{
	TCHAR XmlPath[MAX_PATH];
	TCHAR BkrName[64];
	char BkrId[11];
}BKRPARA,*PBKRPARA;

typedef struct ClientInf
{
	TThostFtdcFrontIDType	FrtID;
	TThostFtdcSessionIDType	SesID;
	TCHAR ProdInf[11];
}CLINFO,*PCLINFO;

typedef struct LoginPara
{
	TThostFtdcInvestorIDType szUid;
	TThostFtdcPasswordType szPass;
	int iBkrGroup;
	int iSvrGroup;
}LOGINPARA,*PLOGINPARA;

typedef vector<CThostFtdcOrderField*> ::iterator VOrd;
typedef vector<CThostFtdcInvestorPositionField*> ::iterator VInvP;
typedef vector<CThostFtdcInstrumentFieldEx*>::iterator VIT_if;
typedef vector<CThostFtdcInstrumentMarginRateField*>::iterator VIT_mr;
typedef vector<CThostFtdcInstrumentCommissionRateField*>::iterator VIT_cf;

#define _REAL_CTP_

#define PROD_INFO "xTrader v2"
#define DBL_MAX 1.7976931348623158e+308 
#define DBL_MIN 2.2250738585072014e-308
#define CFMMC_TMPL "https://investorservice.cfmmc.com/loginByKey.do?companyID=%s&userid=%s&keyid=%d&passwd=%s"
#define CFG_FILE _T("config.xml")
#define FEE_XML "fee_%s.xml"
#define MGR_XML "mgr_%s.xml"
//#define SIDS _T("sids.xml")
#define AUTHOR _T("t0trader")
#define MY_TIPS _T("提示信息")
#define _QNA _T("软件说明")
#define _GERR _T("错误")
#define  ACC_DETAILS _T("期货资金账户详情")
#define  BKACC_LEFT _T("银行资金账户")
#define BFTRANS_TITLE _T("银期转账@%s")
#define CONN_ERR _T("连接失败")
#define  ACC_FBINFO _T("开户信息")
#define USER_ID "LoginUserID"
#define BKR_GRP "BrokerGroup"
#define SV_GRP "ServerGroup"
#define SV_INF "SaveInfo"
#define USER_PW "UserPassword"
#define NTP_SVR "NtpServer"
#define WND_INF "WndInfo"
#define INS_LST "InstList"
#define ROOT "root"
//#define SESRT "sessions"
//#define SESITEM "session"
#define WAIT_MS	10000
#define BKRS_DIR _T("brokers\\*.*")
#define INSERT_OP (-1)

#define _CZCE _T("郑商所")
#define _DCE _T("大商所")
#define _SHFE _T("上期所")
#define _CFFEX _T("中金所")

#define REFRESH_TIMER 100
#define SYNC_TIMER 101

#define DIR_BUY _T("买")
#define DIR_SELL _T("卖")

#define ORD_O _T("开仓")
#define ORD_C _T("平仓")
#define ORD_CT _T("平今")

#define INVPOS_ITMES 8
#define ONROAD_ITMES 8
#define TRADE_ITMES 12
#define ORDER_ITMES 14
#define ALLINST_ITMES 10

#define UNCOMP _T("待完成")

#define  DEL(p)  { delete p; p = NULL; }
#define DELX(p) { delete[] p; p = NULL; }

#ifdef _UNICODE
#define BTPERCHAR 2
#else
#define BTPERCHAR 1
#endif

#define WM_UPDATEMD_MSG (WM_USER+1)

const UINT WM_TASKBARCREATED = ::RegisterWindowMessage(_T("TaskbarCreated"));
const UINT WM_SYNCTIME = ::RegisterWindowMessage(_T("SyncTime_Client"));
const UINT WM_QRYACC_MSG = ::RegisterWindowMessage(_T("QryAcc_Msg"));
const UINT WM_QRYBFLOG_MSG = ::RegisterWindowMessage(_T("QryBFLog_Msg"));
const UINT WM_QRYUSER_MSG = ::RegisterWindowMessage(_T("QryUser_Msg"));
const UINT WM_QRYBKYE_MSG = ::RegisterWindowMessage(_T("QryBkYe_Msg"));
const UINT WM_QRYSMI_MSG = ::RegisterWindowMessage(_T("QrySmi_Msg"));

inline COLORREF CmpPriceColor(double d1,double d2)
{
	COLORREF clorf = WHITE;
	if (d1>d2) { clorf=RED; }
	if (d1<d2) { clorf=GREEN; }

	return clorf;
}

inline void  Tokenize(CString str, CString strDelimits, CStringArray& strArray,BOOL bTrim, CString nullSubst)
{
	ASSERT( !str.IsEmpty() && !strDelimits.IsEmpty() );

	strArray.RemoveAll();

	str += strDelimits[0];
	for( long index = -1; (index=str.FindOneOf((LPCTSTR)strDelimits))!=-1; )
	{
		if(index != 0) 
		strArray.Add( str.Left(index) );
		else if(!bTrim) 
		strArray.Add(nullSubst);
		str = str.Right(str.GetLength()-index-1);
	}
}  


inline void getCurTime(CString& strIn)
{
	SYSTEMTIME tm;

	::GetLocalTime(&tm);
	strIn.Format(_T("%02d:%02d:%02d"), tm.wHour, tm.wMinute, tm.wSecond);
}

inline void getCurTime(TThostFtdcTimeType& InsTm)
{
	SYSTEMTIME tm;
	
	::GetLocalTime(&tm);
	sprintf(InsTm,"%02d:%02d:%02d", tm.wHour, tm.wMinute, tm.wSecond);
}

inline void Fee2String(CString& szIn,double dOpenByM,double dOpenByV,double dCloseByM,
						  double dCloseByV,double dClosetByM,double dClosetByV)
{
	CString szOut =_T("￥0.0");


	if ((dOpenByV>0) && (dOpenByV==dCloseByV))
	{
		if (dCloseByV==dClosetByV)
		{
			szOut.Format(_T("￥%.2f/手"),dOpenByV);
		}
		else if (dClosetByV==0)
		{
			szOut.Format(_T("开平￥%.2f/手,平今免"),dOpenByV);
		}
				
	}
	else if ((dOpenByM>0) && (dOpenByM==dCloseByM))
	{
		if (dCloseByM==dClosetByM)
		{
			szOut.Format(_T("%.2f%%%%"),dOpenByM*10000);
		}
		else if ((dOpenByM>0) && (dOpenByM==dCloseByM) && (dClosetByM>0))
		{
			szOut.Format(_T("开平%.2f%%%%,平今%.2f%%%%"),dOpenByM*10000,dClosetByM*10000);
		}
		else
			szOut.Format(_T("开平%.2f%%%%,平今免"),dOpenByM*10000);
		
	}

	szIn = szOut;
}

inline void JgTdStatus(CString& szIn,BYTE bType)
{
	szIn =_T("");

	switch(bType)
	{
	case THOST_FTDC_IS_BeforeTrading:
		szIn = _T("开盘前");
		break;
	case THOST_FTDC_IS_NoTrading:
		szIn = _T("非交易");
		break;
	case THOST_FTDC_IS_Continous:
		szIn = _T("连续交易");
		break;
	case THOST_FTDC_IS_AuctionOrdering:
		szIn = _T("集合竞价报单");
		break;
	case THOST_FTDC_IS_AuctionBalance:
		szIn = _T("集合竞价价格平衡");
		break;
	case THOST_FTDC_IS_AuctionMatch:
		szIn = _T("集合竞价撮合");
		break;
	case THOST_FTDC_IS_Closed:
		szIn = _T("收盘");
		break;
	default:
		szIn = _T("未知");
		break;
	}

}

inline BOOL SetHighPriority()
{
	if(!SetPriorityClass( GetCurrentProcess(), HIGH_PRIORITY_CLASS))
	{
		return TRUE;
	}
	return FALSE;
}

inline CString FormatLine(CString szItem,CString szValue,CString szFill,int iTotalLen)
{
	CString szOut = _T("");
	if (szFill.IsEmpty()) { return _T("");}

	int iLen = szItem.GetLength()+szValue.GetLength()+szFill.GetLength();
	if (iLen>=iTotalLen) { return _T(""); }

	int iFill=(iTotalLen-3*szItem.GetLength()/2-szValue.GetLength())/(szFill.GetLength());

	szOut += szItem;
	for (int i=0;i<iFill;i++) {szOut += szFill;}
	szOut += szValue;
	szOut += _T("\r\n");

	return szOut;
}

inline int D2Int(double dIn)
{
	int iOut = int(dIn);
	if (dIn>1e-7) iOut = int(dIn+0.5);
	if (dIn<-1e-7) iOut = int(dIn-0.5);

	return iOut;
}

inline char *strsep(char **stringp, const char *delim)
{
	char *s;
	const char *spanp;
	int c, sc;
	char *tok;
	if ((s = *stringp)== NULL)
		return (NULL);
	for (tok = s;;) {
		c = *s++;
		spanp = delim;
		do {
			if ((sc =*spanp++) == c) {
				if (c == 0)
					s = NULL;
				else
					s[-1] = 0;
				*stringp = s;
				return (tok);
			}
		} while (sc != 0);
	}
	/* NOTREACHED */
}

inline int JudgeDigit(double dTick)
{
	int iRes;
	if (dTick<0.01) {iRes=3;}
	else if (dTick<0.1)
	{iRes=2;}
	else if (dTick<1)
	{iRes=1;}
	else
	{iRes = 0;}
	
	return iRes;		
}

inline int outStrAs4(CString& szIn)
{
	CString szTemp = szIn;

	int iLen = szTemp.GetLength();
	int iDotPos = szTemp.ReverseFind('.');
	
	CString szDigEnd=_T("");
	if (iDotPos>0)
	{
		szDigEnd = szTemp.Mid(iDotPos+1,iLen-iDotPos-1);
		szTemp = szTemp.Mid(0,iDotPos);
	}
	szTemp.MakeReverse();

	int iLen2 = szTemp.GetLength();
	int iTimes = iLen2 /4;
	int iLeft = iLen2 %4;

	CString szOut =_T("");
	for (int i=0;i<iTimes;i++)
	{
		szOut += szTemp.Mid(i*4,4);
		if ((i!=(iTimes-1))||(iLeft!=1)||(*(szTemp.GetBuffer(0) + iLen2-1)!='-'))
		{
			szOut += ',';
		}
		
	}

	if (iLeft>0)
	{
		szOut += szTemp.Mid(iLen2-iLeft,iLeft);
	}
	else
	{
		szOut.TrimRight(',');
	}

	szOut.MakeReverse();
	szIn = szOut;

	if (!szDigEnd.IsEmpty())
	{
		szIn.Format(_T("%s.%s"),(LPCTSTR)szOut,(LPCTSTR)szDigEnd);
	}
	
	return 0;

}

inline CString JgProType(char bType)
{
	CString szTmp ;
	
	switch(bType)
	{
	case '1':
		szTmp = _T("期货");
		break;
	case '2':
		szTmp = _T("期权");
		break;
	case '3':
		szTmp = _T("组合");
		break;
	case '4':
		szTmp = _T("即期");
		break;
	case '5':
		szTmp = _T("期转现");
		break;
	default:
		szTmp=_T("未知");
		break;
	}
	return szTmp;
}

inline CString JgCardType(char bType)
{
	CString szTmp;
	
	switch(bType)
	{
	case THOST_FTDC_ICT_EID:
		szTmp = _T("组织机构代码");
		break;
	case THOST_FTDC_ICT_IDCard:
		szTmp = _T("身份证");
		break;
	case THOST_FTDC_ICT_OfficerIDCard:
		szTmp = _T("军官证");
		break;
	case THOST_FTDC_ICT_PoliceIDCard:
		szTmp = _T("警官证");
		break;
	case THOST_FTDC_ICT_SoldierIDCard:
		szTmp = _T("士兵证");
		break;
	case THOST_FTDC_ICT_HouseholdRegister:
		szTmp = _T("户口簿");
		break;
	case THOST_FTDC_ICT_Passport:
		szTmp = _T("护照");
		break;
	case THOST_FTDC_ICT_TaiwanCompatriotIDCard:
		szTmp = _T("台胞证");
		break;
	case THOST_FTDC_ICT_HomeComingCard:
		szTmp = _T("回乡证");
		break;
	case THOST_FTDC_ICT_LicenseNo:
		szTmp = _T("营业执照号");
		break;
	case THOST_FTDC_ICT_TaxNo:
		szTmp = _T("税务登记号");
		break;
	case THOST_FTDC_ICT_OtherCard:
		szTmp = _T("其他证件");
		break;
	}
	return szTmp;
}

inline CString JgTdType(char bType)
{
	CString szTmp;

	switch(bType)
	{
	case 0:
		szTmp = _T("普通成交");
		break;
	case 1:
		szTmp = _T("期权执行");
		break;
	case 2:
		szTmp = _T("OTC成交");
		break;
	case 3:
		szTmp = _T("期转现衍生成交");
		break;
	case 4:
		szTmp = _T("组合衍生成交");
		break;
	default:
		szTmp=_T("未知");
		break;
	}
	return szTmp;
}

inline CString JgOcType(char bType)
{
	CString szTmp = _T("未知");
	
	switch(bType)
	{
	case THOST_FTDC_OF_Open:
		szTmp = _T("开仓");
		break;
	case THOST_FTDC_OF_Close:
		szTmp = _T("平仓");
		break;
	case THOST_FTDC_OF_ForceClose:
		szTmp = _T("强平");
		break;
	case THOST_FTDC_OF_CloseToday:
		szTmp = _T("平今");
		break;
	case THOST_FTDC_OF_CloseYesterday:
		szTmp = _T("平昨");
		break;
	case THOST_FTDC_OF_ForceOff:
		szTmp=_T("强减");
		break;
	case THOST_FTDC_OF_LocalForceClose:
		szTmp=_T("本地强平");
		break;
	default:
		szTmp=_T("未知");
		break;
	}

	return szTmp;
}

inline CString JgOrdSubmitStat(char bType)
{
	CString szTmp = _T("未知");
	
	switch(bType)
	{
	case THOST_FTDC_OSS_InsertSubmitted:
		szTmp = _T("委托已提交");
		break;
	case THOST_FTDC_OSS_CancelSubmitted:
		szTmp = _T("撤单已提交");
		break;
	case THOST_FTDC_OSS_Accepted:
		szTmp = _T("已经接受");
		break;
	case THOST_FTDC_OSS_InsertRejected:
		szTmp = _T("报单已被拒");
		break;
	case THOST_FTDC_OSS_CancelRejected:
		szTmp = _T("撤单已被拒");
		break;
	case THOST_FTDC_OSS_ModifyRejected:
		szTmp=_T("改单已被拒");
		break;
	default:
		szTmp=_T("未知");
		break;
	}
	
	return szTmp;
}

inline CString JgOrdStatType(char bType)
{
	CString szTmp = _T("错误");
	
	switch(bType)
	{
	case THOST_FTDC_OST_AllTraded:
		szTmp = _T("全部成交");
		break;
	case THOST_FTDC_OST_PartTradedQueueing:
		szTmp = _T("部分成交还在队列中");
		break;
	case THOST_FTDC_OST_PartTradedNotQueueing:
		szTmp = _T("部分成交不在队列中");
		break;
	case THOST_FTDC_OST_NoTradeQueueing:
		szTmp = _T("未成交还在队列中");
		break;
	case THOST_FTDC_OST_NoTradeNotQueueing:
		szTmp = _T("未成交不在队列中");
		break;
	case THOST_FTDC_OST_Canceled:
		szTmp=_T("已撤单");
		break;
	case THOST_FTDC_OST_Unknown:
		szTmp=_T("未知");
		break;
	case THOST_FTDC_OST_NotTouched:
		szTmp=_T("尚未触发");
		break;
	case THOST_FTDC_OST_Touched:
		szTmp=_T("已触发");
		break;
	}
	
	return szTmp;
}

inline CString JgPosBsType(char bType)
{
	CString szTmp ;
	
	switch(bType)
	{
	case THOST_FTDC_PD_Net:
		szTmp = _T("净");
		break;
	case THOST_FTDC_PD_Long:
		szTmp = _T("多头");
		break;
	case THOST_FTDC_PD_Short:
		szTmp = _T("空头");
		break;
	default:
		szTmp=_T("未知");
		break;
	}
	return szTmp;
}

inline CString JgBsType(char bType)
{
	CString szTmp ;
	
	switch(bType)
	{
	case THOST_FTDC_D_Buy:
		szTmp = _T("买");
		break;
	case THOST_FTDC_D_Sell:
		szTmp = _T("卖");
		break;
	default:
		szTmp=_T("未知");
		break;
	}
	return szTmp;
}

inline CString JgTbType(char bType)
{
	CString szTmp ;
	
	switch(bType)
	{
	case THOST_FTDC_HF_Speculation:
		szTmp = _T("投机");
		break;
	case THOST_FTDC_HF_Arbitrage:
		szTmp = _T("套利");
		break;
	case THOST_FTDC_HF_Hedge:
		szTmp = _T("套保");
		break;
	default:
		szTmp=_T("未知");
		break;
	}
	return szTmp;
}

inline CString JgExchage(TThostFtdcExchangeIDType ExID)
{
	CString szTmp = _T("未知");
	if (!strcmp(ExID,"CZCE"))
	{
		szTmp = _CZCE;
	}
	if (!strcmp(ExID,"DCE"))
	{
		szTmp = _DCE;
	}
	if (!strcmp(ExID,"SHFE"))
	{
		szTmp = _SHFE;
	}
	if (!strcmp(ExID,"CFFEX"))
	{
		szTmp = _CFFEX;
	}

	return szTmp;
}

inline CString JgBfTdType(TThostFtdcTradeCodeType TdCode)
{
	CString szTmp = _T("未知");
	if (!strcmp(TdCode,"202001"))
	{
		szTmp = _T("银行资金转期货");
	}
	if (!strcmp(TdCode,"202002"))
	{
		szTmp = _T("期货资金转银行");
	}
	if (!strcmp(TdCode,"203001"))
	{
		szTmp = _T("冲正银行转期货");
	}
	if (!strcmp(TdCode,"203002"))
	{
		szTmp = _T("冲正期货转银行");
	}
	if (!strcmp(TdCode,"204002"))
	{
		szTmp = _T("查询银行余额");
	}
	if (!strcmp(TdCode,"204004"))
	{
		szTmp = _T("查询银期直通车");
	}
	if (!strcmp(TdCode,"204005"))
	{
		szTmp = _T("查询转账明细");
	}
	if (!strcmp(TdCode,"204006"))
	{
		szTmp = _T("查询银行状态");
	}
	if (!strcmp(TdCode,"204009"))
	{
		szTmp = _T("查询当日流水");
	}
	if (!strcmp(TdCode,"206001"))
	{
		szTmp = _T("入金通知");
	}
	if (!strcmp(TdCode,"206002"))
	{
		szTmp = _T("出金通知");
	}
	if (!strcmp(TdCode,"901001"))
	{
		szTmp = _T("开通银期直通车");
	}
	if (!strcmp(TdCode,"901002"))
	{
		szTmp = _T("解除银期直通车");
	}
	if (!strcmp(TdCode,"905001"))
	{
		szTmp = _T("期商签到");
	}
	if (!strcmp(TdCode,"905002"))
	{
		szTmp = _T("期商签退");
	}
	if (!strcmp(TdCode,"905003"))
	{
		szTmp = _T("同步密钥");
	}
	return szTmp;
}

inline CString JgBkName(BYTE bType)
{
	CString szIn =_T("");
	switch(bType)
	{
	case THOST_FTDC_BF_ABC:
		szIn = _T("农业银行");
		break;
	case THOST_FTDC_BF_BC:
		szIn = _T("中国银行");
		break;
	case THOST_FTDC_BF_BOC:
		szIn = _T("交通银行");
		break;
	case THOST_FTDC_BF_CBC:
		szIn = _T("建设银行");
		break;
	case THOST_FTDC_BF_ICBC:
		szIn = _T("工商银行");
		break;
	case THOST_FTDC_BF_Other:
		szIn = _T("其他银行");
		break;
	}	
	return szIn;
}

inline CString GetSpecFilePath(LPCTSTR lpsz)
{
	CString strPath = __targv[0]; 
	strPath = strPath.Left(strPath.ReverseFind('\\'));
	strPath += '\\';
	strPath += lpsz;
	return strPath;
}


inline CString LoadString(UINT nID)
{
	CString str;
	str.LoadString(nID);
	return str;
}

extern CWnd* g_pCWnd;
inline void ShowErroTips(UINT nID1, UINT nID2)
{
	CDelayMsgBox mbox(g_pCWnd);
	mbox.MessageBox(LoadString(nID1),LoadString(nID2),1,true,MB_ICONINFORMATION);
}

inline void ShowErroTips(LPCTSTR lpMsg, LPCTSTR lpTitle)
{
	CDelayMsgBox mbox(g_pCWnd);
	mbox.MessageBox(lpMsg,lpTitle,1,true,MB_ICONINFORMATION);
}

inline int res2file(LPCTSTR lpName,LPCTSTR lpType,LPCTSTR filename)
{
	HRSRC myres = FindResource (NULL,lpName,lpType);
	HGLOBAL gl = LoadResource (NULL,myres);
	LPVOID lp = LockResource(gl);
	HANDLE fp = CreateFile(filename ,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,0,NULL);
	if (!fp)
		return false;
	
	DWORD a;
	if (!WriteFile (fp,lp,SizeofResource (NULL,myres),&a,NULL))
		return false;
	
	CloseHandle (fp);
	FreeResource (gl);
	return true;
	
}

inline int uni2ansi(UINT uCodepage,WCHAR *unicodestr, char *ansistr )
{
    int result = 0;
    try
    {
        int needlen = WideCharToMultiByte( uCodepage, 0, unicodestr, -1, NULL, 0, NULL, NULL );
        if( needlen < 0 )
        {
            return needlen;
        }
		
        result = WideCharToMultiByte( uCodepage, 0, unicodestr, -1, ansistr, needlen + 1, NULL, NULL );
        if( result < 0 )
        {
            return result;
        }
        return strlen( ansistr );
    }
    catch( ... )
    {
        ShowErroTips(_T("unicode2ansi ERROR!"),MY_TIPS);
    }
    return result;
}

inline int ansi2uni(UINT uCodepage, char *ansistr,WCHAR *unicodestr)
{
	int result = 0;
	try
	{
		int needlen = MultiByteToWideChar( uCodepage, 0, ansistr, -1, NULL, 0);
		if( needlen < 0 )
		{
			return needlen;
		}
		
		result = MultiByteToWideChar( uCodepage, 0, ansistr, -1, unicodestr, needlen + 1);
		if( result < 0 )
		{
			return result;
		}
		return wcslen( unicodestr );
	}
	catch( ... )
	{
		ShowErroTips(_T("ansi2unicode ERROR!"),MY_TIPS);
	}
	return result;
}


inline void List2Csv(CXListCtrl* pList,LPCTSTR lpName)
{
	CMemFile mmf;
	BYTE bBom[3]={0xEF,0xBB,0xBF};
	BYTE bDot = ',';
	BYTE bEnter = '\n';
	mmf.Write(&bBom,3);
	
	int nItem = pList->GetItemCount();
	int nColumns = pList->GetXHeaderCtrl()->GetItemCount();
	HDITEM hd;
	TCHAR pItem[MAX_PATH];
	char utf8[3*MAX_PATH];
	CString str;
	int nCol = 0; 
	for (nCol = 0; nCol < nColumns; nCol++)
	{
		memset(pItem,0,_tcslen(pItem));
		hd.pszText=pItem;
		hd.cchTextMax=MAX_PATH;
		hd.mask = HDI_TEXT;
		pList->GetHeaderItem(nCol, &hd);
		
		str.Format(_T("\"%s\""),pItem);
		uni2ansi(CP_UTF8,pItem,utf8);
		mmf.Write(utf8,strlen(utf8));
		if (nCol < nColumns-1)
		{
			mmf.Write(&bDot,1);
		}
		if (nCol == nColumns-1)
		{
			mmf.Write(&bEnter,1);
		}	
	}
	
	CString str2;
	for (int nRow = 0; nRow < nItem; nRow++)
	{
		for (nCol = 0; nCol < nColumns; nCol++)
		{
			str2 = pList->GetItemText(nRow,nCol);
			str.Format(_T("\"%s\""),(LPCTSTR)str2);
			uni2ansi(CP_UTF8,str.GetBuffer(MAX_PATH),utf8);
			str.ReleaseBuffer();

			mmf.Write(utf8,strlen(utf8));
			if (nCol < nColumns-1)
			{
				mmf.Write(&bDot,1);
			}
			if (nCol == nColumns-1)
			{
				mmf.Write(&bEnter,1);
			}
		}
	}
	
	CFile fLog(lpName, CFile::modeReadWrite | CFile::modeCreate | CFile::typeText);
	
	DWORD dwLen = mmf.GetLength();
	PBYTE pMemF = mmf.Detach();
	fLog.Write(pMemF,dwLen);
	fLog.Close();
	mmf.Close();
}

inline CString GenDef(LPCTSTR lpPre,LPCTSTR lpExt)
{
	CString szDef,szT;
	SYSTEMTIME tm;
	
	::GetLocalTime(&tm);
	szT.Format(_T("%s_%04d%02d%02d%02d%02d%02d"), lpPre,tm.wYear,tm.wMonth,tm.wDay,tm.wHour, tm.wMinute, tm.wSecond);

	szDef.Format(_T("%s.%s"),(LPCTSTR)szT,lpExt);
	return szDef;
}

inline CString TransTime(TThostFtdcTradeTimeType TdTm)
{
	CString szTm=_T("");
	ansi2uni(CP_ACP,TdTm,szTm.GetBuffer(MAX_PATH));
	szTm.ReleaseBuffer();
	
	return szTm;
}

inline BOOL GenXmlHdr(LPCTSTR lpFile)
{
	if (!PathFileExists(GetSpecFilePath(lpFile)))
	{
		CFile fLog(GetSpecFilePath(lpFile), CFile::modeReadWrite | CFile::modeCreate | CFile::typeText);
		
		LPCSTR szHdr ="<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
		BYTE bBom[3]={0xEF,0xBB,0xBF};
		fLog.Write(&bBom,3);
		
		fLog.Write(szHdr, strlen(szHdr));
		fLog.Close();
		
		return TRUE;
	}
	return FALSE;
}

template<class T> inline void  ClearVector(vector<T*> &v)
{
	int  i;
	int  n = (int)v.size();
	for( i = 0; i < n; i++ )
	{
		T* p = v[i];
		DEL( p );
	}
	v.clear();
}

inline char MapDirection(char src, bool toOrig=true)
{
	if(toOrig)
	{
		if('b'==src||'B'==src)
		{src='0';}
		else if('s'==src||'S'==src)
		{src='1';}
	}
	else
	{
		if('0'==src){src='B';}else if('1'==src){src='S';}
	}
	return src;
}

inline char MapOffset(char src, bool toOrig=true)
{
	if(toOrig)
	{
		if('o'==src||'O'==src){src='0';}
		else if('c'==src||'C'==src){src='1';}
		else if('j'==src||'J'==src) {src='3';}
	}
	else
	{
		if('0'==src){src='O';}
		else if('1'==src){src='C';}
		else if('3'==src){src='J';}
	}
	return src;
}
