#pragma once

#include "ClientReqSocket.h"

enum E_FTP_STATES 
{
	ftpNone,
	ftpConnecting,              // Initial state
	ftpUSER, ftpPASS,           // Authenticating
	ftpSIZE_TYPE, ftpSIZE,      // File size getting via SIZE: TYPE I -> SIZE
	ftpLIST_TYPE, ftpLIST_PASVPORT, ftpLIST, // File size getting via LIST: TYPE A -> PASV or PORT -> LIST
	ftpDownloading,             // Intermediate state
	ftpRETR_TYPE, ftpRETR_PASVPORT, ftpRETR_REST, ftpRETR, // Downloading: TYPE I -> PASV or PORT -> REST -> RETR
	ftpABOR,                     // Aborting after each transfer (for some strange FTP servers)
	ftpClose
};

/// ����Ftp����ͨ��Э���Socket
class CFtpClientReqSocket : public CClientReqSocket
{
	DECLARE_DYNCREATE(CFtpClientReqSocket)

public:

	CFtpClientReqSocket(CUpDownClient* client = NULL);
	~CFtpClientReqSocket(void);

	virtual CUpDownClient* GetClient() const 
	{ 
		return client; 
	}
	
	virtual bool IsRawDataMode() const 
	{ 
		return true; 
	}	
		
	virtual BOOL Connect(SOCKADDR* pSockAddr, int iSockAddrLen);
	BOOL SendCommand( ); //< ����FTP CMD

	void SetFtpState( E_FTP_STATES ftpState ){ m_FtpState=ftpState; }
	virtual void	SetDownloadLimit(uint32 limit); //<ftp ������Ӧ�����⴦��,�޵�Ӧ��������ͨ��,����������ͨ��..
	virtual UINT	GetTimeOut();
protected:
	virtual void DataReceived(const BYTE* pucData, UINT uSize);
	virtual void OnConnect(int nErrorCode);
	virtual void OnClose(int nErrorCode);
    
private:	
	BOOL			OnHeaderLine ( CStringA& strHeader, CStringA& strValue ); //< Header����,һ������'\r\n'��β,��Ӧÿһ�����͵�����
public:
	E_FTP_STATES	m_FtpState; //< FTP����ͨ��״̬..
private:
	BOOL			m_bPassive; //< ��������,��ò���PASVģʽ,���������û�
	BOOL			m_bDecLaunchTimes; //< ���ڿͻ��˴���(���ӹ�������..)
	BOOL			m_bServerErr; //< ftp server �˴���
};

/// ����Ftp����ͨ��Э���Socket
class CFtpClientDataSocket : public CClientReqSocket
{
	DECLARE_DYNCREATE(CFtpClientDataSocket)

public:
	CFtpClientDataSocket(CUpDownClient* in_client = NULL);
	~CFtpClientDataSocket(void);

	virtual CUpDownClient* GetClient() const 
	{ 
		return client; 
	}
	virtual bool IsRawDataMode() const 
	{ 
		return true; 
	}
protected:
	virtual void DataReceived(const BYTE* pucData, UINT uSize);
	virtual void OnConnect(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};
