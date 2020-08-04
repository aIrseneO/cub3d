#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	c;

	if (!(str))
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	j = len - 1;
	while (str[i])
	{
		if (
