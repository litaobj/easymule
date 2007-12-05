// ***************************************************************
//  FtpClient   version:  1.0   ��  date: 08/09/2007
//  -------------------------------------------------------------
//  
//  -------------------------------------------------------------
//  Copyright (C) 2007 - All Rights Reserved
// ***************************************************************
// Ftp Peer ����,��ParFile��ȡ������������,�������غ�����ݽ���PartFile
// Ftp Peer ��Ҫ��������Socketͨ��( ����Socket������Socket)
//                                         vc-huby
// ***************************************************************

#pragma once
#include "updownclient.h"

#include "SourceURL.h"
#include "FTPClientReqSocket.h"


class CFtpClient : public CUpDownClient
{
	DECLARE_DYNAMIC(CFtpClient)
public:
	CFtpClient(void);
	virtual ~CFtpClient(void);

	bool SetUrl(LPCTSTR pszUrl, uint32 nIP = 0);

	virtual void SetRequestFile(CPartFile* pReqFile);	
	virtual bool IsEd2kClient() const 
	{ 
		return false; 
	}

	virtual bool TryToConnect(bool bIgnoreMaxCon = false, CRuntimeClass* pClassSocket = NULL);
	virtual bool Connect();
	
	virtual void OnSocketConnected(int nErrorCode);
	virtual void ConnectionEstablished();
	virtual bool Disconnected(LPCTSTR pszReason, bool bFromSocket = false,CClientReqSocket* pSocket=NULL);

	virtual void Pause( );
	virtual uint32  GetTimeUntilReask() const; ///< http/ftp Peer���û������,����10s����ѯ��һ��.

	bool		 OnFileSizeKnown( uint64 uiFileSize );
	void		 OnCmdSocketErr(CStringA strError);
	virtual void ProcessRawData(const BYTE * pucData, UINT uSize);

	virtual bool SendHelloPacket();
	virtual bool SendFtpBlockRequests();
	virtual void SendCancelTransfer(Packet* packet);
	virtual void CheckDownloadTimeout();
	
	CFtpClientDataSocket* GetClientDataSocket( bool bCreateIfNull=true );
	CFtpClientReqSocket*  GetClientReqSocket( );

	virtual void	CreateBlockRequests(int iMaxBlocks);
	bool		 GetUrlStartPosForReq(  uint64& uiUrlStartPos ); //< �����ftp peerӦ�ô����ݵ��ĸ�λ�ÿ�ʼ������

	CSourceURL			m_SourceURL;  
	uint64				m_uiFileSize;		 //< ��INet peer��Զ���ļ���С,��PartFileSize��С��һ�µ�ʱ�򲻲�������	

	void				CloseDataSocket();
	int					PendingBlockReqCount(){ return m_PendingBlocks_list.GetCount();}
private:
	
	CFtpClientDataSocket *	m_pFtpDataSocket; //< ��PASV����ɹ���Żᴴ������ͨ�����ļ�����
public:
	CStringA lastError;
	int m_ErrorCount;
	CString m_strUrl;
	uint32  m_nIP ;
    bool bAddOtherSources;
};
