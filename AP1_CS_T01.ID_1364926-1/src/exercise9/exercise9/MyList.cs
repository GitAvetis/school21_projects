namespace exercise9
{
    public class MyList<T>
    {
        private T[] _items;
        private int _size;
        private int _version;

        public MyList()
        {
            _items = new T[2];
            _size = 0;
            _version = 0;

        }

        public void Add(T item)
        {
            if (_size == _items.Length)
            {
                Array.Resize(ref _items, _items.Length * 2);
            }
            _items[_size++] = item;
            _version++;
        }

        public int Count
        {
            get { return _size; }
        }

        public void Remove(T item)
        {
            int index = -1;
            for (int i = 0; i < _size; i++)
            {
                if (EqualityComparer<T>.Default.Equals(_items[i], item))
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
                return;

            for (int i = index; i < _size - 1; i++)
            {
                _items[i] = _items[i + 1];
            }
            _items[--_size] = default(T);
            _version++;
        }

        public T this[int index]
        {
            get
            {
                // Following trick can reduce the range check by one
                if ((uint)index >= (uint)_size)
                {
                    throw new ArgumentOutOfRangeException(nameof(index));
                }
                return _items[index];
            }

            set
            {
                if ((uint)index >= (uint)_size)
                {
                    throw new ArgumentOutOfRangeException(nameof(index));
                }
                _items[index] = value;
                _version++;
            }
        }
    }
}
