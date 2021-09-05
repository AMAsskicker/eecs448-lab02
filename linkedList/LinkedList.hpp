/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{

	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	//get front of list pointer
	Node<T>* temp = m_front;
    //return this at end of operations
	bool isFound = false;
    //itterate through list, if found goto end of func
    while (temp != nullptr) {
        if (temp->getValue() == value) {
            isFound = true;
            goto END_FUNC;
        } else {
            temp = temp->getNext();
        }
    }
    END_FUNC:
	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	//temp node
    Node<T> *temp_node = m_front;
    //ptr to last node
	Node<T>* lastNode = nullptr;
	Node<T>* secondToLast = nullptr;
    // return boolean
	bool isRemoved = false;
    //empty list case
    if (isEmpty()) {
        isRemoved = false;
    } else {
        int temp_size = size();
        //goto end of list and pickup ptrs
        for (int i=0; i<temp_size; i++) {
            temp_node = temp_node->getNext();
            if (i == temp_size-3) {
                secondToLast = temp_node;
            } else if (i == temp_size-2) {
                lastNode = temp_node;
            }
        }
        //set secnod to last next to null
        secondToLast->setNext(nullptr);
        //delete last
        delete lastNode;
        //decrement size
        m_size--;
        //set output
        isRemoved = true;
    }

	return(isRemoved);
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
