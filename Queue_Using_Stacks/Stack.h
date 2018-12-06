#pragma once



class CStack
{
public:
	struct CNode {
		int		iData;
		CNode*	pNext;
	};

private:
	CNode*	m_pRoot;
protected:
public:
	CStack();
	virtual ~CStack();

	bool Push(int _iData);
	bool Pop(int* _pData);
};

CStack::CStack() :
	m_pRoot(nullptr)
{

}

CStack::~CStack()
{
	int iTemp;
	// delete all nodes
	while (Pop(&iTemp)) {
		// delete node
		printf("\nLeft in Stack - %d", iTemp);
	}
}

bool CStack::Push(int _iData)
{
	CNode* pNode = new CNode();
	if (!pNode)
		return false;
	pNode->iData = _iData;
	pNode->pNext = m_pRoot;
	m_pRoot = pNode;
	return true;
}

bool CStack::Pop(int* _pData)
{
	if (m_pRoot == nullptr)
		return false;
	(*_pData) = m_pRoot->iData;
	CNode* pTemp = nullptr;
	pTemp = m_pRoot;
	m_pRoot = m_pRoot->pNext;
	delete(pTemp);
	return true;
}


class CQueue
{
private:
	CStack* m_pStack1;
	CStack* m_pStack2;

protected:
public:
	CQueue();
	virtual ~CQueue();

	bool EnQueue(int _iVal);
	bool DeQueue(int* _pRetVal);
};

CQueue::CQueue() :
	m_pStack1(nullptr),
	m_pStack2(nullptr)
{
	m_pStack1 = new CStack();
	m_pStack2 = new CStack();
}

CQueue::~CQueue()
{
	if (m_pStack1) {
		delete m_pStack1;
	}
	if (m_pStack2) {
		delete m_pStack2;
	}
}

bool CQueue::EnQueue(int _iVal)
{
	return m_pStack1->Push(_iVal);
}

bool CQueue::DeQueue(int* _piVal)
{
	int iTemp;
	while (m_pStack1->Pop(&iTemp)) {
		m_pStack2->Push(iTemp);
	}
	
	if (!m_pStack2->Pop(_piVal))
		return false;

	while (m_pStack2->Pop(&iTemp)) {
		m_pStack1->Push(iTemp);
	}

	return true;
}