template <typename Container>
Container	generateInsertPosition(size_t size)
{
	size_t	n = 1;
	Container	positions;

	if (size == 0)
		return (positions);
	while (1)
	{
		size_t	actual = (pow(2, n) - pow(-1, n)) / 3;
		size_t	prev = (pow(2, n - 1) - pow(-1, n - 1)) / 3;
		if (actual > size)
			break;
		size_t	nbElement = actual - prev;
		for (size_t j = 0; j < nbElement; j++)
		{
			if (actual <= size)
				positions.push_back(actual);
			actual--;
		}
		n++;
	}
	for (size_t i = size; i > (pow(2, n - 1) - pow(-1, n - 1)) / 3; i--)
	{
		positions.push_back(i);
	}
	return positions;
}
