#include "StdAfx.h"
#include ".\metalinkexecutor.h"

#include "PartFile.h"
#include "MetaLinkParser.h"

CMetalinkExecutor::CMetalinkExecutor(void)
{
}

CMetalinkExecutor::~CMetalinkExecutor(void)
{
}

bool CMetalinkExecutor::execute( CPartFile * partFile )
{
	// 
	const CString & filepath = partFile->GetFilePath();
	
	if( -1 == filepath.Find( _T(".metalink") ) ) {
		// ���� .metalink �ļ�������
		return false;
	}

	CMetaLinkParser parser( filepath );
	if( parser.GetErrorCode() != METALINK_OK ) {
		// ���ǺϷ��� meta link �ļ�
		return false;
	}

	bool ret = partFile->ChangedToMetalinkFile( &parser );

	// 
	if( !ret ) {
		return false;
	}

	// ���д���

	return true;
}
