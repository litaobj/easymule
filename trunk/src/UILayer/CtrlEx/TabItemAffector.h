#pragma once



// CTabItemAffector ����Ŀ��
class CTabItem;

class CTabItemAffector
{
public:
	CTabItemAffector();
	virtual ~CTabItemAffector();

	void	SetAssocItem(CTabItem *pAssocItem);
	
	void	SetItemCaption(LPCTSTR lpszCaption);
protected:
	friend class CTabItem;
	CTabItem	*m_pAssocItem;
};


