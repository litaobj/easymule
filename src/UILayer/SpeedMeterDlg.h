#pragma once
#include "SpeedMeter.h"

// CSpeedMeterDlg �Ի���

class CSpeedMeterDlg : public CDialog
{
	DECLARE_DYNAMIC(CSpeedMeterDlg)

public:
	CSpeedMeterDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSpeedMeterDlg();

// �Ի�������
	enum { IDD = IDD_MAINTAB_SPEEDMETER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	CSpeedMeter	m_CtrlSpeedMeter;
public:
	int GetDesireWidth();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	LRESULT	OnEraseBkgndEx(WPARAM wParam, LPARAM lParam);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
