#pragma once


// CCloseModeDlg �Ի���

class CCloseModeDlg : public CDialog
{
	DECLARE_DYNAMIC(CCloseModeDlg)

public:
	CCloseModeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCloseModeDlg();

// �Ի�������
	enum { IDD = IDD_CLOSE_MODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	int		m_iCloseMode;
	static bool m_bAskingClose;
	virtual BOOL OnInitDialog();
protected:
	virtual void OnOK();
};
