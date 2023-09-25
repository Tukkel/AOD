template<class T>
Set<T>::Set()
{
	set_ = new List<T>();
	elements_ = 0;
}

template<class T>
Set<T>::~Set()
{
	set_->~List<T>();
}

template<class T>
bool Set<T>::insert(T x)
{
	if (contains(x))
	{
		return false;
	}
	set_->push_back(x);
	elements_++;
	return true;
}

template<class T>
bool Set<T>::contains(T x) const
{
	for (size_t i = 0; i < elements_; i++)
	{
		if (x == set_->find_kth(i))
		{
			return true;
		}
	}
	return false;
}

template<class T>
bool Set<T>::remove(T x)
{
	size_t pos = elements_;
	for (size_t i = 0; i < elements_; i++)
	{
		if (x == set_->find_kth(i))
		{
			pos = i;
			break;
		}
	}
	if (pos == elements_)
	{
		return false;
	}
	else
	{
		List<T> temp;
		for (size_t i = 0; i < pos; i++)
		{
			temp.push_front(set_->pop_front());
		}
		set_->pop_front();
		for (size_t i = 0; i < pos; i++)
		{
			set_->push_front(temp.pop_front());
		}
		elements_--;
		return true;
	}
}