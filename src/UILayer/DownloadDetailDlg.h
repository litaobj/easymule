#pragma once


// CDownloadDetailDlg �Ի���

class CDownloadDetailDlg : public CDialog
{
	DECLARE_DYNAMIC(CDownloadDetailDlg)

public:
	CDownloadDetailDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDownloadDetailDlg();

	void SetPartFileInfo(CKnownFile	*file);
// �Ի�������
	enum { IDD = IDD_DOWNLOAD_DETAIL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
