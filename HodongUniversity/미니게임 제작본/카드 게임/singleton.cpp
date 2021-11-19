#include <stddef.h>
#include "singleton.h"

//이거는 바꾸지 말고 바로 src에 넣기만 하셈
Singletons* Singletons::m_pInstance = NULL;

Singletons* Singletons::getInstance() {

	if (!m_pInstance)
	{
		m_pInstance = new Singletons;
	}

	return m_pInstance;
}
void Singletons::releaseInstance()
{
	if (m_pInstance) delete m_pInstance;
}