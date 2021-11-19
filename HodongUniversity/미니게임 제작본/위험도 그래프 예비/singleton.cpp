#include <stddef.h>
#include "singleton.h"

//�̰Ŵ� �ٲ��� ���� �ٷ� src�� �ֱ⸸ �ϼ�
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