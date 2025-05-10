template <typename Container,
		typename ContainerJacobsthal>
void	insertElements(Container& mainChain, Container& pend,
		ContainerJacobsthal& insertPos)
{
	size_t	len = insertPos.size();

	for (size_t i = 0; i < len ; i++)
	{
		size_t posElementToInsert = std::lower_bound(mainChain.begin(),
			mainChain.end(), pend[insertPos[i] - 1]) - mainChain.begin();
		mainChain.insert(mainChain.begin() + posElementToInsert, pend[insertPos[i] - 1]);
	}
}

template <typename Container,
		 typename OutputContainer>
OutputContainer	createMainPend(Container& container, Container& main,
				Container& pend)
{
	OutputContainer	pairC;
	size_t	len = container.size();

	if (len % 2 != 0)
		len -= 1;
	for (size_t i = 0; i < len - 1; i += 2)
	{
		int	a = container[i];
		int	b = container[i + 1];

		if (a > b)
			std::swap(a, b);
		std::pair<int, int>	pairInt(a, b);
		pairC.push_back(pairInt);
		main.push_back(b);
		pend.push_back(a);
	}
	return (pairC);
}
