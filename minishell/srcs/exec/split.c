#include "../../mini.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		c;
	int		h;
	char	*s3;

	h = 0;
	c = ft_strlen(s2);
	j = ft_strlen(s1);
	s3 = (char *)malloc(sizeof(char) *(j + c + 1));
	i = 0;
	while (i < j)
	{
	s3[i] = s1[i];
	i++;
	}
	while (s2[h] != '\0')
	{
	s3[i] = s2[h];
	i++;
	h++;
	}
	s3[i] = '\0';
	return (&*s3);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*hay;
	int		finds;

	i = 0;
	finds = 0;
	hay = (char *)haystack;
	n_len = ft_strlen(needle);
	if (n_len == 0 || haystack == needle)
		return (*needle);
	while (hay[i] != '\0' && i < len)
	{
		c = 0;
		while (hay[i + c] != '\0' && needle[c] != '\0'
			&& hay[i + c] == needle[c] && i + c < len)
			c++;
		if (c == n_len)
			finds++;
		i++;
	}
	if (finds > 0)
		return (*needle);
	return (0);
}